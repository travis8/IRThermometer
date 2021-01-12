void setup() {
  // put your setup code here, to run once:
  for (int i = 7; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600); //use Serial.print() to print values back
}

//had to write my own power function because pow() from math.h was not precise enough
int power(int base, int exponent){
  if (exponent < 1){
    return 1;
  }
  int value = 1;
  for (int i = 1; i <= exponent; i++){
    value *= base;
  }
  return value;
}

void loop() {
  int numDigits = 7; //how many leds you have
  int maxVal = power(2, numDigits) - 1;
  for (int i = 1; i <= maxVal; i++) {
    
    int iVal = i;
    for (int j = 6; j >= 0; j--){
      float bV = power(2, j);
      int binaryVal = power(2, j);
      if (iVal >= binaryVal){
        digitalWrite(j + 7, HIGH);
        iVal -= binaryVal;
      }
    }
    
    delay(1000);
    
    for (int j = 7; j < 14; j++) {
      digitalWrite(j, LOW);
    }

    delay(500);
  }
}
