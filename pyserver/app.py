# -*- coding:utf-8 -*-

from flask import Flask
import sensor
app = Flask(__name__)

@app.route('/')
def index():
	pihome = sensor.PiHome('AM7AYS4X457BP7IM')
	pihome.getDHTValue()
	return str(pihome.temperature)

if __name__ == '__main__':
	app.debug = True
	app.run('0.0.0.0')