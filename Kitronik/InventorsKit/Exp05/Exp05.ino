/* Experiment 05: Control servo angle with potentiometer. */
#include <Servo.h>

#define SERVO_PIN 3  /* pin to control servo */

/* create a servo instance */
Servo myServo;

void setup()
{
  myServo.attach(SERVO_PIN);
}

void loop()
{
  int potentiometerValue = analogRead(A0);

  /* map potentiometer voltage to servo angle then write to servo */
  int servoValue = map(potentiometerValue, 0, 1023, 0, 180);
  myServo.write(servoValue);
  delay(100);
}