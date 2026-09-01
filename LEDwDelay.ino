/*
  Assignment 2A
  LED Blinking Using Software Delay

  LED Connection:
  LED anode -> Arduino D13 through 220-330 ohm resistor
  LED cathode -> GND

  Purpose:
  To blink an LED using the blocking delay() function.
*/

const int LED_PIN = 13;    // LED connected to digital pin 13

void setup()
{
  // Configure the LED pin as an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Turn the LED ON.
  digitalWrite(LED_PIN, HIGH);

  // Wait for 1000 milliseconds = 1 second.
  delay(1000);

  // Turn the LED OFF.
  digitalWrite(LED_PIN, LOW);

  // Wait for another 1 second.
  delay(1000);
}