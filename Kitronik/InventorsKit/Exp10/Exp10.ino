/* Experiment 10: Use an RGB LED to generate many colors.
 * NOTE: RGB LED legs are, left to right: Red, Green, Blue, which is different 
 * to the diagram in Kitronic Inventor's Kit Tutorial Book. */

#define RED_IN 2
#define GREEN_IN 3
#define BLUE_IN A0

#define RED_OUT 9
#define GREEN_OUT 10
#define BLUE_OUT 11

#define INCREMENT 25
#define THRESHOLD 226

/* red and green LEDs are controlled by buttons, and so are declared volatine */
volatile int redValue = 0;
volatile int greenValue = 0;
int blueValue = 0;

void onRedButtonPressed()
{
  if (redValue < THRESHOLD)
    redValue += INCREMENT;
  else
    redValue = 0;
}

void onGreenButtonPressed()
{
  if (greenValue < THRESHOLD)
    greenValue += INCREMENT;
  else
    greenValue = 0;
}

void setup()
{
  pinMode(RED_IN, INPUT);
  pinMode(GREEN_IN, INPUT);

  /* set interrupt on input buttons */
  attachInterrupt(digitalPinToInterrupt(RED_IN), onRedButtonPressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(GREEN_IN), onGreenButtonPressed, FALLING);

  /* pins connected to RGB LED are PWM outputs */
  pinMode(RED_OUT, OUTPUT);
  pinMode(GREEN_OUT, OUTPUT);
  pinMode(BLUE_OUT, OUTPUT);
}

void loop()
{
  int potentiometerValue = analogRead(BLUE_IN);
  blueValue = map(potentiometerValue, 0, 1023, 0, 255);
  analogWrite(RED_OUT, redValue);
  analogWrite(GREEN_OUT, greenValue);
  analogWrite(BLUE_OUT, blueValue);
}