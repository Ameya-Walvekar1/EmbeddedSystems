/*
  Assignment 3
  Pushbutton and LED with Debouncing

  Connections:
  Pushbutton:
    One terminal -> Arduino D7
    Other terminal -> GND

  LED:
    Arduino D8 -> 220-330 ohm resistor -> LED -> GND

  Logic using INPUT_PULLUP:
    Button released -> HIGH
    Button pressed  -> LOW

  A 50 ms delay is used for debouncing.
*/

const int BUTTON_PIN = 7;     // Pushbutton connected to D7
const int LED_PIN = 8;        // LED connected to D8

void setup()
{
  // Configure the button as an input with the
  // Arduino's internal pull-up resistor enabled.
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Configure the LED pin as an output.
  pinMode(LED_PIN, OUTPUT);

  // Initially keep the LED OFF.
  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  // Read the current state of the pushbutton.
  int buttonState = digitalRead(BUTTON_PIN);

  // With INPUT_PULLUP, LOW means the button is pressed.
  if (buttonState == LOW)
  {
    // Wait 50 ms to allow switch bouncing to settle.
    delay(50);

    // Read the button again after the debounce delay.
    buttonState = digitalRead(BUTTON_PIN);

    // If the button is still LOW, it is a valid press.
    if (buttonState == LOW)
    {
      // Turn the LED ON.
      digitalWrite(LED_PIN, HIGH);

      // Keep the LED ON while the button remains pressed.
      while (digitalRead(BUTTON_PIN) == LOW)
      {
        // Wait here until the button is released.
      }
    }
  }
  else
  {
    // Button is released, so turn the LED OFF.
    digitalWrite(LED_PIN, LOW);
  }
}