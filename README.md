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
   - **`TEMP_WARNING` or higher**: Red LED is activated as an initial warning.  
   - **`TEMP_CRITICAL` or higher**: A buzzer starts beeping, signaling immediate action is needed.  
   - Configurable for progressive alerts as the temperature rises.  

---

## 🛠️ Used Components  
- 1 x [NodeMCU ESP8266 Development Board With 0.96 Inch OLED Display CH340G ESP-12F WiFi Module](https://s.click.aliexpress.com/e/_op1ER6B)
- 1 x [Temperature sensor: DHT11 Module](https://s.click.aliexpress.com/e/_oFnJr6f)
- 1 x Red LED  
- 1 x Piezoelectric buzzer  
- Jumper wires and resistors  
- Power supply or USB cable for Arduino  

---

## 🚀 How to Use  
1. Clone the repository:  
   ```bash
   git clone https://github.com/fbvictorhugo/hot_spot_watcher.git
   ```
2. Assemble the circuit as per the schematic provided in the repository.
3. Upload the code to the Arduino using the official IDE.
4. Place the Arduino in the space to be monitored and connect it to the device via USB (or external power source).

---

## 📝 Configuration
Temperature thresholds can be adjusted directly in the code:

Warning threshold: `TEMP_WARNING = 34`;

Critical threshold: `TEMP_CRITICAL = 38`;

--- 

## 📚 Contributions
This is an open-source project, and contributions are welcome! Feel free to open an issue or submit a pull request.

--- 

## 🖼️ Images

![HotSpotWatcher](/images/project.gif)

|![](/images/front_off.png)|![](/images/front_on.png) |![](/images/back.png) |
|-|-|-|