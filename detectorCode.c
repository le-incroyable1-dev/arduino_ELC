#include<Wire.h>

int analogPin = A0;
int gasPressure = 0;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.print("GAS SENSOR INITIATED \n");              
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  
  delay(100);
  
  gasPressure = analogRead(analogPin);     // read the input pin
  Serial.println(gasPressure);  // debug value
  
  Wire.beginTransmission(4);
  
  if (gasPressure >000 && gasPressure <= 120){
		//lcd.print("Normal");
    	Serial.print("\n NORMAL OR NO GAS DETECTED \n");
    	Wire.write('N');
    
    	digitalWrite(8, HIGH);
    	digitalWrite(12, LOW);
  		digitalWrite(13, LOW);
  		digitalWrite(7, LOW);
  	}else if (gasPressure > 120 && gasPressure <= 200){
		//lcd.print("Dense Gas Det");
    	Serial.print("\n DENSE GAS DETECTED !\n");
    	Wire.write('D');
    
    	digitalWrite(12, HIGH);
    	digitalWrite(8, LOW);
  		digitalWrite(13, LOW);
  		digitalWrite(7, LOW);
    }else if (gasPressure > 200){
		//lcd.print("EMERGENCY!");
    	Serial.print("\n EMERGENCY LEVELS !! \n");
    	Wire.write('E');
    
    	digitalWrite(13, HIGH);
    	digitalWrite(7, HIGH);
    	digitalWrite(8, LOW);
  		digitalWrite(12, LOW);
    }
       
  Wire.endTransmission();   
  delay(500);
}
