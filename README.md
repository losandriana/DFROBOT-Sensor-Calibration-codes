# DFROBOT-Sensor-Calibration-codes


---

## Calibration Code Overview

This repository includes working Arduino sketches for calibrating and reading EC, pH, and turbidity sensors. Below is a breakdown of how each implementation works.

---

### EC Sensor (`ec_calibration.cpp`)

**Pin:** A3  
**Calibration Solution:** 12.88 mS/cm  

#### How it Works
- Waits for user input via Serial Monitor before starting calibration
- Takes 20 analog samples and averages them
- Computes a calibration factor:

  calibrationFactor = 12.88 / rawValue

- Uses this factor to convert raw ADC readings into conductivity (mS/cm)

#### Output Example
- Raw sensor value
- Calculated conductivity (mS/cm)

#### Notes
- If raw value = 0, calibration is skipped (division safety)
- Assumes linear relationship between ADC value and conductivity

---

### pH Sensor (`ph_calibration.cpp`)

**Pin:** A2  

#### How it Works
- Collects 40 samples continuously
- Applies a filtering function (`avergearray`) that removes min/max outliers
- Converts ADC → voltage:

  voltage = avg * 5.0 / 1024

- Then it converts voltage → pH:

  pH = 3.5 * voltage + Offset

#### Key Parameters
- `Offset = 2.65` → calibration constant (adjust this!)
- Sampling interval: 20 ms
- Print interval: 800 ms

#### Output Example
- Voltage (V)
- pH value

#### Notes
- Uses basic linear approximation (not full 2-point calibration)
- For better accuracy:
  - Calibrate using pH 4, 7, 10 buffers
  - Adjust slope (3.5) and offset accordingly

---

### Turbidity Sensor (`turbidity_calibration.cpp`)

**Pin:** A1  

#### How it Works
- Reads raw analog value from sensor
- Converts to voltage:

  voltage = sensorValue * (5.0 / 1024.0)

- Outputs:
  - Raw ADC value
  - Voltage

#### Output Example
Raw ADC: 640 | Voltage: 3.12

#### Notes
- No direct NTU conversion implemented
- You must create your own calibration curve:
  - Measure clear water (low NTU)
  - Measure known turbidity samples
  - Fit equation (linear or polynomial)

---

## ⚠️ Important Observations

- The sketches are **independent** and should be uploaded **one at a time**
- There are **multiple `setup()` and `loop()` functions**, so combining them directly will cause errors
- All sensors assume:
  - 5V reference
  - 10-bit ADC (0–1023)

---

## Suggested Improvements

- Store calibration factors in EEPROM
- Add temperature compensation (especially for EC)
- Implement multi-point calibration for pH
- Convert turbidity voltage → NTU using regression
- Merge into a single modular sketch

---

