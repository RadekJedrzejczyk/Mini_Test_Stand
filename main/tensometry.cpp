#include "tensometry.h"


void TensometryCalibration(HX711& scale,int DAT_PIN,int CLK_PIN)
{
  float calibration_factor = 800;
  Serial.begin(9600);
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Use + and - to get correct calibration factor, enter 'exti' to finish");
  delay(5000);

  scale.begin(DAT_PIN, CLK_PIN);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);



  while (true){
  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.print("kg"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();

    if(Serial.available())
      {
        char temp = Serial.read();
      if(temp == '+' || temp == 'a')
        calibration_factor += 100;
      else if(temp == '-' || temp == 'z')
        calibration_factor -= 100;
      else if(temp=='exit' || temp=='e')
        break;
      }

}
}



void TensometerPrintReading(HX711& scale)
{
  Serial.print("Tensometer reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.print("kg\n");

}