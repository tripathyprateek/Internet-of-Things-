void setup()
{
  //APIs are a litte bit simpler
  
  //register level programming
  
  //ambident c++ programming
  //executing only once
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT); 
}

void loop()
{
  // put your main code here, to run repeatedly:
  //repeatedly
  for(int i= 0; i<5; i++){
    digitalWrite(RED_LED,HIGH);
    delay(500);
    digitalWrite(RED_LED,LOW);
    delay(500);
  }
  for(int j=0; j<2; j++) {
    digitalWrite(GREEN_LED,HIGH);
    delay(500);
    digitalWrite(GREEN_LED,LOW);
    delay(500);
  }
  while(1)
  delay(1000);
}
  
  

