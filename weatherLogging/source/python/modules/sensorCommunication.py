import copy
import sys
import time
from collections import deque
from threading import Thread

import pandas as pd
import serial
from matplotlib import pyplot as plt
import os


class Communication:
    def __init__(self, device, baudrate=9600, pltlen=100, units=None, colors=None):
        self.baudrate = baudrate
        self.device = device
        self.isRunning = True  # Keeps the thread running
        self.thread = None  # Holds the thread that is running in this class
        # The data from the sensors automatically filled
        self.data = {i: deque([0.0] * pltlen, maxlen=pltlen) for i in units.keys()}
        self.timestamps = []  # The timestamps, also automatically filled
        self.isReceiving = False  # Are we receiving any data?
        self.pltTimer = 0
        self.previousTimer = 0
        self.max_plot_length = pltlen
        self.serialConn = self.setup_serial()  # setup a serial connection to the arduino board
        self.csv = []
        self.columns = list(self.data.keys())
        self.units = units
        self.colors = colors
        self.delimiter = "\\" if sys.platform == "win32" else "/"
        if self.serialConn is None:  # If we could not connect to serial console
            print("Nothing to see here and something went wrong!")
            exit(0)

    # Connects to the arduino device
    def setup_serial(self):
        print("Trying to connect to " + self.device + " with baudrate " + str(self.baudrate))
        serial_con = None
        try:
            # Tries to connect to the device on the baudrate specified from before
            serial_con = serial.Serial(port=self.device, baudrate=self.baudrate)
            print("Connected to " + self.device + " with baudrate " + str(self.baudrate) + " successfully!")
        except serial.SerialException as e:
            print(e)
        return serial_con

    # Starts the background thread for getting data
    def read_serial_start(self):
        if self.thread is None:
            self.thread = Thread(target=self.background_thread)  # Creates a thread with target function
            self.thread.start()  # Starts the thread
            while not self.isReceiving:  # Waits until we are receiving data then ends the function
                time.sleep(0.1)

    # Makes the line in each subplot update with the latest value
    def get_serial_data(self, _, axs):
        current_timer = time.perf_counter()
        self.pltTimer = int((current_timer - self.previousTimer) * 1000)  # First reading will be erroneous
        self.previousTimer = current_timer
        ydata = copy.deepcopy(self.data)
        for i in range(len(axs)):
            col = self.columns[i]  # Get the column to plot according to position i
            ax = axs[i]  # Get the axes object for the same position
            ax.clear()  # Clear the data is has
            ax.set_ylabel(self.units[col])  # Set the y-label also known as the unit
            if i == 1:
                ax.text(0.4, 0.90, 'Plot Interval = ' + str(self.pltTimer) + ' ms', transform=ax.transAxes)
            # Plot the x- and y-data in the axes object
            ax.plot(range(self.max_plot_length), ydata[col], self.colors[col], label=col, lw=2)
            value = ydata[col][-1]  # Get latest point
            # Set the text at the top of the figure that holds the latest data-point
            ax.text(0.4, 0.80 if i == 1 else 0.90, '[' + col + '] = ' + str(value), transform=ax.transAxes)
        plt.draw()

    # The background thread that receives the data
    def background_thread(self):
        time.sleep(1.0)  # Sleep for one second
        self.serialConn.reset_input_buffer()  # Reset the input buffer
        while self.isRunning:
            self.timestamps.append(pd.Timestamp.now(tz=None))  # Append a timestamp
            acc = []
            for i in self.columns:  # reads the number of lines equal to the number of columns
                byte = self.serialConn.readline()  # Read a line
                decoded = float(byte[0:len(byte) - 2].decode("utf-8"))
                self.data[i].append(decoded)  # Append the data to each columns deque object for drawing in the graph
                acc.append(decoded)  # append it to an array as well for later saving in a csv file
            self.csv.append(acc)  # Append the data in acc to a two dimensional array
            self.isReceiving = True  # Change from False to True on an isReceiving tag to end the other function

    # Closes the serial connection and writes the data to a csv file
    def close(self):
        self.isRunning = False
        self.thread.join()  # Wait for the thread to end executing
        self.serialConn.close()  # Close the connection to the device
        root = self.get_project_root()
        df = self.create_dataframe()
        ts = str(pd.Timestamp.now()).split(" ")
        overview = self.make_overview(df, root, ts)  # Make a graph
        csv_file = "%s%slogs%slog_%s_%s.csv" % (root, self.delimiter, self.delimiter, ts[0], ts[1].replace(":", "-"))
        df.to_csv(csv_file)  # Saves all the data to a csv file
        return csv_file, len(df.values), df.columns, overview

    # Makes an overview graph
    def make_overview(self, dataframe, root, ts):
        fig = plt.figure(figsize=(12, 10))
        for i in range(len(self.columns)):
            ax = fig.add_subplot(int('42' + str(i + 1)))
            if i == 5 or i == 6:
                ax.set_xlabel("Time")
            ax.text(0.4, 0.85, self.columns[i], transform=ax.transAxes)
            ax.set_ylabel(self.units[self.columns[i]])
            ax.plot(dataframe.index.values, dataframe[self.columns[i]], self.colors[self.columns[i]],
                    label=self.columns[i])
        figure_name = "%s%sfigures%soverview%s_%s.png" % (root, self.delimiter, self.delimiter, ts[0], ts[1].replace(":", "-"))
        fig.savefig(fname=figure_name)
        plt.close(fig)
        return figure_name

    # Creates a dataframe with all the data from the current session
    # Timestamps as index, sensornames as columns and the data itself
    def create_dataframe(self):
        df = pd.DataFrame(index=self.timestamps, data=self.csv, columns=self.columns)
        return df

    def get_project_root(self):
        current_dir = os.getcwd()
        return current_dir.replace("%ssource%spython" % (self.delimiter, self.delimiter), "")
