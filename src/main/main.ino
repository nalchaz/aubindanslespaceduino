//Libraries
#include <SD.h>//https://www.arduino.cc/en/reference/SD
#include <Adafruit_GFX.h>//https://github.com/adafruit/Adafruit-GFX-Library
#include <MCUFRIEND_kbv.h>//https://github.com/prenticedavid/MCUFRIEND_kbv


#define SD_CS 10
#define BLACK 0
#define GREY 21845
#define BLUE 31
#define RED 63488
#define GREEN 2016
#define DARKGREEN 1472
#define CYAN 2047
#define MAGENTA 63519
#define YELLOW 65504
#define GOLD 56768
#define WHITE 65535

int days = 450;
int hours = 23;
int minuteNow = 33;
int secondNow = 20;

MCUFRIEND_kbv tft;


void setup() {
   Serial.begin(9600);
   Serial.println(F("Initialize System"));
   
   //Init tft screen
   uint16_t ID = tft.readID();
   if (ID == 0xD3D3) ID = 0x9486;  //for 3.5" TFT LCD Shield
   tft.begin(ID);
   tft.setRotation(1);//0-PORTRAIT 1-PAYSAGE 2-REVERSE PORTRAIT 3-REVERSE PAYSAGE
   tft.fillScreen(BLACK);
   tft.setTextSize(4);

   //tft.drawRoundRect(5,5,470,71,5,TFT_WHITE);
   //tft.drawRoundRect(6,6,470,71,5,TFT_WHITE);
   //Uncomment if you are using SD
   /*if (!SD.begin(SD_CS)) {
      Serial.println(F("initialization failed!"));
      return;
    }*/
}

void loop() {

  drawCompteur();
  
}

void drawCompteur()
{
   delay(1000);
   //DateTime now = rtc.now(); //get the current date-time
   //minuteNow = now.minute();
   //TODO get current time 
   // + get difference with pascale date
   secondNow++;

   tft.setTextColor(TFT_WHITE, TFT_BLACK);
   tft.setCursor(5, 20);
   tft.setTextSize(4);
   tft.print(String(days));
   tft.setTextSize(2);
   tft.print(" jours ");
   tft.setCursor(5, 60);
   tft.setTextSize(4);
   tft.print(String(hours));
   tft.setTextSize(2);
   tft.print(" heures");
   tft.setCursor(5, 100);
   tft.setTextSize(4);
   tft.print(String(minuteNow));
   tft.setTextSize(2);
   tft.print(" minutes");
   tft.setCursor(5, 140);
   tft.setTextSize(4);
   tft.print(String(secondNow));
   tft.setTextSize(2);
   tft.print(" secondes");
   
}
