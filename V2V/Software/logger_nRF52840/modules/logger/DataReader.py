import os
import queue
import sys
import serial

from modules.logger.autodetect import autodetect


class DataReader(object):
    def __init__(self, config):
        self.auto = autodetect(sys.platform)
        self.settings = config
        self.device = self.settings.get("DEVICE", "location")\
            if self.settings.get("DEVICE", "auto_detect") != "True" \
            else self.auto.autodetect()[0] if len(self.auto.autodetect()) > 0 else 0
        if self.device == 0:
            raise ConnectionError("No device detected, please connect the device before continuing!")
        self.baudrate = int(self.settings.get("DEVICE", "baudrate"))
        self.connection = self.try_connect()

        self.thread = None
        self.t_run = False
        self.thread_two = None
        self.queue = queue.Queue()
        self.x = -1
        self.data_parser = None

    def try_connect(self):
        try:
            dev = serial.Serial(self.device, self.baudrate)
            print("Connected to %s using baudrate %d" % (self.device, self.baudrate))
            return dev
        except serial.SerialException as e:
            print(e)

    def read(self):
        while not self.connection.readable():
            continue
        byte = self.connection.readline()
        decoded = byte[0:len(byte) - 2].decode("utf-8")
        return decoded

    def parse(self):
        item = self.read()
        return self.data_parser.write(item)

    def close(self):
        self.connection.close()

    def set_dp(self, dP):
        self.data_parser = dP
