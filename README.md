# Smart Battery Room Exhaust & Ventilation System

**Embedded Systems | Mechatronics | Safety-Critical Control & Automation Project**

---

## 📌 Project Overview

Battery rooms in industrial environments are susceptible to **hazardous gas accumulation, temperature rise, and humidity variation**, which can lead to **fire risks, battery degradation, and unsafe operating conditions**.

This project implements a **safety-critical embedded exhaust and ventilation system** that continuously monitors environmental parameters and **autonomously controls ventilation, cooling, and vent actuation mechanisms**.

The system integrates **sensor calibration, signal conditioning, embedded decision logic, power electronics, and mechanical linkage design**, reflecting real-world industrial and safety-focused engineering practices.

---

## 🎯 Functional Objectives

- Detect hazardous **gas / smoke concentration** in battery rooms  
- Continuously monitor **temperature and humidity**  
- Automatically **open ventilation vents** using a servo-driven mechanical linkage  
- Activate **forced exhaust and thermal mitigation** under unsafe conditions  
- Demonstrate **calibration-driven sensing, noise filtering, and system-level integration**

---

## ⚙️ High-Level System Architecture

The system is organized into three functional layers:

### 1️⃣ Sensing Layer
- MQ-2 Gas Sensor (smoke / hydrogen detection)  
- DHT11 Temperature & Humidity Sensor  
- Copper–Iron (Cu–Fe) Thermocouple for temperature measurement  

### 2️⃣ Control Layer
- Arduino-based embedded controller  
- Threshold-based safety decision logic  
- PWM-based actuator control  

### 3️⃣ Actuation Layer
- Servo-driven 4-bar linkage for vent opening  
- 12V DC exhaust fan for ventilation  
- Peltier module for localized cooling  

---

## 🔧 Hardware Components

- Arduino microcontroller  
- MQ-2 gas sensor  
- DHT11 temperature & humidity sensor  
- Custom Cu–Fe thermocouple  
- SG90 servo motor  
- 12V DC exhaust fan  
- Peltier cooling module (TEC-based) with heat sink and forced-air cooling fan  
- 4-bar mechanical linkage (acrylic-based)  
- Power supply and signal conditioning components  

---

## 🧠 System Working Principle

1. Sensors continuously monitor **gas concentration, temperature, and humidity**.  
2. Sensor signals are processed by the embedded controller.  
3. When predefined safety thresholds are exceeded:  
   - The **servo actuates a 4-bar linkage** to open the ventilation vent  
   - The **exhaust fan** is activated  
   - If temperature exceeds safe limits, the **Peltier cooling module** is enabled along with a heat sink and cooling fan to prevent thermal escalation  
4. A **low-pass RC filter** is used to suppress noise in thermocouple readings, ensuring stable and reliable temperature measurement.  
5. The system operates autonomously with **predictable and conservative behavior**, prioritizing safety over continued operation.

---

## 📐 Mechanical Design (CAD)

- Designed a **4-bar linkage mechanism** to convert servo rotation into controlled vent-opening motion  
- Ensured mechanical stability and repeatable displacement  
- CAD models and mechanism drawings are available in the `/CAD` directory  

---

## 📊 Sensor Calibration & Signal Conditioning

Accurate temperature sensing was critical due to the use of a **custom-built thermocouple**.

Calibration methodology included:
- Multiple reference methods (hot water, candle flame, comparative thermistor readings)  
- Identification of noise and signal drift  
- Implementation of an **RC low-pass filter** to reduce high-frequency noise  
- Generation and validation of calibration curves  

All calibration plots and analysis files are available in the `/Calibration` directory.

> This calibration-driven approach reflects real-world engineering practice beyond basic sensor interfacing.

---

## 💻 Embedded Software

- Developed modular Arduino firmware for:
  - Sensor data acquisition  
  - Threshold-based decision logic  
  - Servo motor control  
  - Exhaust fan and Peltier module actuation  
- Code structure emphasizes readability, debuggability, and deterministic behavior  

Source code is available in the `/Code` directory.

---

## 📁 Repository Structure

```
├── CAD/            → Mechanical design and linkage drawings
├── Calibration/    → Sensor calibration graphs & filtering analysis
├── Code/           → Arduino source code
├── Hardware/       → Circuit diagrams & system architecture
├── Images/         → Prototype and experimental setup photos
└── README.md
```
---

## 🧪 Prototype & Validation

- Fully assembled and tested working prototype  
- Verified sensor response under:
  - Smoke exposure  
  - Temperature rise  
  - Environmental variation  
- Successfully demonstrated autonomous vent opening and exhaust operation  
- Thermal behavior of the Peltier module validated using heat sink and forced convection cooling  

Prototype images are available in the `/Images` directory.

---

## 🚀 Key Engineering Skills Demonstrated

- Embedded systems programming (Arduino, C)  
- Sensor integration and calibration  
- Signal conditioning and noise filtering  
- Safety-oriented control logic  
- Mechatronics system design  
- Mechanical linkage modeling  
- Hardware–software co-design  
- Practical thermal management using Peltier modules  

---

## 🔮 Future Enhancements

- Replace thermocouple with industrial-grade temperature sensor  
- Implement PID-based thermal control  
- Integrate ESP32 for remote monitoring and diagnostics  
- Add data logging and alert mechanisms  

---

## 👤 Author

**Manash Pratim Ghosh**  

GitHub: https://github.com/manashpgh  

---

## 📄 Disclaimer

This project was developed as part of academic coursework and independent experimentation, with emphasis on **real-world safety, robustness, and disciplined engineering design**.

