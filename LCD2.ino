/*
  Assignment 4
  16x2 I2C LCD - Display and Update Text

  Purpose:
  To display different messages on the two rows
  and demonstrate cursor positioning.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address = 0x27
// LCD size = 16 columns x 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // Initialize the LCD.
  lcd.init();

  // Enable the LCD backlight.
  lcd.backlight();

  // Clear any previous content.
  lcd.clear();

  // Start at first column, first row.
  lcd.setCursor(0, 0);

  // Display text on row 1.
  lcd.print("Hello Arduino");

  // Start at first column, second row.
  lcd.setCursor(0, 1);

  // Display text on row 2.
  lcd.print("I2C LCD Test");
}

void loop()
{
  // Wait for 2 seconds.
  delay(2000);

  // Clear the display.
  lcd.clear();

  // Display a new message.
  lcd.setCursor(0, 0);
  lcd.print("Embedded");

  lcd.setCursor(0, 1);
  lcd.print("Systems Lab");

  // Wait before changing the message again.
  delay(2000);
}