void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (PUSH1, INPUT_PULLUP);
  pinMode (RED_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int i = analogRead (A0);
  Serial.printlm (i);
  delay (1000);

  if (digitalRead (PUSH1)) {
    digitalWrite (RED_LED, LOW);
  }
  else {
    digitalWrite (RED_LED, HIGH);
  }
}
