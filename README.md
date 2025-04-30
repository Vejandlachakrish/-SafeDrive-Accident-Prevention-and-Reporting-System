# Accident Prevention and Reporting System 🚨

An embedded system project developed for our first-year Engineering Clinics that aims to **prevent accidents and provide immediate emergency alerts**.

## 🔧 Features

- **Drowsiness Detection** using Eye Blink Sensor
- **Alcohol Detection** via MQ3 Alcohol Sensor
- **Crash Detection** via Accelerometer/Crash Sensor
- **Overheat Detection** using Temperature Sensor
- **GPS + GSM-based Emergency Reporting** with location sharing
- **Real-time Alerts** with Buzzer and LED

## 🛠️ Components Used

- Arduino UNO
- Eye Blink Sensor
- Alcohol Sensor (MQ3)
- Crash/Impact Sensor
- Temperature Sensor (LM35)
- GPS Module (NEO-6M)
- GSM Module (SIM800L)
- Buzzer, LED, Breadboard, Jumper Wires, Battery Pack

## 🧠 Working

1. **Monitoring Phase**: Sensors constantly check for:
   - Drowsiness (by blink detection)
   - Alcohol (via breath)
   - Temperature of engine
   - Crash or sudden deceleration

2. **Alert Phase**:
   - If any critical event is detected, buzzer and LED alert the driver.
   - In case of a crash, the system sends a location link to emergency services via GSM.

3. **GPS + GSM Communication**:
   - Location is fetched via GPS.
   - Sent to a predefined number using GSM.

## 💻 Code File

The main Arduino sketch is in [vit_accident_prevention_and_reporting_system_oct_23.ino](vit_accident_prevention_and_reporting_system_oct_23.ino). Upload it using Arduino IDE.

## 📷 Circuit Diagram (Optional)

We recommend using Tinkercad or Fritzing to design a visual diagram of your setup.

## 👨‍💻 Team Members

- **Duppala Ganesh Siddhartha** (22BCE8990)
- **Balusu Bhanu Harshith** (22BCE7363)
- **Tadikamalla Koteswara Raju** (22BCE8240)
- **Cheeti Sriman** (22BCE7220)
- **Vejandla Chakrish** (22BCE8330)
- **Kotha Ram Adarsh** (22BCE7603)

## 📚 References

- [GPS Module Datasheet](https://robu.in/product/apm2-5-ublox-neo-m8n-gps-module)
- [Alcohol Sensor](https://amzn.eu/d/08Kbvbj)
- [ESP32 + GSM + Sensors](https://robocraze.com)

## 🚀 Future Enhancements

- Add IoT Dashboard for live tracking
- Integrate voice alerts
- Predictive analytics for accident prevention using AI

---

> 🧾 *Submitted under the guidance of Prof. Tauseef for ECS1002 – Engineering Clinics*
