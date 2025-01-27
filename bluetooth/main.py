from machine import Pin, UART
import time

# Initialize motor control pins
motor1_forward = Pin(26, Pin.OUT)
motor1_backward = Pin(27, Pin.OUT)
motor2_forward = Pin(32, Pin.OUT)
motor2_backward = Pin(33, Pin.OUT)

# Initialize Bluetooth Classic (UART)
uart = UART(1, baudrate=9600, tx=17, rx=16)  # TX=17, RX=16

def control_car(command):
    if command == "F":  # Forward
        motor1_forward.on()
        motor1_backward.off()
        motor2_forward.on()
        motor2_backward.off()
    elif command == "B":  # Backward
        motor1_forward.off()
        motor1_backward.on()
        motor2_forward.off()
        motor2_backward.on()
    elif command == "L":  # Left
        motor1_forward.off()
        motor1_backward.on()
        motor2_forward.on()
        motor2_backward.off()
    elif command == "R":  # Right
        motor1_forward.on()
        motor1_backward.off()
        motor2_forward.off()
        motor2_backward.on()
    elif command == "S":  # Stop
        motor1_forward.off()
        motor1_backward.off()
        motor2_forward.off()
        motor2_backward.off()

print("Waiting for Bluetooth commands...")

while True:
    if uart.any():
        command = uart.read().decode('utf-8').strip()
        print("Received:", command)
        control_car(command)
    time.sleep(0.1)
