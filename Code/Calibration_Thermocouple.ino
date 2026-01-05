/*
 * Cu-Fe Thermocouple Calibration with Smoothing
 * 
 * Purpose: Reads raw ADC values with oversampling and moving average 
 * to provide stable data for regression analysis.
 */

const int tcPin = A1;
const int N = 20;       // Moving average window size
float buffer[N];        // Circular buffer
int indexTC = 0;

// Update these after performing regression analysis
// Formula: Temp = (Slope * RawADC) + Intercept
const float REGRESSION_SLOPE = -1.5306; 
const float REGRESSION_INTERCEPT = 232.5009;

void setup() {
  Serial.begin(9600);
  
  // Initialize buffer
  for(int i = 0; i < N; i++) {
    buffer[i] = 0;
  }
  
  Serial.println("Thermocouple Calibration Mode Started");
}

void loop() {
  // 1. Oversampling: Take 50 readings and average them
  long total = 0;
  for(int i = 0; i < 50; i++) {
    total += analogRead(tcPin);
    delay(2);
  }
  float raw = total / 50.0;

  // 2. Moving Average Filter
  buffer[indexTC] = raw;
  indexTC = (indexTC + 1) % N;

  float avgADC = 0;
  for(int i = 0; i < N; i++) {
    avgADC += buffer[i];
  }
  avgADC /= N;

  // 3. Convert to Temperature
  float T = (REGRESSION_SLOPE * avgADC) + REGRESSION_INTERCEPT;

  Serial.print("Raw ADC: ");
  Serial.print(avgADC);
  Serial.print(" | Temperature (C): ");
  Serial.println(T);

  delay(300);
}
