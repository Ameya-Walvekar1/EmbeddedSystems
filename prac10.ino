const int sensorPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int total = 0;
  int rawADC = 0;

  for (int i = 0; i < 10; i++)
  {
    rawADC = analogRead(sensorPin);
    total += rawADC;

    delay(10);
  }

  float average = total / 10.0;

  float voltage = average * 5.0 / 1023.0;

  // LM35: 10 mV per degree Celsius
  float temperature = voltage * 100.0;

  Serial.print("Raw ADC: ");
  Serial.println(rawADC);

  Serial.print("Filtered ADC: ");
  Serial.println(average);

  Serial.print("Voltage: ");
  Serial.print(voltage, 3);
  Serial.println(" V");

  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" C");

  Serial.println("----------------");

  delay(1000);
}
