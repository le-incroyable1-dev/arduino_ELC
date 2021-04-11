#include<Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);


int backLight = 13; // pin 13 will control the backlight

void setup()
{
  Serial.begin(9600);
  Wire.begin(4);                
  Wire.onReceive(receiveEvent); 
  //pinMode(13, OUTPUT);
  
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); 
  lcd.begin(16,2);  
  lcd.clear();  
  
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
  
  lcd.setCursor(0,0);
  lcd.print("RECEIVER :");
  lcd.clear();
}

void loop()
{ 
  delay(1000);
}

void receiveEvent(int howMany)
{
  char c = Wire.read(); 
  Serial.println(c);  
  if (c=='E')
  {
    Serial.write("EMERGENCY !\n");
    lcd.setCursor(0,0);
  	lcd.print("EMERGENCY !");
  	delay(4000);
  	lcd.clear();
  }
  else if (c == 'D')
  {
   	Serial.write("DENSE GAS !\n");
    lcd.setCursor(0,0);
  	lcd.print("DENSE GAS !");
  	delay(4000);
  	lcd.clear();
  }
  else if (c == 'N')
  {
    Serial.write("NORMAL\n");
    lcd.setCursor(0,0);
  	lcd.print("NORMAL");
  	delay(4000);
  	lcd.clear();
  }
}
