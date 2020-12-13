import serial


class DataReader:
    def __init__(self, device, baudrate=9600):
        self.baudrate = baudrate
        self.device = device
        self.connection = self.try_connect()

    def try_connect(self):
        try:
            dev = serial.Serial(self.device, self.baudrate)
            return dev
        except serial.SerialException as e:
            print(e)

    def read(self):
        while not self.connection.readable():
            continue
        byte = self.connection.readline()
        decoded = byte[0:len(byte) - 2].decode("utf-8")
        return decoded

    def close(self):
        self.connection.close()
