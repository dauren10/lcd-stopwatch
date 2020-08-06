//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
unsigned long t;
int ms;
int sec;
String mysec;
String mymin;
int min;
int hour;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
   Serial.begin(9600);
                   // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
 
}


void loop()
{

  
    t= millis();
    ms = t%1000;
    t = t/1000;
    sec = t%60;
    if(sec<10){
        mysec='0'+String(sec);
      }
      else{
        mysec=sec;
      }
    
    
    t = t/60;
    min = t%60;
     if(min<10){
        mymin='0'+String(min);
      }
      else{
        mymin=min;
      }
    
   
    lcd.setCursor(0,0);
    lcd.print(mymin);

    lcd.setCursor(2,0);
    lcd.print(":");
    
    lcd.setCursor(3,0);
    
     lcd.print(mysec);
    
    
    delay(1000);


}
