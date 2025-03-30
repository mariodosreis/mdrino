/* Experiment 02: Control an LED with a phototransistor. */

/* set to 20% of maximum level */
const int LightLevelSwitch = 200;

void setup()
{
  /* initialise digital pin for LED_BUILTIN as output */
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  /* read state of phototransitor */
  int LightValue = analogRead(A0);

  /* act on read */
  if (LightValue > LightLevelSwitch)
  {
    digitalWrite(LED_BUILTIN, LOW);  /* turn LED off */
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH); /* turn LED on */
  }
}