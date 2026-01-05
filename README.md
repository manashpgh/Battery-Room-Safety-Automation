Smart Battery Room Exhaust & Ventilation System

Embedded Systems | Mechatronics | Control & Automation Project

Project Overview

Battery rooms in industrial facilities are prone to hydrogen gas accumulation, overheating, and humidity rise, which can lead to fire hazards, battery degradation, and safety risks.
This project presents a smart automated exhaust and ventilation system that continuously monitors environmental parameters and autonomously controls ventilation, cooling, and vent opening mechanisms.

The system integrates sensors, embedded control, mechanical linkage design, and calibration-driven signal conditioning to create a reliable safety automation solution.

🎯 Objectives

Detect hazardous gas/smoke buildup in battery rooms
Monitor temperature and humidity continuously
Automatically open ventilation vents using a mechanical linkage
Activate forced exhaust and cooling under unsafe conditions
Demonstrate sensor calibration, noise filtering, and system integration

⚙️ System Architecture

The system consists of three major layers:

Sensing Layer:

MQ-2 Gas Sensor (smoke / hydrogen detection)
DHT11 Humidity Sensor
Copper–Iron Thermocouple (temperature sensing)

Control Layer:

Arduino-based decision logic
Threshold-based safety control
Servo and actuator control

Actuation Layer:

4-bar linkage mechanism for vent opening
12V DC exhaust fan
Peltier Cooling Module (TEC-based) with heat sink and forced-air cooling fan

🔧 Hardware Components:

Arduino (microcontroller)
MQ-2 Gas Sensor
DHT11 Temperature & Humidity Sensor
Homemade Cu–Fe Thermocouple
SG90 Servo Motor
12V DC Exhaust Fan
Peltier Cooling Module (TEC-based)
4-Bar Linkage (acrylic-based mechanical design)
Power supply & signal conditioning components

🧠 Working Principle:

Sensors continuously monitor gas concentration, temperature, and humidity.
Sensor signals are processed by the Arduino controller.

When predefined thresholds are exceeded:
The servo actuates a 4-bar linkage to open the ventilation vent.
The exhaust fan is switched ON.
When temperature exceeds the safe threshold, the Peltier module is activated along with an attached heat sink and cooling fan to ensure effective heat dissipation and prevent thermal runaway.
A low-pass RC filter is used to reduce noise in thermocouple readings, improving temperature measurement stability.
The system operates autonomously without human intervention.

📐 Mechanical Design (CAD)

Designed a 4-bar linkage mechanism to convert servo rotation into smooth vent opening motion
Ensured mechanical stability and controlled displacement
CAD drawings and mechanism views are provided in the /CAD folder

📊 Sensor Calibration & Signal Conditioning

Accurate temperature measurement was critical due to the use of a homemade thermocouple.

Calibration methodology:

Multiple reference methods (hot water, candle flame, comparative thermistor readings)
Identified noise and signal drift issues
Implemented an RC low-pass filter to suppress high-frequency noise
Generated calibration curves and validated sensor behavior
All calibration plots and analysis are available in the /Calibration folder.
This calibration-driven approach demonstrates real-world engineering practices beyond basic sensor usage.

💻 Software & Code

Developed Arduino firmware for:

Sensor data acquisition
Threshold-based decision logic
Servo motor control
Exhaust fan and Peltier activation
Modular code structure for easy debugging and testing
Source code is available in the /Code folder.

📁 Repository Structure
├── CAD/            → Mechanical design and linkage drawings
├── Calibration/    → Sensor calibration graphs & filtering analysis
├── Code/           → Arduino source code
├── Hardware/       → Circuit diagrams & system architecture
├── Images/         → Prototype and experimental setup photos
└── README.md

🧪 Prototype & Validation

Fully assembled working prototype

Verified sensor response under:

Smoke exposure
Temperature rise
Environmental changes
Successfully demonstrated automated vent opening and exhaust operation
Thermal behavior of the Peltier module was validated by operating it with a heat sink and fan to maintain stable temperature gradients.
Images of the prototype are available in the /Images folder.

🚀 Key Engineering Skills Demonstrated

Embedded systems programming (Arduino, C)
Sensor integration & calibration
Signal conditioning & noise filtering
Mechatronics system design
Mechanical linkage modeling
Safety-critical automation
Hardware–software integration
Practical thermal management using Peltier module with forced convection cooling

🔮 Future Enhancements

Replace thermocouple with industrial-grade temperature sensor
Implement PID-based thermal control
Add ESP32 for cloud-based monitoring (IoT)
Include gas concentration logging and alerts

👤 Author

Manash Pratim Ghosh
M.Tech — Mechatronics 
GitHub: [your GitHub profile link]

📄 License

This project is licensed under the MIT License.
