#ifndef FRAMESMODES
#define FRAMESMODES

#include <Arduino.h>
#include "Arduino_LED_Matrix.h"
extern byte frame_ModeNone[8][12];
extern byte frame_ModeA[8][12];
extern byte frame_ModeB[8][12];
extern byte frame_ModeC[8][12];
extern byte frame_ModeD[8][12];
extern byte frame_ModeE[8][12];

void FrameModeTest(ArduinoLEDMatrix& LED_Matrix);

#endif
