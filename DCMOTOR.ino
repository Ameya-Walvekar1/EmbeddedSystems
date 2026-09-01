/*
  Assignment 6C
  DC Motor Speed Control Using PWM and L293D

  Arduino -> L293D:
    D9 -> EN1   (PWM speed control)
    D8 -> IN1   (motor direction)
    D7 -> IN2   (motor direction)

  L293D:
    OUT1 and OUT2 -> DC motor

  IMPORTANT:
    - Do NOT connect the motor directly to Arduino GPIO.
    - Use an external motor supply.
    - Connect Arduino GND and motor-driver GND together.

  Purpose:
  To control the speed of a DC motor using PWM.
*/

const int EN1 = 9;       // PWM pin connected to L293D enable
const int IN1 = 8;       // Motor direction input 1
const int IN2 = 7;       // Motor direction input 2

void setup()
{
  // Configure motor-control pins as outputs.
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Set the motor to one fixed direction.
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Initially keep the motor stopped.
  analogWrite(EN1, 0);
}

void loop()
{
  // Low PWM value.
  // Motor receives a low average drive.
  analogWrite(EN1, 80);
  delay(2000);

  // Medium PWM value.
  // Motor speed should increase.
  analogWrite(EN1, 150);
  delay(2000);

  // Full PWM value.
  // Motor receives maximum average drive.
  analogWrite(EN1, 255);
  delay(2000);

  // Stop the motor.
  analogWrite(EN1, 0);
  delay(2000);
}