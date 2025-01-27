from servo import Servo
from time import sleep

servo=Servo(pin=15)

while True: 
    servo.move(0)
    sleep(2)
    servo.move(90)
    sleep(2)
    servo.move(180)
    sleep(2)
    