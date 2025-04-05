#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

/* the matrix has 8 x 12 = 96 LEDs, and thus the matrix state can be
 * represented by an array of three 32-bit integers */
const uint32_t happy[] = {
    0x19819,
    0x80000001,
    0x81f8000
};

const uint32_t heart[] = {
    0x3184a444,
    0x44042081,
    0x100a0040
};

void setup()
{
  Serial.begin(115200);
  matrix.begin();
}

void loop()
{
  matrix.loadFrame(happy);
  delay(500); /* wait half a second */

  matrix.loadFrame(heart);
  delay(500);
}