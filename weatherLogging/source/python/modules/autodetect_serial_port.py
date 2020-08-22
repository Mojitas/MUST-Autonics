import glob
import sys

import serial


def serial_ports():
    """ Lists serial port names

        :raises EnvironmentError:
            On unsupported or unknown platforms
        :returns:
            A list of the serial ports available on the system
    """
    if sys.platform == 'win':
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform in ('linux', 'cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform == 'darwin':
        ports = glob.glob('/dev/tty.usb*')
    else:
        raise EnvironmentError('Unsupported devices or platform!')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result
