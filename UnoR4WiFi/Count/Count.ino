/* Count from 00 to 99 on the UNO R4 WiFi LED Matrix.
 * The LED matrix is divided into left and right frames, with the right frame
 * used to plot the "ones" and the left frame the "tens". Ones and tens are
 * stored as matrix arrays, and are joined into the full frame using bitwise OR.
 */ 
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const uint32_t clear[3] = {0x0, 0x0, 0x0};

const uint32_t ones[10][3] = {
  {0x00001F01, 0x10110110, 0x1101101F},  // _0
  {0x00000100, 0x10010010, 0x01001001},  // _1
  {0x00001F00, 0x100101F0, 0x1001001F},  // _2
  {0x00001F00, 0x100101F0, 0x0100101F},  // _3
  {0x00001101, 0x101101F0, 0x01001001},  // _4
  {0x00001F01, 0x001001F0, 0x0100101F},  // _5
  {0x00001F01, 0x001001F0, 0x1101101F},  // _6
  {0x00001F00, 0x10010010, 0x01001001},  // _7
  {0x00001F01, 0x101101F0, 0x1101101F},  // _8
  {0x00001F01, 0x101101F0, 0x0100101F}   // _9
};

const uint32_t tens[10][3] = {
  {0x0007C044, 0x04404404, 0x404407C0},  // 0_
  {0x00004004, 0x00400400, 0x40040040},  // 1_
  {0x0007C004, 0x00407C04, 0x004007C0},  // 2_
  {0x0007C004, 0x00407C00, 0x400407C0},  // 3_
  {0x00044044, 0x04407C00, 0x40040040},  // 4_
  {0x0007C040, 0x04007C00, 0x400407C0},  // 5_
  {0x0007C040, 0x04007C04, 0x404407C0},  // 6_
  {0x0007C004, 0x00400400, 0x40040040},  // 7_
  {0x0007C044, 0x04407C04, 0x404407C0},  // 8_
  {0x0007C044, 0x04407C00, 0x400407C0}   // 9_
};

void joinFrames(const uint32_t tens[], const uint32_t ones[], uint32_t joined[]) 
{
  for (int i=0; i < 3; ++i)
    joined[i] = tens[i] ^ ones[i];
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
      joinFrames(tens[i], ones[j], frame);
      matrix.loadFrame(frame);
      delay(1000);
    }
}
