/* Experiment 04: Using a transistor to drive a motor. */

#define MAXVAL 255

/* analog output pin controlling motor */
const int MotorControlPin = 3;

void setup()
{
  pinMode(MotorControlPin, OUTPUT);
}

void loop() {
  int OutputValue;

  /* ramp up output value to speed up motor */
  for (OutputValue = 0; OutputValue < MAXVAL; OutputValue++)
  {
    analogWrite(MotorControlPin, OutputValue);
    delay(50); /* 50 milliseconds */
  }

  /* pause at full speed for 1/2 a second, to emphasize we are at max speed */
  delay (500);

  /* ramp down output value to slow down moter */
  for (OutputValue = 0; OutputValue > 0; OutputValue--) 
  {
    analogWrite(MotorControlPin, OutputValue);
    delay(50);
  }

  /* pause at low speed for 1/2 a second */
  delay(500);
}
