import os
import queue
import sys
from threading import Thread
from time import sleep

import serial
import configparser

from modules.logger.DataParser import DataParser
from modules.logger.autodetect import autodetect
from copy import deepcopy


class DataReader(object):
    def __init__(self):
        self.auto = autodetect(sys.platform)
        self.settings = configparser.ConfigParser(allow_no_value=True)
        self.settings.read(os.getcwd() + "/configs/defaults.ini")
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
        self.data = []
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
        decoded = byte[0:len(byte) - 2].decode("utf-8") + ""
        return decoded

    def setup_threads(self):
        self.t_run = True
        self.thread = Thread(target=self.data_thread)
        self.thread.start()
        print("Thread is running!", flush=True)
        sleep(3)
        self.thread_two = Thread(target=self.parse_thread)
        self.thread_two.start()

    def data_thread(self):
        try:
            while self.t_run:
                local = self.read()
                self.queue.put_nowait(local)
        except serial.SerialException:
            print("Device disconnected from serial port!", file=sys.stderr, flush=True)
        return

    def parse_thread(self):
        while not self.has_data():
            continue
        while self.has_data():
            line = self.queue.get_nowait()
            self.data_parser.write(line)
        return

    def get_data(self):
        return deepcopy(self.data)

    def close(self):
        self.connection.close()

    def get_first(self):
        self.x += 1
        return deepcopy(self.data[self.x])

    def has_data(self):
        return self.queue.qsize() > 0

    def set_dp(self, dP):
        self.data_parser = dP
