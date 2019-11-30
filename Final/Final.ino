#include <SoftwareSerial.h>
SoftwareSerial mySerial(3,2); //Pin 3 is RX and Pin 2 is TX
String mobNumber="+917898372401";
String msg="Hello! I am arduino with SIM Module";


void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Initializing SIM Module....");
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  //sendMessage(mobNumber,msg);
  
}

void sendMessage(String number,String message)
{
  String s="AT+CMGS=\"";
  s.concat(number);
  s.concat("\"");
  mySerial.println(s);//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print(message); //text content
  updateSerial();
  mySerial.write(26);
  /*mySerial.print("AT+CMGS=\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  mySerial.print(number);
  mySerial.println("\"");
  updateSerial();
  mySerial.print(message); //text content
  updateSerial();
  mySerial.write(26);*/
}

void updateSerial()
{
  delay(500);
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}

void loop()
{
  if(Serial.available()>0)
  {
    String s=Serial.readString();
    //String s1=Serial.readString();
    sendMessage(s,"Message");
  }
}
