#include <SPI.h>
#include <WiFi.h>, 

char ssid[] = "OnePlus 3T";
char password[] = "9518993767";

uint16_t port = 5555;
IPAddress server(192, 168, 433, 122);
char b[100];
int k;

WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  WiFi.begin (ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println ("...");
    delay (300);
  }

  Serial.print ("\nWiFi connected");
  Serial.print ("\nAttempting to connect to Server"); 

  while (!client.connect (server, port)) {
    Serial.print ("\nConnected to Server");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (client.available()) {
    char c = client.read();
    Serial.print (c);

    if (c == 1)
      digitalWrite (RED_LED, HIGH);
    else
      digitalWrite (RED_LED, LOW);
  }

  if (Serial.available ()) {
    for (k = 0; b[k]; k++) {
      b[k] = ' ';
    }
    Serial.readBytes (b, 100);
    Serial.println (b);
    client.println (b);
    delay (500);
  }
}
