void setup() {
  // put your setup code here, to run once:
  for (int i = 7; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  //make led blink
  digitalWrite(07, HIGH);
  delay(1000);
  digitalWrite(07, LOW);
  delay(1000);
}
