#include "time.h"
#include <pb_decode.h>
#include "nyct-subway.pb.h"
#include "mtainfo.h"
#include <Fonts/Picopixel.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

String QueryEndpoint(const char* url) {
  g_Wifi->setCACert(MTA_CERT);

  //create an HTTPClient instance
  HTTPClient https;

  //Initializing an HTTPS communication using the secure client
  Serial.print("[HTTPS] begin...\n");
  if (https.begin(*g_Wifi, url)) {  // HTTPS
    Serial.print("[HTTPS] GET...\n");
    // start connection and send HTTP header
    int httpCode = https.GET();
    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        // print server response payload
        String payload = https.getString();
        return payload;
      }
    }
    else {
      Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
    }
    https.end();
  }

  return {};
}


bool DecodeSTU(pb_istream_t* stream, const pb_field_t *, void** arg)
{
  transit_realtime_TripUpdate_StopTimeUpdate stu = transit_realtime_TripUpdate_StopTimeUpdate_init_zero;
  if (!pb_decode(stream, transit_realtime_TripUpdate_StopTimeUpdate_fields, &stu))
  {
    return false;
  }

  int64_t* arrivalTime = (int64_t*)*arg;
  if (strcmp(stu.stop_id, g_StationInfo.id) == 0)
  {
    Serial.printf("Stop ID: %s\nTimestamp: %llu\n", stu.stop_id, stu.arrival.time);
    // Skip already departed trains
    if (stu.arrival.time - time(nullptr) > 0)
    {
      *arrivalTime = stu.arrival.time;
    }
  }

  return true;
}

bool DecodeFeedEntity(pb_istream_t* stream, const pb_field_t *, void**)
{
  // Early out if we've already hit max lines
  if (g_StationInfo.trains.size() >= MAX_TRAINS)
  {
    return true;
  }

  transit_realtime_FeedEntity entity = transit_realtime_FeedEntity_init_zero;
  int64_t arrivalTime = 0;
  entity.trip_update.stop_time_update.funcs.decode = &DecodeSTU;
  entity.trip_update.stop_time_update.arg = &arrivalTime;

  if (!pb_decode(stream, transit_realtime_FeedEntity_fields, &entity))
  {
    return false;
  }

  if (!entity.has_trip_update || arrivalTime == 0)
  {
    // Early out if there's nothing relevant happening here
    return true;
  }

  // Otherwise, get the route associated with the trip object
  Train train {
    .line = Util::GetLineFromName(entity.trip_update.trip.route_id),
    .arrivalTime = arrivalTime,
  };
  g_StationInfo.trains.push_back(train);

  return true;
}

time_t lastUpdate = 0;

void UpdateStationData() {
  if (lastUpdate != 0 && time(nullptr) - lastUpdate < QUERY_INTERVAL_SEC)
  {
    return;
  }

  g_StationInfo.trains.clear();
  String response = QueryEndpoint(SERVER_URL);

  pb_istream_t istream = pb_istream_from_buffer(reinterpret_cast<const pb_byte_t*>(response.c_str()), static_cast<size_t>(response.length()));

  transit_realtime_FeedMessage feedMessage = transit_realtime_FeedMessage_init_zero;
  feedMessage.entity.funcs.decode = &DecodeFeedEntity;

  pb_decode(&istream, &transit_realtime_FeedMessage_msg, &feedMessage);

  std::sort(g_StationInfo.trains.begin(), g_StationInfo.trains.end(), [](const Train& a, const Train& b)
  {
    return a.arrivalTime < b.arrivalTime;
  });

  lastUpdate = time(nullptr);
}

void DrawLine(int16_t x, int16_t y, int16_t radius, Line line) {
  g_Display->fillCircle(x, y, radius, Util::GetLineColor(line));
  g_Display->setCursor(x-1, y+2);
  if (line == Line::N || line == Line::Q || line == Line::R || line == Line::W)
  {
    g_Display->setTextColor(COLOR_BLACK);
  } else
  {
    g_Display->setTextColor(COLOR_WHITE);
  }
  g_Display->printf("%s", Util::GetLineName(line));
  // Reset the color back to white
  g_Display->setTextColor(COLOR_WHITE);
}


void DrawStationData() {
  g_Display->clearScreen();
  int16_t start = 12;
  Line l = Line::Invalid;
  for (int16_t i = 0; i < g_StationInfo.trains.size(); i++) {
    const Train& train = g_StationInfo.trains[i];
    if (train.line == Line::Invalid)
    {
      break;
    }
    l = train.line;
    int y = start + (8 * i);
    DrawLine(5, y, 3, l);
    g_Display->setCursor(10, y+2);
    time_t current = time(nullptr);
    const long long difference_seconds = (train.arrivalTime - current);
    char diff_fmt[50];
    int mins = (int) (difference_seconds / 60);
    auto t = localtime((const time_t*)&train.arrivalTime);
    sprintf(diff_fmt, "%d mins", mins);
    g_Display->printf("%s (%02d:%02d)", diff_fmt, t->tm_hour, t->tm_min);
  }

  // Draw the station name and direction based on one of the lines above
  g_Display->setCursor(2, 6);
  // Ellipsize long station names to avoid squishing on the display
  String shortName = Util::EllipsizeName(STATION_NAME, 12);
  g_Display->printf("%s - %s", shortName.c_str(), Util::ParseDirectionWithLine(STATION_DIRECTION, l));
}

void setup() {
  Serial.begin(112500);
  
  HUB75_I2S_CFG mxconfig(
    PANEL_RES_X, // Module width
    PANEL_RES_Y, // Module height
    PANEL_CHAIN, // // chain length
    pins // pin mapping
  );
  //mxconfig.clkphase = false;
  //mxconfig.driver = HUB75_I2S_CFG::FM6126A;


  // GFX setup
  g_Display = new MatrixPanel_I2S_DMA(mxconfig);
  g_Display->begin();
  g_Display->clearScreen();
  g_Display->setFont(&Picopixel);
  g_Display->setTextSize(1);

  
  // Connect to wifi first
  Serial.print("Connecting to WiFi: ");
  g_Display->println("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  // Setup time
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);

  g_Display->clearScreen();
  g_Display->println(".....");
  Serial.println("\nWaiting for time");
  while (!time(nullptr))
  {
    Serial.print(".");
    delay(1000);
  }

  // Network client 
  Serial.println("Connecting to server");
  g_Wifi = new WiFiClientSecure();

  // Set up the station ID for the protobuffer
  sprintf(g_StationInfo.id, "%s%c", STATION_ID, STATION_DIRECTION == Direction::N ? 'N' : 'S');
}

void loop() {
  UpdateStationData();
  DrawStationData();
  delay(UPDATE_INTERVAL_MS);
}
