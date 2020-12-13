import glob
import serial


class autodetect:
    def __init__(self, platform):
        self.os = platform
        self.ports = self.get_ports()

    def autodetect(self):
        if self.os not in ("darwin", "linux", "cygwin", "win"):
            raise EnvironmentError("Unsupported platform detected")
        else:
            result = []
            for port in self.ports:
                try:
                    obj = serial.Serial(port, 115200)
                    obj.close()
                    result.append(port)
                except (OSError, serial.SerialException):
                    pass
            return result

    def get_ports(self):
        return ['COM%s' % (i + 1) for i in range(256)] \
            if self.os == "win" else glob.glob("/dev/ACM[0-9]*") \
            if self.os in ("linux", "cygwin") else glob.glob("/dev/tty.usbmodem*") \
            if self.os == "darwin" else None
