#pragma once
#include <WiFiClientSecure.h>

#include "ESP32-HUB75-MatrixPanel-I2S-DMA.h"
#include "util.h"

// Station
const char* STATION_ID = "J30"; // Gates Ave J
const char* STATION_NAME = "Gates Ave";
Direction STATION_DIRECTION = Direction::S; // To Manhattan

constexpr int STATION_ID_LENGTH = 16;
constexpr int MAX_TRAINS = 3;

// TODO?: Embed station.txt data from MTA; not really relevant here since I'm not writing a whole API
struct Train
{
    Line line;
    int64_t arrivalTime;
};

struct StationInfo
{
    char id[STATION_ID_LENGTH]{};
    std::vector<Train> trains;
};

// Network
#define WIFI_WRITE(format, ...)                 \
g_Wifi->printf(format, ##__VA_ARGS__); \
Serial.printf(format, ##__VA_ARGS__);

// This is the cert for https://api-endpoint.mta.info
const char* MTA_CERT = \
    "-----BEGIN CERTIFICATE-----\n" \
    "MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n" \
    "ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n" \
    "b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n" \
    "MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n" \
    "b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n" \
    "ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n" \
    "9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n" \
    "IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n" \
    "VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n" \
    "93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n" \
    "jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n" \
    "AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n" \
    "A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n" \
    "U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n" \
    "N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n" \
    "o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n" \
    "5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n" \
    "rqXRfboQnoZsG4q5WTP468SQvvG5\n" \
    "-----END CERTIFICATE-----\n";

const char* SERVER_URL = "https://api-endpoint.mta.info/Dataservice/mtagtfsfeeds/nyct%2Fgtfs-jz";
constexpr int SERVER_PORT = 443;
constexpr int DEFAULT_TIMEOUT = 15000;
constexpr int QUERY_INTERVAL_SEC = 30;
constexpr int UPDATE_INTERVAL_MS = 1000;

const char* SSID = "Kings";
const char* password = "thepactbindsthem";

// Time
const char* NTP_SERVER = "pool.ntp.org";
const long GMT_OFFSET_HR = -5;
const long GMT_OFFSET_SEC = GMT_OFFSET_HR * 3600;
const int DAYLIGHT_OFFSET_SEC = 3600;

// Panel
#define PANEL_RES_X 64 // Number of pixels wide of each INDIVIDUAL panel module.
#define PANEL_RES_Y 32 // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1  // Total number of panels chained one to another

// Create display
static HUB75_I2S_CFG::i2s_pins pins = {
    25, // R1_PIN,
    26, // G1_PIN,
    27, // B1_PIN,
    14, // R2_PIN,
    12, // G2_PIN,
    13, // B2_PIN,
    23, // A_PIN,
    22, // B_PIN,
    5,  // C_PIN,
    17, // D_PIN,
    32, // E_PIN,
    4,  // LAT_PIN,
    15, // OE_PIN,
    16, // CLK_PIN
};

// Globals
MatrixPanel_I2S_DMA* g_Display = nullptr;
WiFiClientSecure* g_Wifi = nullptr;
StationInfo g_StationInfo;

