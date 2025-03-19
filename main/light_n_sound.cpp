#include "light_n_sound.h"


void light_n_sound_controller::setup(int address, int reddiode, int yellowdiode, int greendiode, int bluediode, int buzzer)
{
  Wire.begin();
  if(expander.begin(address))
    Serial.write("Diode controller connected!\n");
  else
    Serial.write("Diode controller error!\n");

  REDDIODE = reddiode;
  YELLOWDIODE  =yellowdiode;
  GREENDIODE = greendiode;
  BLUEDIODE = bluediode;
  BUZZER = buzzer;
  all_down();
}


    void light_n_sound_controller::red_up()
    {
      expander.write(REDDIODE, 1);
    }
    void light_n_sound_controller::yellow_up()
    {
      expander.write(YELLOWDIODE, 1);
    }
    void light_n_sound_controller::green_up()
    {
      expander.write(GREENDIODE,1);
      
    }
     void light_n_sound_controller::blue_up()
    {
      expander.write(BLUEDIODE,1);
      
    }
     void light_n_sound_controller::buzz()
    {
      expander.write(BUZZER,1);
      
    }
    void light_n_sound_controller::all_down()
      {
        expander.selectNone();
      }
    void light_n_sound_controller::all_up()
    {
      expander.selectAll();
    }

    void light_n_sound_controller::check()
    {

      for(int i=0;i<3;i++)
      {
        expander.selectAll();
        delay(1000);
        expander.selectNone() ;
        delay(1000);
        if (expander.isConnected())
          Serial.write("Diode controller is all good \n");
        else 
          Serial.write("Something is wrong with diode controller \n") ;
      }
    }