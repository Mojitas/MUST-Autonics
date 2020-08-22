# Created by Erik Kamph for a logging device for Solar Team 2020
# With purpose of being used for the testbench in energy department
# Created on 18th July 2020
#
import sys
import os
from modules.dataPlotter import Plotter
from data_tests.TestRunner import run_data_tests
from data_tests.LogFileTest import setUpAndRun

delimiter = "\\" if sys.platform == "win32" else "/"

def get_project_root():
    current_dir = os.getcwd()
    return current_dir.replace("%ssource%spython" % (delimiter, delimiter), "")


def try_create(log_dirs):
    root = get_project_root()
    for i in log_dirs:
        if not os.path.isdir(root + i):
            os.mkdir(root + i)


if __name__ == "__main__":
    log_dirs = ["%sfigures" % delimiter, "%slogs" % delimiter]  # Directories for logging
    try_create(log_dirs)  # We try and create these if they don't already exist
    run_data_tests()  # We run tests on directories
    arguments = sys.argv[1:]  # We capture the program arguments given
    program = Plotter(arguments)  # Send the arguments to the plotter for parsing
    values = program.main()  # Start the main program and wait for four values
    # Setup and run the last test in which we check for the files that were created
    setUpAndRun(values[0], values[1], values[2], values[3])
