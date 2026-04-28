# DFROBOT-Sensor-Calibration-codes

## Sensor Calibration (Arduino Uno)

This repository contains calibration sketches for analog water quality sensors using the Arduino Uno. Each script helps you obtain accurate readings by calibrating the sensor against known reference solutions.

---

## Supported Sensors

- **Electrical Conductivity (EC) Sensor**  
  Gravity: Lab Grade Analog EC Sensor (K=10)

- **pH Sensor Kit**  
  DFRobot Gravity Lab Grade Analog pH Sensor

- **Turbidity Sensor**  
  Gravity Analog Turbidity Sensor for Arduino

---

## Files

| File | Description |
|------|-------------|
| calibration_ec.cpp | Calibration routine for EC sensor (K=10) |
| ph_calibration.cpp | Calibration routine for pH sensor |
| turbidity_calibration.cpp | Calibration routine for turbidity sensor |

---

## Hardware Requirements

- Arduino Uno  
- Analog sensors listed above  
- Calibration solutions:
  - EC: standard conductivity solutions (e.g., 12.88 mS/cm)
  - pH: buffer solutions (e.g., pH 4.00, 7.00, 10.00)
  - Turbidity: known NTU reference samples or clear/distilled water

---

## Wiring Overview

All sensors use **analog output**:

| Sensor | Arduino Pin |
|--------|------------|
| EC Sensor | A0 |
| pH Sensor | A1 |
| Turbidity Sensor | A2 |

> ⚠️ Ensure proper power supply (typically 5V) and common GND.

---

## How to Use

1. Connect the sensor to the Arduino Uno.
2. Open the corresponding .cpp file in the Arduino IDE.
3. Upload the sketch to your board.
4. Open the Serial Monitor (baud rate defined in code).
5. Follow on-screen instructions for calibration.

---

## Calibration Process

### EC Sensor
- Place probe in a known conductivity solution.
- Wait for readings to stabilize.
- Adjust calibration constant in code until measured value matches reference.

### pH Sensor
- Use at least two-point calibration (pH 7 and pH 4 or 10).
- Record voltage readings at each buffer.
- Update slope and offset values in the code.

### Turbidity Sensor
- Measure voltage in clear water (baseline).
- Compare with known NTU samples if available.
- Fit calibration curve (linear or polynomial depending on accuracy needs).

---

## Notes

- Always rinse probes with distilled water between measurements.
- Allow sensors to stabilize before recording values.
- Temperature can affect readings—consider compensation if high accuracy is required.
- Store calibration constants securely after tuning.

---

## Future Improvements

- Add temperature compensation for EC and pH
- EEPROM storage for calibration values
- Unified calibration interface
- Data logging support


