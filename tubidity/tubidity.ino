void setup()
{
  Serial.begin(9600); //Baud rate: 9600
}
void loop()
{
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
  delay(500);
}

/*void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}
void loop()
{
  Serial.println(analogRead(A0));
  delay(200);
}
*/

/*float volt,ntu;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop()
{
  //Serial.println(analogRead(A0));
  volt = 0;
    for(int i=0; i<800; i++)
    {
        volt += ((float)analogRead(A0)/1023)*5;
    }
    volt = volt/800;
    volt = round_to_dp(volt,1);
    if(volt < 2.5){
      ntu = 3000;
    }else{
      ntu = -1120.4*square(volt)+5742.3*volt-4353.8; 
    }
    Serial.print(volt);
    Serial.print(" Volts    ");
    Serial.print(ntu);
    Serial.println(" NTU");
    delay(500);
}
float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}*/
