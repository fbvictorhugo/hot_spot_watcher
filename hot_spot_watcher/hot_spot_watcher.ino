/**
 * HotSpotWatcher-Arduino is a simple and efficient project designed to monitor 
 * and alert about overheating in confined spaces, such as cabinets 
 * where electronic devices like gaming consoles are installed.
 *
 * Author: fbvictorhugo
 * Version: 0.0.1
 * License: MIT
 */

#include <DHT11.h>
#include <Wire.h>         // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"  // legacy include: `#include "SSD1306.h"`

// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to Digital I/O Pin 2.
// - For ESP32: Connect the sensor to pin GPIO2 or P2.
// - For ESP8266: Connect the sensor to GPIO2 or D4.
DHT11 dht11(2);

SSD1306Wire display(0x3c, 14, 12);

//-------- Variables --------------------------------
int temperature = 0;
int humidity = 0;
const int LED_PIN = 4;     //GPIO4 > D2
const int BUZZER_PIN = 5;  //GPIO5 > D1

const int TEMP_WARNING = 30;
const int TEMP_CRITICAL = 36;
const int TONE = 432;

//-------- Life Cycle -------------------------------

void setup() {
  Serial.begin(9600);

  display.init();
  display.flipScreenVertically();
  // display.setContrast(255);
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_10);
  writeDisplay("Inicializing ...");

  display.setFont(ArialMT_Plain_24);
}

void loop() {

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    ledOff();
    log(temperature, humidity);
    writeDisplay(String(temperature) + " ºC");

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
    writeDisplay("Error " + String(result));
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

void writeDisplay(String text) {
  display.clear();
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, text);
  display.display();
}

void ledOn() {
  digitalWrite(LED_PIN, HIGH);
}

void ledOff() {
  digitalWrite(LED_PIN, LOW);
}

void playBuzzer() {
  tone(BUZZER_PIN, TONE, 50);
}
