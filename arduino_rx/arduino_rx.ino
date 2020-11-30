/* RECIEVER */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,6,5,4,3);

void setup()
{
  Serial.begin(9600);
  lcd.begin(32,2);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  if(Serial.read()==HIGH)
  {
    lcd.print("Digital Sensor ON");
    lcd.setCursor(0,1);
    lcd.print("recieving TEMP-SENSOR data....");
    Serial.print("temp : ");
    Serial.print(Serial.read());
    Serial.println("   *C");
    delay(500);
  }
  else
  {
    lcd.print("Digital Sensor OFF");
    lcd.setCursor(0,1);
    lcd.print("recieving TEMP-SENSOR data....");
    Serial.print("temp : ");
    Serial.print(Serial.read());
    Serial.println("   *C");
  }
  
  delay(50);
}
