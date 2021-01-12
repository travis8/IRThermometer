void setup() {
  // put your setup code here, to run once:
  for (int i = 7; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600); //use Serial.print() to print values back for debugging
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

//Hardware: TMP36 - Analog Temperature Sensor
//"The voltage out is 0V at -50°C [-58°F] and 1.75V at 125°C [257°F]."
int readTemp(){
    double voltage = analogRead(A0) * (5.0/1024.0);
    int tempInC = 100 * voltage - 50;
    int tempInF = 180 * voltage - 58;
//    Serial.println(voltage);
//    Serial.println(tempInC);
//    Serial.println(tempInF);
    
    return tempInF;
}

void loop() {
  int numDigits = 7; //how many leds you have
  int maxVal = power(2, numDigits) - 1;
  int temperature = readTemp();

  if (temperature <= maxVal && temperature > 0) {
    for (int i = 6; i >= 0; i--){
      int binaryVal = power(2, i);
      if (temperature >= binaryVal){
        digitalWrite(i + 7, HIGH);
        temperature -= binaryVal;
      }
    }
  }
    
  delay(600000); //read every 10 minutes (1000 = 1second)

  //clear leds
  for (int i = 7; i < 14; i++) {
    digitalWrite(i, LOW);
  }
}
