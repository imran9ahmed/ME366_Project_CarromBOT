# 🤖 Project Carrom Bot

An Arduino-based electro-mechanical robotic system designed to **automate the sorting of carrom pucks** using a **4-DOF robotic arm mounted on a mobile cart**.

> 🚀 Developed as part of the course [ME366: Electro-Mechanical System Design and Practice] at **Bangladesh University of Engineering and Technology (BUET)**.

---

## 📽️ Project Demonstrations

- 🎯 **Complete Project Demonstration**: [Watch on YouTube](https://www.youtube.com/watch?v=0QuMNoEQiSg)
- 🧲 **Suction Mechanism Tutorial (by team member)**: [Watch Tutorial](https://www.youtube.com/watch?v=8Wvk7AqxIFw)

---

## 🧠 Objective

To design and implement a robotic system capable of autonomously arranging carrom discs into pre-programmed patterns with high accuracy and repeatability.

---

## 🛠️ Components Used

- Arduino Uno
- MG996R 10kg Servo Motors (×4)
- Nema-17 Stepper Motors (×2)
- DRV8825 Stepper Motor Driver
- L298N Motor Driver
- 12V DC Vacuum Pump
- Suction Cup with Vulcanized Rubber Tip
- Jumper & Electrical Wires
- DC-DC Buck Converter (LM2596)
- 85mm Plastic Wheels
- Custom Wooden and 3D Printed Chassis

---

## 🧩 How It Works

1. Stepper motor moves the bot to the center of the carrom board.
2. Servo motors manipulate the robotic arm to reach a disc.
3. Vacuum pump turns ON to pick up the disc.
4. The arm carries the disc to the target position.
5. Vacuum turns OFF to release it.
6. The bot moves backward to start the next sequence.
7. Repeats the process for all discs.

---

## 🧪 Methodology

- **CAD Design**: SolidWorks for modeling the cart and arm.
- **Fabrication**: Lightweight wooden body and polymer arms (3D printed).
- **Control**: Arduino IDE with pre-programmed sequences for each disc.
- **Motion**: 
  - Stepper motors drive the wheels (for mobility).
  - Servo motors control arm segments (for picking & placing).
  - Vacuum pump uses DC motor to hold discs during transport.

---

## 📊 Results

The robot successfully completed the task of picking and placing all carrom discs in the desired pattern during a live demonstration. The suction mechanism was robust, and servo positioning was accurate.

---

## 🧠 Challenges Faced

- Coordinating 3 different types of motors (servo, stepper, DC)
- Power management and avoiding leakage
- Servo gear slippage during extended use
- Finding a suitable suction cup that provides a good seal
- Frequent recalibration due to mechanical tolerance issues

---

## 🛠️ Future Improvements

- Enhance sorting speed with industrial-grade servo motors
- Introduce **machine learning** to dynamically identify and recreate new patterns
- Upgrade arm design for improved mechanical accuracy and repeatability

---

## 📂 Files Included

- `Poster.png`: Visual overview of the project
- `ProjectCarromBot.pdf`: Full project report with design methodology, components, and results
- `code.ino`: Arduino source code with servo and motor control logic

---

## 👥 Team Members

- **MD. Azmal Bin Adil** (1910085)
- **Nafis Nahian** (1910088)
- **Imran Ahmed** (1910089)
- **Sabit Hasnat Mahee** (1910091)

---

## 📘 Citation

> Project Carrom Bot: An autonomous precision sorting robot prototype  
> [DOI: 10.13140/RG.2.2.15504.42249/2](https://www.researchgate.net/publication/384443774)

---

## 🏫 Department of Mechanical Engineering  
Bangladesh University of Engineering and Technology (BUET)

---

