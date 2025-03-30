/* Experiment 09: Measure the voltage in a capacitor. Use LEDs to indicate
 * voltage level in capacitor.
 * NOTE: See warning below about missing outer brackets in if() statements in 
 * Kitroniks Investor's Kit Tutrial Book. */

#define RED 2
#define ORANGE 3
#define YELLOW 4
#define GREEN 5

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(ORANGE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
  /* read capacitor's voltage */
  int capacitorVoltage = analogRead(A0);

  /* convert to % value */
  int capacitorPercent = capacitorVoltage / 10; 

  /* WARNING: The tutorial book had missing outer brackets:
   *
   * "if () && ()"
   * insted of:
   * "if (() && ())"
   *
   * Note the internal brackets are not necessary as the && operator has lower
   * precedence than the >, >=, <, and =< operators */

  /* work out which LEDs to turn on */
  if (capacitorPercent > 25 && capacitorPercent <= 50)
  {
    digitalWrite(RED, HIGH);
  }
  else if (capacitorPercent > 50 && capacitorPercent <= 75)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(ORANGE, HIGH);
  }
  else if (capacitorPercent > 75 && capacitorPercent <= 90)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(ORANGE, HIGH);
    digitalWrite(YELLOW, HIGH);
  }
  else if (capacitorPercent > 90)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(ORANGE, HIGH);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, HIGH);
  }
  else /* below 25%, switch all LEDs off */
  {
    digitalWrite(RED, LOW);
    digitalWrite(ORANGE, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  }
}

