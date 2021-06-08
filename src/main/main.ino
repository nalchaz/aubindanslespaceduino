#include <TFT_HX8357.h> // Driver pour TFT ILIxx86


TFT_HX8357 tft = TFT_HX8357();


void setup() {

  Serial.begin(9600);
  
  tft.init();
  //tft.setRotation(1);
  

void loop() {

   
}
