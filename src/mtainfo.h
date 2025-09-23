#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <Adafruit_GFX.h>
#include <WiFi.h>
#include <json_parser.h>

#define WIFI_WRITE(format, ...)                 \
    wifi_client->printf(format, ##__VA_ARGS__); \
    Serial.printf(format, ##__VA_ARGS__);

#define MAX_STOP_TIMES 3

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

#define DEFAULT_TIMEOUT 15000

#define SERVER_PORT 5000

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
