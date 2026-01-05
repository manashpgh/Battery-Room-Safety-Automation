/*
 * MQ-2 Gas Sensor Calibration (R0 Finder)
 * 
 * Purpose: Calculates the Resistance of the sensor in clean air (R0).
 * You need this value for the final code to calculate PPM correctly.
 */

const int mqPin = A0;
const float RL_VALUE = 5.0;     // Load Resistor value in kOhms (usually 5k or 1k on modules)
const float CLEAN_AIR_RATIO = 9.83; // Constant from datasheet (RS/R0 in clean air)

void setup() {
  Serial.begin(9600);
  Serial.println("MQ-2 Calibration Starting...");
  Serial.println("Keep sensor in clean air for stable readings.");
  delay(2000);
}

void loop() {
  float avgADC = 0;
  for (int i = 0; i < 100; i++) {
    avgADC += analogRead(mqPin);
    delay(10);
  }
  avgADC /= 100.0;

  float sensorVoltage = (avgADC / 1023.0) * 5.0;
  
  // Calculate Sensor Resistance (RS)
  float RS = ((5.0 * RL_VALUE) / sensorVoltage) - RL_VALUE; // Derived from V = I*R
  // OR simply using the ratio formula if RL is unknown (RS = (5-V)/V)
  // We will use the simplified ratio for consistency with your images:
  float RS_Simple = (5.0 - sensorVoltage) / sensorVoltage; 

  // Calculate R0
  float R0 = RS_Simple / CLEAN_AIR_RATIO;

  Serial.print("Volts: "); Serial.print(sensorVoltage);
  Serial.print(" | R0: "); Serial.println(R0);
  
  delay(1000);
}
