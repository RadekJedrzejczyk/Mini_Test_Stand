#ifndef TESNOMETRY
#define TENSOMETRY

#include <Arduino.h>
#include "HX711.h"


void TensometryCalibration(HX711& scale,int DAT_PIN,int CLK_PIN);

void TensometerPrintReading(HX711& scale);


#endif