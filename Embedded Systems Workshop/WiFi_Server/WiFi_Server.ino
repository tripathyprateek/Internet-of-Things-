#include <SPI.h>
#include <WiFi.h>, 

char ssid[] = "OnePlus 3T";
char password[] = "9518993767";

IPAddress ip(192, 168, 1, 122);
unsigned char data = 0;
WiFiServer server(9999);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  Serial.print ("Attempting to connect to ");
  Serial.println (ssid);

  WiFi.config (ip);
  WiFi.begin (ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println ("...");
    delay (300);
  }

  Serial.print ("\nYou're connected to the Network");
  Serial.print ("\nWaiting for an IP Address");

  while (WiFi.localIP() == INADDR_NONE) {
    Serial.println ("...");
    delay (300);
  }

  Serial.print ("\nIP Address Obtained");
  
  printWiFiStatus();

  server.begin();  
}

void loop() {
  // put your main code here, to run repeatedly: 
  WiFiClient client = server.available();
  
  if (client == true) {
    server.print ("Hello\n");
    delay (500);
  }
}

void printWiFiStatus () {
  Serial.print ("\nSSID: ");
  Serial.println (WiFi.SSID());

  IPAddress IP = WiFi.localIP();
  Serial.print ("\nIP Address: ");
  Serial.println (IP);
}
