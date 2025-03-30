/* Experiment 03: Dimming a light using a potentiometer 
 * NOTE: See warning below about code modification. */

const int switchInputPin = 2;
const int LEDDrivePin = 3;

/* use volatine for interrupt variables */
volatile byte buttonState = LOW;

void setup()
{
  pinMode(LEDDrivePin, OUTPUT);
  pinMode(switchInputPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(switchInputPin), OnButtonPressed, FALLING);
}

/* interrupt routine attached to pin 2 (button) */
void OnButtonPressed()
{
  buttonState = !buttonState;
}

void loop()
{
  int potentiometerValue = analogRead(A0);

  if (buttonState)
  {
    /* Analog Digital Converter (ADC) works on a 0 to 1023 scale, while Pulse
     * Width Modulation works on a 0 to 255 scale. Thus, mapping is required. */
    potentiometerValue = map(potentiometerValue, 0, 1023, 0, 255);
    analogWrite(LEDDrivePin, potentiometerValue);
  }
  else
  {
    /* WARNING: this was digitalWrite(LEDDrivePin, LOW) in Kitronic Inventor's
     * Tutorial Book. However, it did not appear to work properly */
    analogWrite(LEDDrivePin, LOW); /* turn LED off */
  }
}