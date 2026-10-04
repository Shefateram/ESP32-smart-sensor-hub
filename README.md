# ESP32 Smart Sensor Hub 🔌🤖

An embedded firmware repository containing modular development scripts for an Internet of Things (IoT) environment hub. Built using **VS Code and the PlatformIO IDE ecosystem**, this project focuses on hardware-software interfacing, data collection protocols, and signal processing.

---

### 🛠️ Hardware Component Stack & Peripheral Arrays
* **Microcontroller:** ESP32 Development Board (Dual-core Tensilica Xtensa 32-bit LX6)
* **Environment Sensing:** DHT11 Temperature & Relative Humidity Sensor
* **Light Detection:** LDR (Light Dependent Resistor) Photocell Array
* **Motion & Security Tracking:** PIR (Passive Infrared) Motion Sensor
* **Visual Interfaces:** OLED Display Unit (I2C Protocol Integration)
* **Discrete Component Circuitry:** Potentiometers, Push-Buttons, Resistor Matrices, Breadboard Bus rails, and RGB LED arrays.

---

### 📂 Repository File Mapping & System Architecture

This codebase outlines a progressive developmental pipeline from foundational pin manipulation to multi-sensor hub integration:

* **`ESP32_Blinkin_Test.cpp` / `External LED testing.cpp`:** Basic General Purpose Input/Output (GPIO) digital write routing verification.
* **`PWM_LED.cpp`:** Pulse Width Modulation implementation handling precise variable voltage fading control loops.
* **`button.cpp`:** Hardware-interrupt and hardware logic handling discrete user button state-press detections.
* **`mini_traffic_light.cpp`:** State-machine logic simulating sequential timing arrays for smart traffic control infrastructure.
* **`Dht11_testing.cpp` / `dht11_LED.cpp`:** Parsing 1-Wire serial data buses from the environment sensor and linking outputs to responsive conditional LED alarms.
* **`esp32_testing_code.cpp`:** Development sandbox compiling hardware interactions across multiple sensor test variations.

---

### 🚀 Compilation & Deployment Workflow
Developed utilizing a native C++ build chain compiled within the **PlatformIO IDE** system extension inside **Visual Studio Code**. Peripheral communications run standard library drivers for handling specialized sensor read-cycles and logic loops efficiently.

# ESP32-smart-sensor-hub
My hands-on IoT project using DHT11, LDR, PIR, OLED, etc.
Platform.IO 
VS Code
