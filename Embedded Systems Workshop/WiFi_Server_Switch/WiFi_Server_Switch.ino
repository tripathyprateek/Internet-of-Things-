#include <SPI.h>
#include <WiFi.h>,

char ssid[] = "OnePlus 3T";
char password[] = "9518993767";

IPAddress ip(192, 168, 43, 122);
char b[100];
int k;

WiFiServer server(5555);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);

  pinMode (PUSH1, INPUT_PULLUP);

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

  if (Serial.available ()) {
    for (k = 0; b[k]; k++) {
      b[k] = ' ';
    }
    Serial.readBytes (b, 100);
    Serial.println (b);
    server.println (b);
    delay (500);
  }

  if (client.available()) {
    char c = client.read();
    Serial.print (c);
  }

  if (client == true) {
    int a = digitalRead (PUSH1);
    if (a == 1)
      server.print (1);
  }
}

void printWiFiStatus () {
  Serial.print ("\nSSID: ");
  Serial.println (WiFi.SSID());

  IPAddress IP = WiFi.localIP();
  Serial.print ("\nIP Address: ");
  Serial.println (IP);
}
