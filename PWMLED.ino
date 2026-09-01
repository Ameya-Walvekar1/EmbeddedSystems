/*
  Assignment 6A
  PWM Control of LED Brightness

  LED:
    Arduino D9 -> 220-330 ohm resistor -> LED -> GND

  PWM values:
    0   -> 0% duty cycle
    64  -> approximately 25%
    128 -> approximately 50%
    192 -> approximately 75%
    255 -> approximately 100%

  Purpose:
  To observe how PWM duty cycle affects LED brightness.
*/

const int LED_PIN = 9;     // D9 is a PWM-capable pin

void setup()
{
  // Configure the LED pin as an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // 0% duty cycle - LED OFF.
  analogWrite(LED_PIN, 0);
  delay(1000);

  // Approximately 25% duty cycle.
  analogWrite(LED_PIN, 64);
  delay(1000);

  // Approximately 50% duty cycle.
  analogWrite(LED_PIN, 128);
  delay(1000);

  // Approximately 75% duty cycle.
  analogWrite(LED_PIN, 192);
  delay(1000);

  // 100% duty cycle - LED fully ON.
  analogWrite(LED_PIN, 255);
  delay(1000);
}