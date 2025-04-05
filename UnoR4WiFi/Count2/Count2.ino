/* Count from 00 to 99 on the UNO R4 WiFi LED Matrix.
 * An array stores 10 double-digit numbers, from 00 to 99. Then left and right
 * mask arrays are used to mask undesired digits using bitwise AND (&). The
 * masked arrays are merged back again using bitwise OR (^) to generate the
 * correct number to display.
 */ 
#include "Arduino_LED_Matrix.h"

#define RIGHT 0
#define LEFT  1

ArduinoLEDMatrix matrix;

const uint32_t clear[3] = {0x0, 0x0, 0x0};

const uint32_t numbers[10][3] = {
  {0x0007DF45, 0x14514514, 0x514517DF},  // 00
  {0x00004104, 0x10410410, 0x41041041},  // 11
  {0x0007DF04, 0x10417DF4, 0x104107DF},  // 22
  {0x0007DF04, 0x10417DF0, 0x410417DF},  // 33
  {0x00045145, 0x14517DF0, 0x41041041},  // 44
  {0x0007DF41, 0x04107DF0, 0x410417DF},  // 55
  {0x0007DF41, 0x04107DF4, 0x514517DF},  // 66
  {0x0007DF04, 0x10410410, 0x41041041},  // 77
  {0x0007DF45, 0x14517DF4, 0x514517DF},  // 88
  {0x0007DF45, 0x14517DF0, 0x410417DF}   // 99
};

/* right Mask has one-bits on left-half of frame and zero-bits on the right-half, 
 * thus masking bits on the right-half, and left Mask has the opposite */
const uint32_t Mask[2][3] = {
  {0x0007C07C, 0x07C07C07, 0xC07C07C0}, // right
  {0x00001F01, 0xF01F01F0, 0x1F01F01F}  // left
};

void joinFrames(int tens, int ones, uint32_t joined[]) 
{
  for (int i=0; i < 3; ++i)
    joined[i] = (numbers[tens][i] & Mask[RIGHT][i]) ^ (numbers[ones][i] & Mask[LEFT][i]);
}

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() 
{
  uint32_t frame[3];

  for (int i=0; i < 10; ++i)
    for (int j=0; j < 10; ++ j) {
      joinFrames(i, j, frame);
      matrix.loadFrame(frame);
      delay(1000);
    }
}
