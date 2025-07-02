# 🌿 IoT Smart Plant Watering System

An IoT-based smart irrigation system designed to automate the watering process based on real-time soil moisture levels. It uses an ESP8266 NodeMCU microcontroller, a soil moisture sensor, and the Blynk IoT platform to control a water pump automatically or manually via a smartphone.

---

## 📌 Project Overview

- 🚿 **Automatic and manual pump control**
- 🌱 **Real-time soil moisture monitoring**
- 📲 **Remote control via Blynk mobile app**
- 🔔 **Low moisture alerts via notifications**
- 💧 **Optimized water usage for plant health**

---

## 🧰 Hardware Components

| Component              | Quantity | Operating Voltage | Notes                            |
|------------------------|----------|-------------------|----------------------------------|
| ESP8266 NodeMCU        | 1        | 3.3V              | Wi-Fi-enabled microcontroller    |
| Soil Moisture Sensor   | 1        | 3.3V–5V           | Analog output to A0 pin          |
| Relay Module           | 1        | 5V                | Controls the water pump          |
| Water Pump             | 1        | 6V–12V            | Submersible pump recommended     |
| Jumper Wires           | As needed | —                | For circuit connections          |
| Power Supply           | 1        | —                 | USB or external 5V adapter       |

---

## 🔧 Software & Tools

- Arduino IDE
- Blynk IoT App (Android/iOS)
- Blynk Library
- ESP8266 Board Manager
- Blynk Template ID and Auth Token

---

## 📱 Blynk Virtual Pins Used

| Feature                   | Virtual Pin |
|---------------------------|-------------|
| Moisture Display          | V2          |
| Manual Pump Control       | V3          |
| Auto/Manual Mode Switch   | V4          |
| Low Moisture Notification | Event Name: `lowmoisture` |

---

## 🔌 Circuit Overview

- **Soil Sensor →** A0 pin of ESP8266
- **Relay IN →** D0 pin of ESP8266
- **Relay VCC/GND →** 5V/GND
- **Pump →** Connected via relay
- **ESP8266 →** Powered via USB or 5V

---

## 🚀 How It Works

1. Soil moisture is continuously read using the sensor.
2. If **Auto Mode** is ON:
   - Pump is turned ON when moisture falls below threshold.
   - Pump turns OFF when moisture is sufficient.
3. If **Manual Mode** is selected:
   - User controls pump using switch (V3) from the Blynk app.
4. Low moisture alerts are sent via Blynk notifications.

---

## 🧪 Future Scope

- Integration with weather APIs
- Solar-powered system
- Zone-based moisture control for large farms
- Machine learning for irrigation prediction

---

## 🛡 License

This project is licensed under the [MIT License](LICENSE).

---

## 👨‍💻 Author

**Saurav Satpute**  
GitHub: [@sgsatpute](https://github.com/sgsatpute)  
Email: sgsatpute2005@gmail.com

---

