# ESP32-S3 USB HID Button Keyboard

Simple project using ESP32-S3 to send keyboard input (arrow keys + 'e') through USB when buttons are pressed.

## 🧠 Features
- Press physical buttons → send arrow key (↑ ↓ ← →) or "e"
- Uses USB HID (no extra driver needed)
- Built with Arduino framework

## 🛠️ Hardware Used
- ESP32-S3 board (with native USB)
- 5x push buttons
- Jumper wires + breadboard

## 📷 Wiring
| Button | GPIO Pin |
|--------|----------|
| UP     | 5        |
| DOWN   | 1        |
| LEFT   | 7        |
| RIGHT  | 6        |
| E      | 14       |

(use INPUT_PULLUP)

## 🧪 How It Works
- Hold a button → sends and holds the key
- Release button → releases the key
- Press 'E' button → types lowercase `e` every time (with delay to avoid spam)

## 🧵 Code
Code is in `main.ino` (or whatever you name it).  
Flash using Arduino IDE with ESP32 board manager installed.

## 📸 Demo
*Insert image or gif here if u got one*

## 💬 Author
Made by [Your Name or GitHub handle]

---
> Started at 13. Watch me go full beast mode by 18 🔥
