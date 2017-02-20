const int SENSORPIN = A0;
float BASELINETEMP = 25.0;

void setup() {
  Serial.begin(9600);

  for (int pinNum = 2; pinNum < 5; pinNum++) {
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }

  BASELINETEMP = (((analogRead(SENSORPIN) / 1024.0) * 5.0) - 0.5) * 100;
}

void loop() {
  int sensorVal = analogRead(SENSORPIN);

  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if (temperature < BASELINETEMP) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= BASELINETEMP + 2 && temperature < BASELINETEMP + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= BASELINETEMP + 4 && temperature < BASELINETEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (temperature >= BASELINETEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(10);
}
