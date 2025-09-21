#include <ArduinoJson.h>
#include "mtainfo.h"

const char* SERVER_URL = "18.216.136.118";
const char* SERVER_ENDPOINT = "/by-id";

const char* SSID = "Kings";
const char* password = "thepactbindsthem";

#define REFRESH_INTERVAL_MS 30000
                    
String queryEndpoint(const char* url, const uint16_t port, const char* endpoint, const char* params, unsigned long timeout_duration) { 
  if (!wifi_client->connect(url, port)) {
    return "No connection to server!";
  }
  Serial.printf("Connected successfully to %s:%d\n", url, wifi_client->remotePort());
  Serial.printf("Querying endpoint %s with params %s\n", endpoint, params);
  WIFI_WRITE("GET %s/%s HTTP/1.0\r\n\r\n", endpoint, params);

  unsigned long timeout = millis();
  while (!wifi_client->available()) {
    if (millis() - timeout > timeout_duration) {
      Serial.println("Timed out!");
      wifi_client->stop();
      return wifi_client->readString();
    }
  }
  
  while(wifi_client->available()) {
    String line = wifi_client->readStringUntil('\n');
    Serial.printf("DEBUG: %s\n", line.c_str());
    if (line.length() < 2) {
      break;
    }
  }
  
  return wifi_client->readString(); 
}

void convertFromJson(JsonVariantConst src, tm& dst) {
  strptime(src.as<const char*>(), "%Y-%m-%dT%H:%M:%S-%W:%W", &dst);
}

void updateStationData(StationInfo* station_info) {
  if (station_info == nullptr || station_info->id == nullptr) {
    Serial.println("Unable to update station data as data or id is not present!");
    return;
  }

  String response = queryEndpoint(SERVER_URL, SERVER_PORT, SERVER_ENDPOINT, station_info->id, DEFAULT_TIMEOUT);
  Serial.printf("Station query response: %s\n", response.c_str());
  
  JsonDocument doc;
  deserializeJson(doc, response);
  String name = doc["data"][0]["name"];
  station_info->name = name;
  
  auto stops = doc["data"][0]["S"].as<JsonArray>();
  for (size_t i = 0; i < 3; i++) {
    station_info->times[i] = "";
    station_info->minsTo[i] = "";
    if (stops.size() <= i) {
      break;
    }
    auto stop = stops[i].as<JsonObject>();

    String dateTime = stop["time"];
    int _year, _month, _day, hour, minute, seconds, _a, _b;
    sscanf(dateTime.c_str(), "%d-%d-%dT%d:%d:%d-%d:%d", &_year, &_month, &_day, &hour, &minute, &seconds, &_a, &_b);
    char time_fmt[50];
    sprintf(time_fmt, "%02d:%02d", hour, minute);
    Serial.printf("Parsed time: %s\n", time_fmt);
    
    float difference_seconds = stop["time_delta"];
    char diff_fmt[50];
    int mins = (int) (difference_seconds / 60.0f);
    sprintf(diff_fmt, "%d mins", mins);
    station_info->times[i] = String(time_fmt);
    station_info->minsTo[i] = String(diff_fmt);
  }  
}

void drawStationData(const StationInfo* station_info) {
  dma_display->clearScreen();
  // TODO: Eventually draw the correct line depending on the station 
  // for now hard-code Gates Ave J
  dma_display->fillCircle(8, 8, 8, MTA_BROWN);  
  dma_display->setCursor(4, 14);
  dma_display->setFont(&FreeSans9pt7b);
  dma_display->printf("J ");
  
  dma_display->setFont(&Picopixel);
  dma_display->setCursor(20, 10);
  dma_display->printf("%s", station_info->name);
  int start = 22;
  for (int i = 0; i < 3; i++) {
    dma_display->setCursor(4, start + (7 * i));
    dma_display->printf("%s (%s)\n", station_info->minsTo[i], station_info->times[i]);
  }
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
  dma_display->setFont(&FreeSans9pt7b);
  dma_display->setTextSize(1);
  
  
  // Connect to wifi first
  Serial.print("Connecting to WiFi: ");
  dma_display->println("Connecting to WiFi");
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
  wifi_client = new WiFiClient();
  
  dma_display->clearScreen();

  // Populate the station info
  station_info = new StationInfo();
  station_info->id = "J30"; // Gates Ave J
}


void loop() {
  updateStationData(station_info);
  drawStationData(station_info);
  delay(REFRESH_INTERVAL_MS);
}
