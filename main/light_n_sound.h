#ifndef DIODECONTROLLER
#define DIODECONTROLLER
#include <Arduino.h>
#include <PCF8574.h>
#include <Wire.h>

class light_n_sound_controller
{
  PCF8574 expander;
  int REDDIODE;
  int YELLOWDIODE;
  int GREENDIODE;
  int BLUEDIODE;
  int BUZZER;

  public:
    void setup(int address, int reddiode, int yellowdiode, int greendiode, int bluediode, int buzzer);
    void red_up();
    void yellow_up();
    void green_up();
    void blue_up();
    void buzz();
    void all_down();
    void all_up();
    void check();
};

#endif