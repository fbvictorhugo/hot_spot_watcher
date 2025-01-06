/**
 * HotSpotWatcher-Arduino is a simple and efficient project designed to monitor 
 * and alert about overheating in confined spaces, such as cabinets 
 * where electronic devices like gaming consoles are installed.
 *
 * Author: fbvictorhugo
 * Version: 0.1.0
 * License: MIT
 */

#include <DHT11.h>
#include <Wire.h>         // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"  // legacy include: `#include "SSD1306.h"`
#include "NodeMcuPins.h"
#include "OLEDDisplayUi.h"  // Include the UI lib

// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to Digital I/O Pin 2.
// - For ESP32: Connect the sensor to pin GPIO2 or P2.
// - For ESP8266: Connect the sensor to GPIO2 or D4.
DHT11 dht11(D4);

SSD1306Wire display(0x3c, D5, D6);
OLEDDisplayUi ui(&display);

//-------- Variables --------------------------------
int temperature = 0;
int humidity = 0;
const int LED_PIN = D2;
const int BUZZER_PIN = D1;

const int TEMP_WARNING = 34;
const int TEMP_CRITICAL = 38;
const int TONE = 432;

String msgError = "";
int screenW = 128;
int screenH = 64;

//-------- UI Displays --------------------------------

void temperatureFrame(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  if (isDHT11Error()) {
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->setFont(ArialMT_Plain_16);
    display->drawString(x + 20, y + 10, "  Erro 2");
  } else {
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->setFont(ArialMT_Plain_16);
    display->drawString(x + 20, y + 10, String(temperature) + " ºC");
  }
}

void humidityFrame(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y) {

  if (isDHT11Error()) {
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->setFont(ArialMT_Plain_16);
    display->drawString(x + 20, y + 10, " Frame 1");
  } else {
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->setFont(ArialMT_Plain_16);
    display->drawString(x + 20, y + 10, String(humidity) + " %");
  }
}


void appOverlay(OLEDDisplay* display, OLEDDisplayUiState* state) {
}

void msOverlay(OLEDDisplay* display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, String(millis()));
}

FrameCallback frames[] = { temperatureFrame, humidityFrame };
OverlayCallback overlays[] = { msOverlay };

//-------- Life Cycle -------------------------------

void setup() {
  // pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  Serial.println();


  ui.setTargetFPS(30);
  ui.setActiveSymbol(ANIMATION_activeSymbol);
  ui.setInactiveSymbol(ANIMATION_inactiveSymbol);
  ui.setIndicatorPosition(BOTTOM);
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setFrames(frames, 2);
  ui.setOverlays(overlays, 1);
  ui.init();
}

void loop() {

  int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0) {
    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.

    /*
    int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    msgError = "";

    ledOff();
    log(temperature, humidity);

    if (temperature >= TEMP_WARNING) {
      ledOn();
    } else {
      ledOff();
    }

    if (temperature >= TEMP_CRITICAL) {
      playBuzzer();
    }

  } else {
    ledOn();
    Serial.println(DHT11::getErrorString(result));
    msgError = "Error " + String(result);
  }
    */

    delay(remainingTimeBudget);
  }
}

//-------- Utils Functions --------------------------------

void log(int temperature, int humidity) {
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\tHumidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}

void writeDisplay(OLEDDisplay* display, String text) {
  // Limpa a tela para garantir que não haja sobreposição
  display->clear();

  // Configura o alinhamento e a fonte
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(ArialMT_Plain_24);

  // Desenha o texto na posição desejada
  display->drawString(display->getWidth() / 2, display->getHeight() / 2 - 16, text);
}


void ledOn() {
  digitalWrite(LED_PIN, HIGH);
}

void ledOff() {
  digitalWrite(LED_PIN, LOW);
}

void playBuzzer() {
  tone(BUZZER_PIN, TONE, 50);
  Serial.println("BUZZER BUZZER BUZZER");
}

bool isDHT11Error() {
  return !msgError.isEmpty();
}
