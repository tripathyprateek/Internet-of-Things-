#include <SPI.h>
#include <WiFi.h>

char ssid[] = "OnePlus 3T";
char password[] = "9518993767";

IPAddress ip, subnet;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  Serial.print ("Attempting to connect to ");
  Serial.println (ssid);

  WiFi.begin (ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println ("...");
    delay (300);
  }

  Serial.print ("\nYou're connected to ");
  Serial.println (ssid);

  while (WiFi.localIP() == INADDR_NONE) {
    Serial.println ("...");
    delay (300);
  }

  ip = WiFi.localIP();
  Serial.print ("\nYou're IP Address: ");
  Serial.println (ip);
  subnet = WiFi.subnetMask();
  Serial.print ("You're Subnet Mask: ");
  Serial.println (subnet);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
