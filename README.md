# 🚁 Arduino-Dual-Drone Project

> **A lightweight two-motor drone system with live stabilization using MPU6050 and Bluetooth control via HC-05. Modular, expandable, and student-built with love.**

---

## 📖 Overview

This project is a micro drone built on **Arduino Uno** featuring:
- **2 Brushless Motors + ESCs**
- **MPU6050 Gyroscope Sensor** for tilt detection and stabilization
- **HC-05 Bluetooth module** for remote control via custom Android app
- Modular software structure using **PlatformIO** and C++

---

## 🎯 Features

- 🛠️ **Manual control via Bluetooth (WASD control scheme)**
- 📈 **Automatic tilt correction using MPU6050**
- ✨ **Clean modular code split into multiple `.cpp` and `.h` files**
- 📡 **HC-05 Bluetooth receiver with dedicated communication module**
- 🔄 **ESC control using Servo library (PWM-based)**
- ⚙️ **Custom speed and threshold configuration**

---

## 🧩 Folder Structure

```bash
Arduino-Dual-Drone/
├── include/          
│   ├── drone.h
│   ├── sensor.h
│   └── comm.h
├── src/
│   ├── main.cpp
│   ├── drone.cpp
│   ├── sensor.cpp
│   └── comm.cpp
├── platformio.ini
└── README.md
```

---

## 🔧 Hardware Structure

**Components:**
- Arduino Uno (CH340)
- 2x A2212 1000KV Brushless Motor
- 2x 30A ESC with BEC
- 2x Pairs of 1045L/R Propellers for brushless motors (CW & CCW)
- 1x MPU6050 (Gyroscope & Accelerometer)
- HC-05 Bluetooth Module
- Li-Po 7.4V 1500mAh 2S Battery (You can upgrade to Li-Po 3S (11.1V) Battery
- Jumper Cables
- Custom Impraboard Frame
  
---

## ⚡ Wiring Layout

| Component              | Arduino Pin | Note                                             |
| :--------------------- | :---------- | :----------------------------------------------- |
| Motor Left ESC Signal  | D6          | Controlled via Servo PWM                         |
| Motor Right ESC Signal | D5          | Controlled via Servo PWM                         |
| MPU6050 SDA            | A4          | I2C communication                                |
| MPU6050 SCL            | A5          | I2C communication                                |
| HC-05 TX               | RX (D0)     | Bluetooth serial receive                         |
| HC-05 RX               | TX (D1)     | Bluetooth serial transmit                        |
| Li-Po Battery          | ESC T-plug  | ESC powers motors and BEC provides 5V to Arduino |

⚠️ Note:
- Motors connected directly to ESCs
- ESC’s BEC powers Arduino via 5V and GND
- Ensure to calibrate ESC before first flight

📊 Optional ASCII/Diagram:
```
[HC-05]        [MPU6050]
   |               |
 TX/RX          SDA/SCL
   |               |
  [Arduino UNO CH340]
    |       |       |
  D6 ESC  D5 ESC    5V/GND (from ESC BEC)
    |       |
  Motor1  Motor2
```

---
## ⚙️ Dependencies

- Servo (by Arduino)
- Wire (by Arduino)
- Adafruit_MPU6050 (v2.0.0 or newer)

(installed via PlatformIO lib_deps in platformio.ini)

---

## 👨‍💻 Contributors
| Name                   | Role                                   |
| :--------------------- | :------------------------------------- |
| Bernardus (me 😎)      | Project Lead / Programmer / Repo Owner |
| Austin | Programmer / Hardware Builder / Hardware Wiring                       |
| Christopher  | Hardware Wiring |
| Hugo | Hardware Builder / Hardware Wiring |
| Joyce K. | Programmer |
| Isaac Primo Djojo | Hardware Builder / Hardware Wiring |
| Matthew Filbert Johari | Hardware Builder |

---

## 📈 Goals
- Build a polished, working student drone
- Learn modular embedded system programming
- Leave behind a clean, reusable codebase for future students
- Earn big teacher respect points 😤

---

## 📸 Demo (To be added after testing)

> Documentation photos, test footage, and performance stats coming soon.

---

## 🚀 Big Projects Start Small

*Remember ! Big Projects Start From Small Dreams ! ✨🌠"*


