const int EC_SENSOR_PIN = A3;
const float CALIBRATION_SOLUTION = 12.88;

int rawValue = 0;
float conductivity = 0.0;
float calibrationFactor = 0.0;

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Place the sensor in the calibration solution (12.88 mS/cm).");
  Serial.println("Press any key to continue...");
  while (!Serial.available()) {}

  // Take multiple samples and average
  long sum = 0;
  const int samples = 20;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(EC_SENSOR_PIN);
    delay(50);
  }
  rawValue = sum / samples;
  
  Serial.print("Average raw sensor value: ");
  Serial.println(rawValue);

  if (rawValue == 0) {
    Serial.println("Error: raw value is zero, cannot calibrate!");
    calibrationFactor = 0.0;  // Or handle error appropriately
  } else {
    calibrationFactor = CALIBRATION_SOLUTION / rawValue;
    Serial.print("Calibration factor: ");
    Serial.println(calibrationFactor);
  }

  Serial.println("Calibration complete! You can now start measuring conductivity.");
}

void loop() {
  rawValue = analogRead(EC_SENSOR_PIN);
  
  if (calibrationFactor == 0.0) {
    Serial.println("Calibration factor is zero, conductivity calculation skipped.");
    delay(1000);
    return;
  }

  conductivity = rawValue * calibrationFactor;

  Serial.print("Raw EC Sensor Value: ");
  Serial.print(rawValue);
  Serial.print("\tCalculated Conductivity: ");
  Serial.print(conductivity);
  Serial.println(" mS/cm");

  delay(1000);
}

