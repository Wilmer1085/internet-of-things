#script python
import serial
import time
import os

arduino_port = 'com1'
band_rate = 9600
ser = serial.serial(arduino_port,
baud_rate, timeou=1)
time.sleep(2)
while True
    data=ser.readline().decode('utf-8')
        rstrip()
    if data:
        humidity.temperature=data.split(",")
        print (f"Humedad: {humidity}%, Temperatura: {temperature}°C")
        TIME.sleep(1)
#rstrip: elimina espacio en blanco
#Timeout

