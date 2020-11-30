/* TRANSMITTER */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,6,5,4,3);
int TEMP_SEN=A0;

void setup()
{
  pinMode(7,INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(32,2);
}

void loop()
{
  int digitalStatus=0;
  lcd.clear();
  lcd.setCursor(0,0);
  if(digitalRead(7)==LOW)
  {
    digitalStatus=1;
    lcd.print("Digital Sensor ON");
    lcd.setCursor(0,1);
    lcd.print("sending TEMP-SENSOR data....");
    Serial.write(digitalStatus);
    Serial.write(analogRead(TEMP_SEN)/2-1);
    delay(500);
  }
  else if(digitalRead(7)==HIGH)
  {
    digitalStatus=0;
    lcd.print("Digital Sensor OFF");
    lcd.setCursor(0,1);
    lcd.print("sending TEMP-SENSOR data....");
    Serial.write(digitalStatus);
    Serial.write(analogRead(TEMP_SEN)/2-1);
  }
  
  delay(50);
}
