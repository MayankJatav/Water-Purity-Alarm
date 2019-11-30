#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(7, 6); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  //Serial.println("Check");

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  //Serial.println("Check");

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  //delay(500);
  updateSerial();

  //Serial.println("Check");
  
  mySerial.println("AT+CMGS=\"+918319594095\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //delay(500);
  updateSerial();

  //Serial.println("Check");
  
  mySerial.print("Hello! I am Arduino with SIM 800L Module"); //text content
  //delay(500);
  updateSerial();

  //Serial.println("Check");
  
  Serial.write(26);

  //Serial.println("Check");
}

void loop()
{
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
