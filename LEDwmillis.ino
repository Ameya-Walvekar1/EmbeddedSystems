/*
  Assignment 2B
  LED Blinking Using Non-Blocking millis()

  LED Connection:
  LED anode -> Arduino D8 through 220-330 ohm resistor
  LED cathode -> GND

  Purpose:
  To blink an LED without blocking the main loop().
*/

const int LED_PIN = 8;           // LED connected to digital pin 8

const unsigned long interval = 1000; // LED toggle interval = 1000 ms

unsigned long previousMillis = 0;    // Stores the previous toggle time

bool ledState = LOW;                 // Stores the current LED state

void setup()
{
  // Configure the LED pin as an output.
  pinMode(LED_PIN, OUTPUT);

  // Initially keep the LED OFF.
  digitalWrite(LED_PIN, ledState);
}

void loop()
{
  // Get the current elapsed time in milliseconds.
  unsigned long currentMillis = millis();

  // Check whether 1000 ms have passed since the last toggle.
  if (currentMillis - previousMillis >= interval)
  {
    // Save the current time as the new reference time.
    previousMillis = currentMillis;

    // Toggle the LED state.
    // LOW becomes HIGH and HIGH becomes LOW.
    ledState = !ledState;

    // Apply the new state to the LED.
    digitalWrite(LED_PIN, ledState);
  }

  // Other tasks can be performed here.
  // Unlike delay(), the program is not stopped while waiting.
}