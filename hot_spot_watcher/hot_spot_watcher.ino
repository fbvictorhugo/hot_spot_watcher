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

// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to Digital I/O Pin 2.
// - For ESP32: Connect the sensor to pin GPIO2 or P2.
// - For ESP8266: Connect the sensor to GPIO2 or D4.
DHT11 dht11(2);
int temperature = 0;
int humidity = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println(DHT11::getErrorString(result));
  }
}
