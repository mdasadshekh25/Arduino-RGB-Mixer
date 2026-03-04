# Arduino-RGB-Mixer
![b3509174-ae88-4769-b518-f8b48100f608photo png~2](https://github.com/user-attachments/assets/d3fca429-2708-4160-8e82-463e8d667ec8)

An interactive, hardware-based **RGB Color Mixer** built with Arduino. This project allows users to manually dial in any color in the visible spectrum using three potentiometers, providing real-time visual feedback via an RGB LED and data monitoring through the Serial port.

---

## 1. Overview
**Arduino-RGB-Mixer** is an embedded systems project designed to demonstrate the relationship between analog inputs and PWM (Pulse Width Modulation) outputs. By utilizing three independent potentiometers, the user can control the intensity of Red, Green, and Blue channels to create over 16 million color combinations.

## 2. Actual Concept
The core concept is to bridge the gap between **analog input** and **digital output**. 
* **Input:** Rotating physical knobs (potentiometers) changes the voltage sent to the Arduino's Analog-to-Digital Converter (ADC).
* **Processing:** The software translates the 10-bit input (0-1023) into an 8-bit PWM signal (0-255).
* **Output:** Because the system uses a **Common Anode** RGB LED, the logic is inverted—meaning a lower PWM value results in a brighter color.



## 3. Hardware Components
| Component | Quantity | Description |
| :--- | :--- | :--- |
| **Arduino Nano/Uno** | 1 | Main microcontroller for logic and PWM control. |
| **Common Anode RGB LED** | 1 | The light source for color mixing. |
| **Potentiometers (10kΩ)** | 3 | Analog input devices for R, G, and B control. |
| **Resistors (220Ω)** | 3 | Current limiting resistors for LED protection. |
| **Breadboard & Jumper Wires** | 1 | For circuit assembly and prototyping. |

## 4. Pin Configuration
### Inputs (Potentiometers)
| Color Channel | Arduino Pin | Type |
| :--- | :--- | :--- |
| **Red Pot** | A2 | Analog Input |
| **Green Pot** | A1 | Analog Input |
| **Blue Pot** | A0 | Analog Input |

### Outputs (RGB LED)
| Color Channel | Arduino Pin | Type |
| :--- | :--- | :--- |
| **Red LED** | 9 | Digital (PWM) |
| **Green LED** | 10 | Digital (PWM) |
| **Blue LED** | 11 | Digital (PWM) |

## 5. System Explanation
The system operates in a continuous loop with four distinct stages:

1. **Sensing:** The Arduino reads the voltage (0V to 5V) from the center pin of each potentiometer.
2. **Inverted Mapping:** To accommodate the Common Anode hardware, the code uses the `map()` function to flip the range: `map(val, 0, 1023, 255, 0)`.
3. **Actuation:** The `analogWrite()` function generates a PWM signal. This rapidly toggles the LED pins to simulate varying brightness levels.
4. **Reporting:** The current R, G, and B values are streamed to the Serial Monitor at **115200 baud** for real-time debugging.

## 6. Software Design
The software is designed for low latency and high readability:
* **Header Macros:** Uses `#define` for pin assignments to make hardware changes easy to manage.
* **Setup Block:** Initializes pin modes and establishes high-speed Serial communication.
* **Loop Block:** * Samples all three analog channels.
    * Performs linear mapping to the 8-bit color space.
    * Updates the PWM registers.
    * Includes a small `delay(20)` to maintain a responsive "feel" and prevent Serial buffer overflow.
