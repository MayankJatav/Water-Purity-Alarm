#include<SoftwareSerial.h>
SoftwareSerial ser(3,2);
int turbidity,ph;
void setup()
{
  //Serial.begin(9600);
  ser.begin(9600);
  pinMode(A1,INPUT);
  pinMode(A5,INPUT);
}

// the loop function runs over and over again forever
void loop()
{
  turbidity=analogRead(A1);
  ph=analogRead(A5);
  ser.write(turbidity);
  ser.write(" ");
  ser.write(ph);
  ser.write("\n");
  /*Serial.print(turbidity);
  Serial.print("  ");
  Serial.println(ph);
  delay(500);*/
  
  
}
