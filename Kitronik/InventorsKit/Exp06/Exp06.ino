/* Experiment 06: Setting the tone with a piezo buzzer. */

/* pin attached to piezo buzzer */
#define TONE_PIN 3

void setup()
{

}

void loop()
{
  int potentiometerValue = analogRead(A0);
  int toneValue = map(potentiometerValue, 0, 1023, 120, 5000);
  tone(TONE_PIN, toneValue);
}