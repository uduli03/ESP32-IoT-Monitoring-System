# ESP32-IoT-Monitoring-System
ESP32-based IoT system for monitoring temperature, humidity, and light intensity with cloud visualization

**Author:** Uduli Gunathilake 

**Tech Stack:** ESP32, DHT22, LDR, OLED, Arduino IoT Cloud, Arduino IDE  

## Project Story

This project started as a simple experiment to monitor temperature, humidity, and light, but for me it became a journey full of challenges, learning, and discovery.

I wanted to **build a smart IoT system** using ESP32 that could:
- Monitor temperature and humidity  
- Track light conditions  
- Display data locally on an OLED  
- Send live updates to Arduino IoT Cloud for visualization

Along the way, I faced multiple challenges:
1. Getting the ESP32 to connect reliably to Wi-Fi  
2. Displaying the data correctly on the OLED screen  
3. Integrating IoT Cloud variables (temperature, humidity, light)  
4. Debugging sensor readings and serial issues  

Every challenge taught me something new about hardware-software integration, IoT cloud, and debugging.

---

## Features

- Live temperature & humidity readings  
- Light detection with LDR (Bright / Dark)  
- OLED display showing real-time data  
- Charts on Arduino IoT Cloud for temperature and humidity  
- Gauge for light intensity  
- Full integration with Arduino IoT Cloud

---
## Photos / Diagrams
![IMG_2085](https://github.com/user-attachments/assets/439651fc-6031-4930-bbff-d5e0d5c3d940)
![IMG_2087](https://github.com/user-attachments/assets/16be9c09-7e67-4472-b48f-304613d3d7e5)
![IMG_2089](https://github.com/user-attachments/assets/a8a8fac1-63f1-4a3f-b506-9e22b00848e0)

<img width="1440" height="900" alt="Screenshot 2026-03-23 at 16 05 53" src="https://github.com/user-attachments/assets/4fbca011-b9d5-4b07-b0c1-c6bb81f70aaf" />
Arduino IoT Cloud chart and gauge

---

## What I Learned

- How to integrate **ESP32 with sensors** and OLED  
- How to use **Arduino IoT Cloud** variables and charts  
- How to debug **serial connection & sensor issues**  
- Best practices for **structuring Arduino code**  
- Importance of **documenting journey, failures, and solutions**

---

## Code Structure

- `ESP32_Sensor.ino` → Main Arduino sketch  
- `thingProperties.h` → IoT Cloud properties & callbacks  

You can explore the code in the code folder to see how each sensor is read and visualized.  

---
