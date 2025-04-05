/* Speciation: draw a phylogeny depicting a speciation process in time, from a
 * single common ancestor to three descendant species. */

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const uint32_t speciation[8][3] = {
  {0x00000000, 0x00000000, 0x00000040},
  {0x00000000, 0x00000000, 0x000A0040},
  {0x00000000, 0x00000000, 0xA00A0040},
  {0x00000000, 0x00001100, 0xA00A0040},
  {0x00000000, 0x01101100, 0xA00A0040},
  {0x00000028, 0x81101100, 0xA00A0040},
  {0x00028828, 0x81101100, 0xA00A0040},
  {0x44428828, 0x81101100, 0xA00A0040}
};

void setup()
{
  Serial.begin(115200);
  matrix.begin();
}

void loop()
{
  for (int i = 0; i < 8; ++i)
  {
    matrix.loadFrame(speciation[i]);
    delay(250);
  }
  delay(1000); /* display the full phylogeny a little longer */
}