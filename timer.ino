//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
unsigned long t;

unsigned long tr;
int ms;
int sec;
String mysec;
String mymin;
int min;
int hour;
boolean buttonWasUp = true;
boolean ledEnabled = false;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
   Serial.begin(9600);
                   // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
 
}

int





timer(boolean button,boolean button2){
  Serial.println(button);
  Serial.println(button2);
  return millis();
}

void loop()
{
 
     
   // узнаем, отпущена ли кнопка сейчас
   boolean buttonIsUp = digitalRead(2);
 
   // если кнопка была отпущена и не отпущена сейчас
   if (buttonWasUp && !buttonIsUp) {
    
      // исключаем дребезг контактов тактовой кнопки
      delay(10);

    // и считываем сигнал с кнопки снова
    buttonIsUp = digitalRead(2);

      // если кнопка нажата, то переворачиваем сигнал светодиода
      if (!buttonIsUp) {
         ledEnabled = !ledEnabled;
         digitalWrite(8, ledEnabled);
         tr = millis();
      }
      
   }
  
  
 
   // запоминаем состояние кнопки для новой итерации
   buttonWasUp = buttonIsUp;

   
    t=millis()-tr;
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
    




}
