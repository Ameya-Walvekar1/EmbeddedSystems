/*
  Assignment 6B
  PWM Control of Buzzer

  Buzzer:
    Positive terminal -> Arduino D9
    Negative terminal -> GND

  IMPORTANT:
    This direct connection is suitable only for a
    low-current buzzer. A transistor driver should
    be used for a higher-current buzzer.

  Purpose:
  To observe the change in buzzer response
  with different PWM duty cycles.
*/

const int BUZZER_PIN = 9;    // PWM-capable pin

void setup()
{
  // Configure buzzer pin as an output.
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  // 0% duty cycle - buzzer OFF.
  analogWrite(BUZZER_PIN, 0);
  delay(1000);

  // Approximately 25% duty cycle.
  analogWrite(BUZZER_PIN, 64);
  delay(1000);

  // Approximately 50% duty cycle.
  analogWrite(BUZZER_PIN, 128);
  delay(1000);

  // Approximately 75% duty cycle.
  analogWrite(BUZZER_PIN, 192);
  delay(1000);

  // 100% duty cycle.
  analogWrite(BUZZER_PIN, 255);
  delay(1000);
}