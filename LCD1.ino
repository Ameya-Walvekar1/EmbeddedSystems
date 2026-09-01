/*
  Assignment 4
  16x2 LCD Interface Using I2C

  LCD Connections:
    VCC -> Arduino 5V
    GND -> Arduino GND
    SDA -> Arduino A4
    SCL -> Arduino A5

  Common I2C address:
    0x27

  If the LCD does not respond, check its actual
  I2C address using an I2C scanner.
*/

// Include the library used to communicate with the LCD.
#include <Wire.h>

// Include the I2C LCD control library.
#include <LiquidCrystal_I2C.h>

// Create an LCD object.
// 0x27 = I2C address
// 16   = number of columns
// 2    = number of rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // Initialize the LCD.
  lcd.init();

  // Turn ON the LCD backlight.
  lcd.backlight();

  // Set cursor to column 0, row 0.
  lcd.setCursor(0, 0);

  // Display a message on the first row.
  lcd.print("Hello");

  // Move cursor to column 0, row 1.
  lcd.setCursor(0, 1);

  // Display a message on the second row.
  lcd.print("MMCOE");
}

void loop()
{
  // No repeated operation is required.
  // The displayed text remains on the LCD.
}