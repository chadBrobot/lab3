// include the library code:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16,2);

#define button 25 
#define pot A7

void setup() {
    // set up the LCD's number of columns and rows:

    pinMode(button, INPUT);
    pinMode(pot, INPUT);
    lcd.init();
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.backlight();
    

}

void loop() {
  int x = analogRead(pot);
  int but = digitalRead(button); //0 = on 1 = off
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.setCursor(9,0);
 
  lcd.print("     ");
  lcd.setCursor(10,0);
  x = map(x, 0, 1023, 20, 120);
  lcd.print(x);
   delay(120);
  //Serial.println(but); 
  
  
}
