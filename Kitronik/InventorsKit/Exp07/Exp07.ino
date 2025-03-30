/* Experiment 07: Use a seven segment display to count numbers from 1 to 9 and
 * then back down from 9 to 1.
 * 
 *          A
 *        -----
 *      F | G | B
 *        -----
 *      E |   | C
 *        -----
 *          D
 */

# define CLEAR_DISPLAY 10

/* maps pin states for the seven segments to digits */
const bool Numbers[11][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 0, 0, 1, 1 }, // 9
  { 0, 0, 0, 0, 0, 0, 0 }  // clear
};

/* setup pin state for given number */
int displayNumber(int numberToDisplay)
{
  int pin = 2;
  for (int segment = 0; segment < 7; ++segment)
  {
    digitalWrite(pin, Numbers[numberToDisplay][segment]);
    pin++;
  }
  return numberToDisplay;
}

void setup()
{
  for (int i = 2; i < 10; ++i)
    pinMode(i, OUTPUT);
}

void loop()
{
  /* count up */
  for (int i = 0; i < 10; ++i)
  {
    displayNumber(i);
    delay(1000);
  }

  /* count down */
  for (int i = 9; i >= 0; --i)
  {
    displayNumber(i);
    delay(1000);
  }

  displayNumber(CLEAR_DISPLAY);
  delay(1000);
}