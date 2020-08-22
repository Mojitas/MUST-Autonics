import argparse

from modules.autodetect_serial_port import serial_ports
from matplotlib import animation as anim
from matplotlib import pyplot as plt
from modules.sensorCommunication import Communication


class Plotter:
    def __init__(self, arguments):
        self.parser = None
        self.arguments()  # The argument parser
        self.args = self.parser.parse_args(arguments)  # arguments needs to be sys.argv[1:]
        # Sensors that exist, for each sensor added after these, add a color and a unit in the two after
        self.columns = ["Temperature", "Voltage", "Windspeed", "Pyranometer",
                        "Current", "Preassure", "Flow"]
        # Color configuration, one color per sensor = 1 color per graph
        self.colors = {i: ['c-', 'm-', 'y-', 'k-', 'r-', 'g-', 'b-'][self.columns.index(i)] for i in self.columns}
        # Unit configuration, each sensor has a unit
        self.units = {i: ['Celsius', 'Volt', 'Number', 'W m^(-2)', 'Ampere', 'kPa', 'l/m'][self.columns.index(i)]
                      for i in self.columns}
        self.device = None
        self.baudrate = None
        self.get_device()
        self.get_baudrate()

    # Create a parser that parses arguments
    def arguments(self):
        parser = argparse.ArgumentParser(description='Show live plots and save sensor data from Arduino')
        parser.add_argument('-dev', '--device', dest='arduino_device',
                            help='A path to an arduino device e.g. /dev/ttyACM0 or COM4', required=False)
        parser.add_argument('-b', '--baudrate', dest='baudrate',
                            choices=['300', '600', '1200', '2400', '4800', '9600', '14400',
                                     '19200', '28800', '38400', '57600', '115200'],
                            help='The serial data rate which the arduino is sending data on', required=False)
        self.parser = parser

    def get_device(self):
        args = self.args
        if 'arduino_device' in args and args.arduino_device is not None:
            arduino = args.arduino_device  # If it is then take it as argument for the program
        else:
            devices = serial_ports()  # Otherwise search for a device
            dev = devices[1] if len(devices) > 1 else devices[0] if len(
                devices) > 0 else None  # Take the first depending on length, first might be bluetooth com port
            if dev is None:
                print("Enter exact location of arduino serial port:")
            arduino = dev if dev is not None else input()
        self.device = arduino

    def get_baudrate(self):
        args = self.args
        if 'baudrate' in args and args.baudrate is not None:
            self.baudrate = int(args.baudrate)
        self.baudrate = 9600

    def main(self):
        max_plot_len = 100  # How much data in one plot should we have
        # Initialization of class that contains background thread
        sensor = Communication(device=self.device, baudrate=self.baudrate, pltlen=max_plot_len,
                               units=self.units, colors=self.colors)
        sensor.read_serial_start()  # Start the background thread

        interval = 1000  # How often should we plot? 1000 ms = 1 sec interval
        fig = plt.figure(figsize=(12, 10))  # Create a figure with a specified size
        axs = []
        for i in range(len(self.columns)):
            ax = fig.add_subplot(int("42" + str(i + 1)))
            if i == 5 or i == 6:
                ax.set_xlabel("Time")
            ax.plot([], [], self.colors[self.columns[i]], label=self.columns[i], lw=2)
            axs.append(ax)
        # Never remove "_ = " from the line below otherwise it breaks the animation itself
        _ = anim.FuncAnimation(fig, sensor.get_serial_data, fargs=(axs, ), interval=interval)
        plt.autoscale(enable=True, axis='both', tight=True)
        plt.legend(loc='upper left')
        plt.show()  # Show the figures that were created

        # Close the stream when done and return 4 values back to main
        return sensor.close()
