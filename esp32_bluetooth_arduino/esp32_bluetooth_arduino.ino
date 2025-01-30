#include "BluetoothSerial.h"

// Create BluetoothSerial object
BluetoothSerial SerialBT;

const int motorPin1 = 32; // Motor driver input 1
const int motorPin2 = 33; // Motor driver input 2
const int motorPin3 = 34; // Motor driver input 3
const int motorPin4 = 35; // Motor driver input 4

void setup() {
  // Start Bluetooth Serial
  SerialBT.begin("ESP32_RC_Car"); // Bluetooth device name
  Serial.begin(9600);

  // Initialize motor pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  Serial.println("Bluetooth Started. Waiting for pairing...");
}

void loop() {
  // Check if data is available
  if (SerialBT.available()) {
    char receivedChar = SerialBT.read(); // Read the received character
    Serial.println(receivedChar);

    // Control the motor based on received character
    if (receivedChar == 'F') {  // Move forward
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
    }
    else if (receivedChar == 'B') { // Move backward
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
    }
    else if (receivedChar == 'L') { // Turn left
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
    }
    else if (receivedChar == 'R') { // Turn right
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
    }
    else if (receivedChar == 'S') { // Stop
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
    }
  }
}
