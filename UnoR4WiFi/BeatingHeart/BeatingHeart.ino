#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

/* the matrix has 8 x 12 = 96 LEDs, and thus the matrix state can be
 * represented by an array of three 32-bit integers */

/* little heart:   guess ordering by column:
 * 0000 0000 0000  0x 0122 1000  0x 0B40 1A40  0x 0088 0000 
 * 0001 1011 0000
 * 0010 0100 1000  guess ordering by row: (this is the right order)
 * 0010 0000 1000  0x 0001 B024  0x 8208 1100  0x A004 0000
 * 0001 0001 0000 
 * 0000 1010 0000  
 * 0000 0100 0000
 * 0000 0000 0000
 */

//const uint32_t littleHeart[] = { 0x01221000, 0x0B401A40, 0x00880000};
const uint32_t littleHeart[] = { 0x0001B024, 0x82081100, 0xA0040000 }; 

/* big heart:      ordering by row:
 * 0011 1011 1000  0x 3B87 FC64  0x C60C 3181  0x B00E 0040
 * 0111 1111 1100
 * 0110 0100 1100
 * 0110 0000 1100
 * 0011 0001 1000 
 * 0001 1011 0000  
 * 0000 1110 0000
 * 0000 0100 0000
 */

const uint32_t bigHeart[] = { 0x3B87FC64, 0xC60C3181, 0xB00E0040 };

void setup()
{
  Serial.begin(115200);
  matrix.begin();
}

void loop()
{
  matrix.loadFrame(littleHeart);
  delay(750);

  matrix.loadFrame(bigHeart);
  delay(750);
}
