int x,y,z;
void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A3,INPUT);
  pinMode(A5,INPUT);
}

void loop() 
{
  x=analogRead(A0);
  y=analogRead(A3);
  z=analogRead(A5);
  Serial.print(x);
  Serial.print("  ");
  Serial.print(y);
  Serial.print("  ");
  Serial.println(z);
  //Serial.print("");
  delay(500);
}
