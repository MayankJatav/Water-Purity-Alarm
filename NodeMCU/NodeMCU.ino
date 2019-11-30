/*#include<SoftwareSerial.h>
SoftwareSerial ser(1,0);
int turbidity;
void setup()
{
  ser.begin(9600);
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop()
{
  if(ser.available()>0)
  {
    Serial.print(ser.read());
  }
  else
  Serial.print("0");
  
  turbidity=analogRead(A0);
  Serial.println(turbidity);
  
}*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "Smartcity";
const char *password = "31253125";

const char *url = "https://waterpurityalarma.000webhostapp.com/mail.php";

void send_request()
{
    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED)
    {
        //Declare an object of class HTTPClient
        HTTPClient http;
        http.begin(url);           //Specify request destination
        int httpCode = http.GET(); //Send the request
        //Check the returning code
        if (httpCode > 0)
        {
            //Get the request response payload
            String payload = http.getString();
            //Print the response payload
            Serial.println(payload);
        }
        //Close connection
        http.end();
    }
}

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.print("Connecting.");
    // Checking Wifi connectivity
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print("Wait ");
    }
    Serial.println("\nConnected !");
    // Sending request
    send_request();
}

void loop()
{
}
