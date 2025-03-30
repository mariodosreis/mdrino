/* Experiment 01: Use a button to control the state of the LED built into the 
 * Arduino board. */

/* define a human readable name for the input the switch is connected to */
const int SwitchInputPin = 2;
/* variable to hold the buttom value: HIGH (TRUE) or LOW (FALSE) */
boolean buttonValue;

/* setup runs once when you press reset or power the board */
void setup() {
  /* initialise digital pin for the LED_BUILTIN as an output */
  pinMode(LED_BUILTIN, OUTPUT);
  /* and set switch pin as an input */
  pinMode(SwitchInputPin, INPUT);
}

/* loop function runs forever, reading button value and setting LED state */
void loop() {
  /* read state of button */
  buttonValue = digitalRead(SwitchInputPin);

  /* act on button value */
  if (buttonValue)
  {
    digitalWrite(LED_BUILTIN, HIGH);  /* turn LED on */
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);   /* turn LED off */
  }
}
