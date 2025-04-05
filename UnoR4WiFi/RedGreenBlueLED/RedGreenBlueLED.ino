#define RED_OUT 11
#define GREEN_OUT 10
#define BLUE_OUT 9

double redValue = 0;
double greenValue = 0;
double blueValue = 0;

void setup()
{
  /* pins connected to RGB LED are PWM outputs */
  pinMode(RED_OUT, OUTPUT);
  pinMode(GREEN_OUT, OUTPUT);
  pinMode(BLUE_OUT, OUTPUT);
}

void loop()
{
    analogWrite(RED_OUT, 50);
    analogWrite(GREEN_OUT, 5);
    analogWrite(BLUE_OUT, 5);
}