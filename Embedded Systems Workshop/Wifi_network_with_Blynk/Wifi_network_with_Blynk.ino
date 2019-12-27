/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example shows how to use Arduino WiFi shield
 * to connect your project to Blynk.
 *
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi.h>
#include <BlynkSimpleEnergiaWiFi.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "vF3DejA4qCv-aGwwA0Rbuc7h7-udEcS-";

// Your WiFi credentials
char ssid[] = "One Plus";
char pass[] = "no password";        // Set to "" for open networks

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(RED_LED,OUTPUT);
  digitalWrite(RED_LED,LOW);
  
}
  BLYNK_WRITE(V0)
  {
    BLYNK_LOG("GOt a value % s", param.asStr());
    int i= param.asInt();
    Serial.println(i);
    if(i==1)
      digitalWrite(RED_LED,HIGH);
    else if(i==0)
      digitalWrite(RED_LED,LOW);s
  }
  //storage servicee
  //private network cloud 
  

void loop()
{
  Blynk.run();
}

