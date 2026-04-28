void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A1);
  float voltage = sensorValue * (5.0 / 1024.0);
  Serial.print("Raw ADC: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage);
  delay(500);
}
