/*
Required libraries have already been included
in the arduino software
*/

int brightness = 0;

void setup()
{
  Serial.begin(9600);
  /*
  Allow communication between
  arduino device and serial monitor
  to get the required output.
  The number inside is the communication rate.
  */
  
  pinMode(11, OUTPUT);
  /*
  State the required pin invoked
  */
}

void loop()
{ 
  digitalWrite(11, HIGH); //Supply ON
  delay(2000);
  digitalWrite(11, LOW); //Supply OFF
  delay(2000);
  
  Serial.print("Starting loop !");
  delay(2000);
  
  //Controlling the brightness;
  
  for(brightness = 255; brightness >= 0; brightness = brightness - 5)
  {
    digitalWrite(11, brightness); //Supply ON
    Serial.print("Supply reduced");
    delay(100);
  }
  
  digitalWrite(11, LOW);
  
  Serial.print("Text Message Here ");
  delay(1000); //delays loop by 1000 ms or 1 s
}
