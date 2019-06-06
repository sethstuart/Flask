from flask import Flask, request, render_template
import serial

app = Flask(__name__)

port = serial.Serial(port= 'COM11', baudrate=9600)
port.flushInput()
text = b'0'

# @app.route('/loading')
# def loading():
	# rcvinit = ""
	# initline = "<Arduino is ready>"
	# ohgodohfuckmyairpods = 0
	# while ohgodohfuckmyairpods == 0:
		# rcvinit = port.readline()
		# if rcvinit == initline:
			# ohgodohfuckmyairpods += 1
			# return rcvinit
		# else:
			# return rcvinit
	
	
@app.route('/write', methods=['GET','POST'])
def writeserial():
	if request.method == 'POST':
		text = request.form['text']
		text = text.encode()
		port.write(text)
		port.write(b'\n\r')
		return render_template('my-form.html')
	else:
		# port.write(b'0\n')
		return render_template('my-form.html')
	
# @app.route('/read')
# def readserial():
   # port.read()
   # roombaFarts = 
   # templateData = {
      # 'roombafarts': roombaFarts
      # }
   # return render_template('readserial.html', **templateData)