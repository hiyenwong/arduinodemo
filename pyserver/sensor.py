#!/usr/bin/python
#-*- coding:utf-8 -*-

# TEST DHT11

import Adafruit_DHT
import urllib2
import time

class PiHome:

    def __init__(self, api_key):
        self.TS_API_URL_HEADER = 'https://api.thingspeak.com/update?key=' + api_key + '&'

    def postThingSpeak(self,temperature, humidity):
        post_url = self.TS_API_URL_HEADER + 'field1=' + str(temperature) + '&field2=' + str(humidity)
        print post_url
        resp = urllib2.urlopen(post_url)
        print resp.read()

    def getDHTValue(self):
        sensor = Adafruit_DHT.DHT11
        pin = 4
        humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
        if humidity is not None and temperature is not None:
            print 'temperature:{0:0.1f}'.format(temperature)
            print 'humidity:{0:0.1f}%'.format(humidity)
            self.temperature = temperature
            self.humidity = humidity
            self.postThingSpeak('{0:0.1f}'.format(temperature),'{0:0.1f}'.format(humidity))
        else:
            print 'opps!!!!! bad data! '

# pihome = PiHome('AM7AYS4X457BP7IM')
# pihome.getDHTValue()

#while 1:
#    pihome.getDHTValue()
#    time.sleep(300)
