//matryca led
#include "Arduino_LED_Matrix.h"
#include "frames_modes.h"
//CANBUS
#include <SPI.h>
#include <DFRobot_MCP2515.h>
#include "CAN_methods.h"
//Tensometer amp
#include "HX711.h"
#include "tensometry.h"
//Controling diodoes
#include "light_n_sound.h"

//#include <LiquidCrystal_I2C.h>

//PINS
#define DOUT  3
#define CLK  2
#define POWERGATE 4

#define DIODECONTR_I2C_ADDRESS 32
#define REDIODE_EXPANDER 0
#define YELLOWDIODE_EXPANDER 1
#define GREENDIODE_EXPANDER 2
#define BLUEDIODE_EXPANDER 3
#define BUZZER_EXPANDER 4

const int SPI_CS_PIN = 10;


//arduino classes
ArduinoLEDMatrix LED_Matrix;
HX711 scale;
DFRobot_MCP2515 CAN(SPI_CS_PIN); //set CS pin

PCF8574 expander;
light_n_sound_controller light_n_sound_control;

void setup() {
  Serial.begin(9600);
  LED_Matrix.begin();
  FrameModeTest(LED_Matrix);
  //initialiseCAN(CAN);
  // TensometryCalibration(scale, DOUT,CLK);
  pinMode(POWERGATE, OUTPUT);
  digitalWrite(POWERGATE, HIGH);
  //light_n_sound_control.setup(DIODECONTR_I2C_ADDRESS, REDIODE_EXPANDER,YELLOWDIODE_EXPANDER,GREENDIODE_EXPANDER,BLUEDIODE_EXPANDER,BUZZER_EXPANDER);
  //light_n_sound_control.check();
  
}
void loop() {
 
 }
