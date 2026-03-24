#include "nyct-subway.h"
#include "mtainfo.h"
#include <Fonts/Picopixel.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

#include "ReadBufferFixedSize.h"

const char* SERVER_URL = "https://api-endpoint.mta.info/Dataservice/mtagtfsfeeds/nyct%2Fgtfs-jz";
constexpr int SERVER_PORT = 443;
constexpr int DEFAULT_TIMEOUT = 15000;
constexpr int REFRESH_INTERVAL_MS = 30000;


const char* SSID = "Kings";
const char* password = "thepactbindsthem";

const char* STATION_ID = "631"; // Gates Ave J
Direction STATION_DIRECTION = Direction::S;

#define WIFI_WRITE(format, ...)                 \
wifi_client->printf(format, ##__VA_ARGS__); \
Serial.printf(format, ##__VA_ARGS__);

WiFiClientSecure* wifi_client = nullptr;
MatrixPanel_I2S_DMA *dma_display = nullptr;
StationInfo* station_info = nullptr;

uint16_t getLineColor(Line line)
{
  switch (line)
  {
  case Line::One:
  case Line::Two:
  case Line::Three:
    return COLOR_RED;
  case Line::Four:
  case Line::Five:
  case Line::Six:
    return COLOR_DARKGREEN;
  case Line::Seven:
    return COLOR_PURPLE;
  case Line::S:
  case Line::L:
    return COLOR_GRAY;
  case Line::N:
  case Line::R:
  case Line::Q:
  case Line::W:
    return COLOR_YELLOW;
  case Line::B:
  case Line::D:
  case Line::F:
  case Line::M:
    return COLOR_ORANGE;
  case Line::A:
  case Line::C:
  case Line::E:
    return COLOR_BLUE;
  case Line::J:
  case Line::Z:
    return COLOR_BROWN;
  case Line::G:
    return COLOR_LIGHTGREEN;
  case Line::Invalid:
    break;
  }
  return COLOR_GRAY;
}

inline const char* getLineName(Line line)
{
  switch (line)
  {
  case Line::One:
    return "1";
  case Line::Two:
    return "2";
  case Line::Three:
    return "3";
  case Line::Four:
    return "4";
  case Line::Five:
    return "5";
  case Line::Six:
    return "6";
  case Line::Seven:
    return "7";
  case Line::S:
    return "S";
  case Line::L:
    return "L";
  case Line::N:
    return "N";
  case Line::R:
    return "R";
  case Line::Q:
    return "Q";
  case Line::W:
    return "W";
  case Line::B:
    return "B";
  case Line::D:
    return "D";
  case Line::F:
    return "F";
  case Line::M:
    return "M";
  case Line::A:
    return "A";
  case Line::C:
    return "C";
  case Line::E:
    return "E";
  case Line::J:
    return "J";
  case Line::Z:
    return "Z";
  case Line::G:
    return "G";
  case Line::Invalid:
    break;
  }
  return "?";
}

inline Line getLineFromName(const char* name)
{
  if (strcmp(name, "1") == 0)
  {
    return Line::One;
  }
  if (strcmp(name, "2") == 0)
  {
    return Line::Two;
  }
  if (strcmp(name, "3") == 0)
  {
    return Line::Three;
  }
  if (strcmp(name, "4") == 0)
  {
    return Line::Four;
  }
  if (strcmp(name, "5") == 0)
  {
    return Line::Five;
  }
  if (strcmp(name, "6") == 0)
  {
    return Line::Six;
  }
  if (strcmp(name, "7") == 0)
  {
    return Line::Seven;
  }
  if (strcmp(name, "S") == 0)
  {
    return Line::S;
  }
  if (strcmp(name, "L") == 0)
  {
    return Line::L;
  }
  if (strcmp(name, "N") == 0)
  {
    return Line::N;
  }
  if (strcmp(name, "R") == 0)
  {
    return Line::R;
  }
  if (strcmp(name, "Q") == 0)
  {
    return Line::Q;
  }
  if (strcmp(name, "W") == 0)
  {
    return Line::W;
  }
  if (strcmp(name, "B") == 0)
  {
    return Line::B;
  }
  if (strcmp(name, "D") == 0)
  {
    return Line::D;
  }
  if (strcmp(name, "F") == 0)
  {
    return Line::F;
  }
  if (strcmp(name, "M") == 0)
  {
    return Line::M;
  }
  if (strcmp(name, "A") == 0)
  {
    return Line::A;
  }
  if (strcmp(name, "C") == 0)
  {
    return Line::C;
  }
  if (strcmp(name, "E") == 0)
  {
    return Line::E;
  }
  if (strcmp(name, "J") == 0)
  {
    return Line::J;
  }
  if (strcmp(name, "Z") == 0)
  {
    return Line::Z;
  }
  if (strcmp(name, "G") == 0)
  {
    return Line::G;
  }
  return Line::Invalid;
}

inline const char* parseDirectionWithLine(Direction direction, Line line)
{
  switch (line)
  {
  case Line::Invalid:
    return "???";
  case Line::One:
  case Line::Two:
  case Line::Three:
  case Line::Four:
  case Line::Five:
  case Line::Six:
    return direction == Direction::N ? "BRX" : "DT";
  case Line::Seven:
    return direction == Direction::N ? "QNS" : "MAN";
  case Line::S:
    return direction == Direction::N ? "N" : "S";
  case Line::L:
    return direction == Direction::N ? "MAN" : "BRK";
  case Line::N:
  case Line::R:
  case Line::W:
  case Line::Q:
    return direction == Direction::N ? "MAN" : "BRK";
  case Line::B:
  case Line::D:
    return direction == Direction::N ? "MAN" : "BRK";
  case Line::M:
    return direction == Direction::N ? "MAN" : "QNS"; // This seems like it should be reversed, but its correct
  case Line::F:
    return direction == Direction::N ? "QNS" : "BRK";
  case Line::A:
  case Line::C:
  case Line::E:
    return direction == Direction::N ? "MAN" : "QNS";
  case Line::J:
  case Line::Z:
    return direction == Direction::N ? "QNS" : "MAN";
  case Line::G:
    return direction == Direction::N ? "QNS" : "BRK";
  }
  return "";
}

String queryEndpoint(const char* url) {
  wifi_client->setCACert(MTA_CERT);

  //create an HTTPClient instance
  HTTPClient https;

  //Initializing an HTTPS communication using the secure client
  Serial.print("[HTTPS] begin...\n");
  if (https.begin(*wifi_client, url)) {  // HTTPS
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

void updateStationData() {
  if (station_info == nullptr || station_info->id == nullptr) {
    Serial.println("Unable to update station data as data or id is not present!");
    return;
  }

  String response = queryEndpoint(SERVER_URL);
  Serial.printf("Station query response: %s\n", response.c_str());

  // Get good data from the protobuffer
  EmbeddedProto::ReadBufferFixedSize<65536> buf;
  memcpy(buf.get_data(), response.c_str(), response.length());
  buf.set_bytes_written(response.length());

  transit_realtime::FeedMessage<>::deserialize(buf);

  //
  // JsonDocument doc;
  // deserializeJson(doc, response);
  // String name = doc["data"][0]["name"];
  // station_info->name = name;
  // JsonArray stops;
  // if (station_info->direction == Direction::N)
  // {
  //   stops = doc["data"][0]["N"].as<JsonArray>();
  // } else
  // {
  //   stops = doc["data"][0]["S"].as<JsonArray>();
  // }
  //
  // for (size_t i = 0; i < 3; i++) {
  //   // Clear the station info
  //   station_info->times[i] = "";
  //   station_info->minsTo[i] = "";
  //   station_info->lines[i] = Line::Invalid;
  //
  //   if (stops.size() <= i) {
  //     break;
  //   }
  //   auto stop = stops[i].as<JsonObject>();
  //
  //   String dateTime = stop["time"];
  //   int _year, _month, _day, hour, minute, seconds, _a, _b;
  //   sscanf(dateTime.c_str(), "%d-%d-%dT%d:%d:%d-%d:%d", &_year, &_month, &_day, &hour, &minute, &seconds, &_a, &_b);
  //   char time_fmt[50];
  //   sprintf(time_fmt, "%02d:%02d", hour, minute);
  //   Serial.printf("Parsed time: %s\n", time_fmt);
  //
  //   float difference_seconds = stop["time_delta"];
  //   char diff_fmt[50];
  //   int mins = (int) (difference_seconds / 60.0f);
  //   sprintf(diff_fmt, "%d mins", mins);
  //   station_info->times[i] = String(time_fmt);
  //   station_info->minsTo[i] = String(diff_fmt);
  //   station_info->lines[i] = getLineFromName(stop["route"]);
  // }
}

void drawLine(int16_t x, int16_t y, int16_t radius, Line line) {
  dma_display->fillCircle(x, y, radius, getLineColor(line));
  dma_display->setCursor(x-1, y+2);
  if (line == Line::N || line == Line::Q || line == Line::R || line == Line::W)
  {
    dma_display->setTextColor(COLOR_BLACK);
  } else
  {
    dma_display->setTextColor(COLOR_WHITE);
  }
  dma_display->printf(getLineName(line));
  // Reset the color back to white
  dma_display->setTextColor(COLOR_WHITE);
}

inline String ellipsizeName(const String& s, size_t maxLen)
{
  if (s.length() <= maxLen) return s;
  if (maxLen <= 3) return s.substring(0, maxLen);
  return s.substring(0, maxLen - 3) + "...";
}

void drawStationData() {
  dma_display->clearScreen();
  int16_t start = 12;
  Line l = Line::Invalid;
  for (int16_t i = 0; i < 3; i++) {
    if (station_info->lines[i] == Line::Invalid)
    {
      break;
    }
    l = station_info->lines[i];
    int y = start + (8 * i);
    drawLine(5, y, 3, station_info->lines[i]);
    dma_display->setCursor(10, y+2);
    dma_display->printf("%s (%s)\n", station_info->minsTo[i].c_str(), station_info->times[i].c_str());
  }

  // Draw the station name and direction based on one of the lines above
  dma_display->setCursor(2, 6);
  // Ellipsize long station names to avoid squishing on the display
  String shortName = ellipsizeName(station_info->name, 12);
  dma_display->printf("%s - %s", shortName.c_str(), parseDirectionWithLine(station_info->direction, l));
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
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin(); 
  dma_display->clearScreen();
  dma_display->setFont(&Picopixel);
  dma_display->setTextSize(1);
  
  
  // Connect to wifi first
  Serial.print("Connecting to WiFi: ");
  dma_display->println("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());
                                   

  // Network client 
  dma_display->clearScreen();
  dma_display->println(".....");
  Serial.println("Connecting to server");
  wifi_client = new WiFiClientSecure();
  
  // Populate the station info
  station_info = new StationInfo();
  station_info->id = STATION_ID;
  station_info->direction = STATION_DIRECTION;
}

void loop() {
  updateStationData();
  drawStationData();
  delay(REFRESH_INTERVAL_MS);
}
