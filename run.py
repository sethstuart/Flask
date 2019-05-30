from flask import Flask, request, render_template
import serial
import time

app = Flask(__name__)

port = serial.Serial(port= 'COM12', baudrate=9600)
port.flushInput()
text = b'0'

@app.route('/')
def my_form():
	port.write(text)
	return render_template('my-form.html')
	
	
@app.route('/', methods=['POST'])
def my_form_post():
	text = request.form['text']
	port.write(text)
	return text

time.sleep(5)
	


