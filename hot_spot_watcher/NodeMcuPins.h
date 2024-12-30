#ifndef NODEMCU_PINS_H
#define NODEMCU_PINS_H

/*
 * NodeMcuPins.h
 * 
 * Description:
 * This file defines the pin mappings for the NodeMCU ESP8266 development board.
 * Each pin is assigned a name for ease of use in Arduino sketches.
 */

// === Digital Pin Mapping ===
#define D0 16  // GPIO16, general-purpose I/O
#define D1 5   // GPIO5, I2C SCL
#define D2 4   // GPIO4, I2C SDA
#define D3 0   // GPIO0, general-purpose I/O
#define D4 2   // GPIO2, built-in LED (active LOW)
#define D5 14  // GPIO14, SPI CLK
#define D6 12  // GPIO12, SPI MISO
#define D7 13  // GPIO13, SPI MOSI
#define D8 15  // GPIO15, SPI CS

// === Analog Pin Mapping ===
#define A0 0   // ADC pin, supports voltage range 0-1V

// === Power Pins ===
#define VCC 3.3 // 3.3V power supply
#define GND 0   // Ground

// === OLED I2C Pins ===
#define OLED_SDA D2  // GPIO4, I2C SDA for OLED
#define OLED_SCL D1  // GPIO5, I2C SCL for OLED

// === Additional Notes ===
// - GPIO0, GPIO2, and GPIO15 have specific roles during boot and must be used cautiously.
// - GPIO16 does not support PWM or I2C functionality.
// - A0 (ADC pin) accepts voltages between 0-1V. Use a voltage divider for higher inputs.

#endif // NODEMCU_PINS_H
