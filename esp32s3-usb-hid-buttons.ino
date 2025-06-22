// Include necessary libraries
#include "USB.h"
#include "USBHIDKeyboard.h"
// Uncomment below to use WASD control instead of arrow keys
//#define USE_WASD

USBHIDKeyboard Keyboard;

// Define button pins
int UP = 5;
int DOWN = 1;
int LEFT = 7;
int RIGHT = 6;
int E = 14;

void setup() {
  // Set button pins as input with internal pull-up resistors
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);

  // Initialize USB and Keyboard
  Keyboard.begin();
  USB.begin();
}

void loop() {
  // Handle UP button
  if (digitalRead(UP) == LOW) {
    #ifdef USE_WASD
    Keyboard.press('w');
    #else
    Keyboard.press(KEY_UP_ARROW);
    #endif
  } else {
    #ifdef USE_WASD
    Keyboard.release('w');
    #else
    Keyboard.release(KEY_UP_ARROW);
    #endif
  }

  // Handle DOWN button
  if (digitalRead(DOWN) == LOW) {
    #ifdef USE_WASD
    Keyboard.press('s');
    #else
    Keyboard.press(KEY_DOWN_ARROW);
    #endif
  } else {
    #ifdef USE_WASD
    Keyboard.release('s');
    #else
    Keyboard.release(KEY_DOWN_ARROW);
    #endif
  }

  // Handle LEFT button
  if (digitalRead(LEFT) == LOW) {
    #ifdef USE_WASD
    Keyboard.press('a');
    #else
    Keyboard.press(KEY_LEFT_ARROW);
    #endif
  } else {
    #ifdef USE_WASD
    Keyboard.release('a');
    #else
    Keyboard.release(KEY_LEFT_ARROW);
    #endif
  }

  // Handle RIGHT button
  if (digitalRead(RIGHT) == LOW) {
    #ifdef USE_WASD
    Keyboard.press('d');
    #else
    Keyboard.press(KEY_RIGHT_ARROW);
    #endif
  } else {
    #ifdef USE_WASD
    Keyboard.release('d');
    #else
    Keyboard.release(KEY_RIGHT_ARROW);
    #endif
  }

  // Handle E button for single press
  static bool eWasPressed = false;
  if (digitalRead(E) == LOW && !eWasPressed) {
    Keyboard.print("e");
    eWasPressed = true;
  }
  if (digitalRead(E) == HIGH && eWasPressed) {
    eWasPressed = false;
  }

  delay(10); // Tiny delay to debounce and chill the loop
}
