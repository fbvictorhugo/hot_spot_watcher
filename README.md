# HotSpotWatcher-Arduino  
**HotSpotWatcher-Arduino** is a simple and efficient project designed to monitor and alert about overheating in confined spaces, such as cabinets where electronic devices like gaming consoles are installed.  

Using an **Arduino**, temperature sensors, and basic components, the system provides real-time temperature monitoring, lighting up an LED and triggering sound alerts when predefined temperature thresholds are reached.  

---

## 🔥 Problem Addressed  
Gaming consoles and other devices are often placed in cabinets or poorly ventilated spaces, which can lead to overheating. This may impact performance or even damage the equipment. **HotSpotWatcher-Arduino** helps prevent this by alerting you about critical temperatures, enabling proactive action.  

---

## ⚙️ Features  
1. **Temperature Monitoring**:  
   - Detects and displays real-time ambient temperature.  

2. **Visual and Sound Alerts**:  
   - **30°C (86°F)**: Red LED is activated as an initial warning.  
   - **38°C (100.4°F) or higher**: A buzzer starts beeping, signaling immediate action is needed.  
   - Configurable for progressive alerts as the temperature rises.  

---

## 🛠️ Required Components  
- 1 x Arduino board (e.g., Uno, Nano, etc.)  
- 1 x Temperature sensor (e.g., DHT11 or LM35)  
- 1 x Red LED  
- 1 x Piezoelectric buzzer  
- Jumper wires and resistors  
- Power supply or USB cable for Arduino  

---

## 🚀 How to Use  
1. Clone the repository:  
   ```bash
   git clone https://github.com/fbvictorhugo/hot_spot_watcher.git
