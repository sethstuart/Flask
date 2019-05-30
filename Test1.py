import serial
import time

port = serial.Serial("/dev/ttyAMA0", baudrate=9600, timeout=3.0)
port.flushInput()
x = b'0'

while True:
    port.write(x)
	x = input("Enter a number between 1 and 180 (pick a lower number)")
	port.write(x)
	time.sleep(1)
	if port.inWaiting() > 0:
		data = port.read()
		print(data)
	