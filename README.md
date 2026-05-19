# 📌 Project Overview

The Automatic Water Pumping System is an Arduino-based smart water management system designed to automatically monitor and control the water level in a storage tank. The project uses an HC-SR04 Ultrasonic Sensor to measure the water level and automatically controls the water pump through a relay module.
An OLED display provides real-time monitoring information such as water level percentage, pump status, and operating mode. The system supports both Automatic Mode and Manual Mode for efficient water management.

# 🚀 Features

- Automatic Water Level Monitoring
- Automatic Pump ON/OFF Control
- Manual Pump Operation
- OLED Display Monitoring
- Overflow Prevention
- Dry Run Protection
- User Calibration Support
- Low-Cost Automation System

# 🛠 Components Used

| Arduino UNO 
| HC-SR04 Ultrasonic Sensor 
| SSD1306 OLED Display 
| Relay Module 
| DC Water Pump 
| Toggle Switch 
| Breadboard 
| Jumper Wires 
| Power Supply 

# ⚙️ Working Principle

1. The ultrasonic sensor measures the water level inside the tank.
2. Arduino calculates the water level percentage.
3. In Automatic Mode:
   - Pump turns ON below 30%
   - Pump turns OFF above 85%
4. In Manual Mode:
   - User manually controls the pump using a button.
5. OLED display shows:
   - Water Level Percentage
   - Pump Status
   - Current Mode
   - Calibration Value
  
# 🔌 Pin Connections

Ultrasonic Trigger | D2 |
Ultrasonic Echo | D3 |
Push Button | D10 |
Mode Switch | D11 |
Relay Module | D13 |
OLED SDA | A4 |
OLED SCL | A5 |



# 💻 Software Requirements

- Arduino IDE
- Adafruit GFX Library
- Adafruit SSD1306 Library

# 🔄 System Flow

1. Measure water level
2. Calculate water percentage
3. Check operating mode
4. Control relay and pump
5. Display data on OLED
6. Repeat continuously

# 📈 Applications

- Home Water Tank Automation
- Agricultural Irrigation Systems
- Industrial Water Monitoring
- Smart Water Management
- Automated Pump Control

# 🔮 Future Improvements

- IoT Monitoring using ESP32
- Mobile App Integration
- GSM Alert Notifications
- Cloud Data Logging
- Solar Powered System
- Automatic Fault Detection
