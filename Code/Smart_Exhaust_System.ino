/*
 * Smart Exhaust System - Final Firmware (PPM Version)
 */

#include <Servo.h>
#include <DHT.h>

// --- Pin Definitions ---
#define PELTIER_PIN 7
#define PELTIER_FAN_PIN 2
#define FAN_PIN A2
#define THERMOCOUPLE_PIN A1
#define MQ2_PIN A0
#define HUMIDITY_PIN 3
#define SERVO_PIN 6

// --- System Thresholds ---
#define TEMP_THRESHOLD 45.0     // Degrees Celsius
#define HUMIDITY_THRESHOLD 50   // Relative Humidity %
#define GAS_PPM_THRESHOLD 100   // Threshold in PPM (e.g., 100-200 for warning)

// --- Actuator Settings ---
#define FAN_SPEED 255
#define SERVO_CLOSED 0
#define SERVO_OPEN 180

// --- Calibration Constants ---
#define THERMO_A -1.5306
#define THERMO_B 232.5009

// --- MQ-2 Gas Sensor Constants ---
// REPLACE THIS VALUE with the R0 you found in the calibration sketch!
float R0 = 10.0;  

// Curve constants for LPG/Smoke (Standard MQ-2 Curve)
const float MQ2_A = 574.25; 
const float MQ2_B = -2.222; 

// --- Object Initialization ---
#define DHT_TYPE DHT11
DHT dht(HUMIDITY_PIN, DHT_TYPE);
Servo ventServo;

// --- Global Variables ---
float temperature = 0;
float humidity = 0;
float gasPPM = 0;

bool ventActive = false;
bool fanActive = false;
bool peltierActive = false;

void setup() {
  Serial.begin(9600);

  pinMode(PELTIER_PIN, OUTPUT);
  pinMode(PELTIER_FAN_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  
  ventServo.attach(SERVO_PIN);
  ventServo.write(SERVO_CLOSED);

  dht.begin();

  // Ensure OFF state
  digitalWrite(PELTIER_PIN, LOW);
  digitalWrite(PELTIER_FAN_PIN, LOW);
  analogWrite(FAN_PIN, 0);

  Serial.println("System Started - PPM Mode");
}

void loop() {
  readSensors();
  processVentilation();
  processHumidity();
  printStatus();
  
  delay(1000);
}

void readSensors() {
  // 1. Thermocouple (Smoothed)
  long thermoSum = 0;
  for(int i=0; i<20; i++) {
    thermoSum += analogRead(THERMOCOUPLE_PIN);
    delay(2);
  }
  float thermoAvg = thermoSum / 20.0;
  temperature = (THERMO_A * thermoAvg) + THERMO_B;

  // 2. DHT11 Humidity
  float h = dht.readHumidity();
  if (!isnan(h)) humidity = h;

  // 3. MQ-2 Gas in PPM
  float mq_adc = analogRead(MQ2_PIN);
  float sensor_volt = (mq_adc / 1023.0) * 5.0;
  
  // Calculate RS (Sensor Resistance)
  // Note: Using simplified RS calc to match calibration method
  float RS = (5.0 - sensor_volt) / sensor_volt;
  
  // Calculate Ratio
  float ratio = RS / R0;
  
  // Calculate PPM using Power Law: PPM = a * (ratio)^b
  gasPPM = MQ2_A * pow(ratio, MQ2_B);
}

void processVentilation() {
  // Trigger if Temp is high OR Gas PPM is high
  bool needVentilation = (temperature > TEMP_THRESHOLD) || (gasPPM > GAS_PPM_THRESHOLD);

  if (needVentilation) {
    if (!ventActive) {
      ventServo.write(SERVO_OPEN);
      ventActive = true;
    }
    if (!fanActive) {
      analogWrite(FAN_PIN, FAN_SPEED);
      fanActive = true;
    }
  } else {
    // Hysteresis: Only turn off if significantly below threshold to prevent flapping
    // (e.g., Temp < Threshold - 2 AND Gas < Threshold - 10)
    if (temperature < (TEMP_THRESHOLD - 2.0) && gasPPM < (GAS_PPM_THRESHOLD - 10.0)) {
      if (ventActive) {
        ventServo.write(SERVO_CLOSED);
        ventActive = false;
      }
      if (fanActive) {
        analogWrite(FAN_PIN, 0);
        fanActive = false;
      }
    }
  }
}

void processHumidity() {
  if (humidity > HUMIDITY_THRESHOLD) {
    if (!peltierActive) {
      digitalWrite(PELTIER_PIN, HIGH);
      digitalWrite(PELTIER_FAN_PIN, HIGH);
      peltierActive = true;
    }
  } else {
    // Humidity Hysteresis (Wait until 3% below threshold)
    if (humidity < (HUMIDITY_THRESHOLD - 3.0)) {
      if (peltierActive) {
        digitalWrite(PELTIER_PIN, LOW);
        digitalWrite(PELTIER_FAN_PIN, LOW);
        peltierActive = false;
      }
    }
  }
}

void printStatus() {
  Serial.print("Temp: "); Serial.print(temperature); Serial.print(" C | ");
  Serial.print("Hum: "); Serial.print(humidity); Serial.print(" % | ");
  Serial.print("Gas: "); Serial.print(gasPPM); Serial.print(" PPM");
  
  Serial.print(" [Vent: "); Serial.print(ventActive ? "ON" : "OFF");
  Serial.print("] [Peltier: "); Serial.print(peltierActive ? "ON" : "OFF");
  Serial.println("]");
}
