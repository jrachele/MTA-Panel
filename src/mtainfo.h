#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define MAX_STOP_TIMES 3

// Hard-code station data


enum class Direction
{
    N,
    S,
};

enum class Line {
    Invalid,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    S,
    L,
    N,
    R,
    Q,
    W,
    B,
    D,
    F,
    M,
    A,
    C,
    E,
    J,
    Z,
    G,
};

struct StationInfo
{
    const char *id;
    String name;
    Line lines[MAX_STOP_TIMES];
    String times[MAX_STOP_TIMES];
    String minsTo[MAX_STOP_TIMES];
    Direction direction;
    bool express;
};

#define COLOR_BROWN 0x8AE6
#define COLOR_BLUE 0x0319
#define COLOR_ORANGE 0xeb40
#define COLOR_LIGHTGREEN 0x7ca6
#define COLOR_DARKGREEN 0x04ca
#define COLOR_GRAY 0x7c31
#define COLOR_YELLOW 0xf5c5
#define COLOR_RED 0xd106
#define COLOR_PURPLE 0x99d4
#define COLOR_BLACK 0x0000
#define COLOR_WHITE 0xFFFF

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
