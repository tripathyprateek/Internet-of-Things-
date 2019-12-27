#include<SPI.h>
#include<WiFi.h>

char ssid[]="OnePlus™";
char password[]= "no password";
IPAddress gateway,ip;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Attempting to connect to network to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.println("...");
    delay(300);  
  }
  Serial.println("\n You are now connected to the network");
  
  while(WiFi.localIP()==INADDR_NONE){
    Serial.println("...");
    delay(300);
  }
  ip = WiFi.localIP();
  Serial.println("Your IP address is :");
  Serial.println(ip);
  gateway = WiFi.gatewayIP();
  Serial.println("YOUR GATEWAY IP ADDRESS");
  Serial.println(gateway);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  
}
