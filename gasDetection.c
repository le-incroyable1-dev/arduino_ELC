int analogPin = A0;
int gasPressure = 0;

void setup()
{
  Serial.begin(9600);
  Serial.print("GAS SENSOR INITIATED \n");
}

void loop()
{
  
  delay(100);
  
  gasPressure = analogRead(analogPin);     // read the input pin
  Serial.println(gasPressure);  // debug value
  
  
  if (gasPressure >000 && gasPressure <= 120){
		//lcd.print("Normal");
    	Serial.print("\n NORMAL OR LOW GAS DETECTED \n");
    	digitalWrite(8, HIGH);
    	digitalWrite(12, LOW);
  		digitalWrite(13, LOW);
  		digitalWrite(7, LOW);
  	}else if (gasPressure > 120 && gasPressure <= 200){
		//lcd.print("Dense Gas Det");
    	Serial.print("\n DENSE GAS DETECTED !\n");
    	digitalWrite(12, HIGH);
    	digitalWrite(8, LOW);
  		digitalWrite(13, LOW);
  		digitalWrite(7, LOW);
    }else if (gasPressure > 200){
		//lcd.print("EMERGENCY!");
    	Serial.print("\n EMERGENCY LEVELS !! \n");
    	digitalWrite(13, HIGH);
    	digitalWrite(7, HIGH);
    	digitalWrite(8, LOW);
  		digitalWrite(12, LOW);
    }
  
}
