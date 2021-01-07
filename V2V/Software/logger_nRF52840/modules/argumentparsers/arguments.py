import argparse
import configparser
import sys

accepted = ['300', '600', '1200', '2400', '4800', '9600', '14400', '19200', '28800', '31250', '38400', '57600', '115200']
version = 1.0


def print_version():
    print("Version: %f" % version)


def print_help(arg):
    print("""Usage: python %s [optional arguments] [commands] [optional commands]
Version: %f

Optional arguments:
-h, --help                              Display this help dialog
-br in, --baudrate in                   Change the default baudrate for information flow on UART bus.
                                        Default: 115200, Accepted values: [300, 600, 1200, 2400, 4800, 9600, 14400,
                                                                           19200, 28800, 31250, 38400, 57600, 115200]
-d device, --device device              Set the path to the device to use
                                        Default: autodetect, Accepts: COM[0-255], /dev/ACM[0-9] or /dev/tty.usbmodem<numbers>
                                        Depending on the OS it might be different
-v, --version                           Display the version of this program
-V, --verbose                           Increase output verbosity, one V or verbose per level.
                                        Highest possible verbose level is 3, which is equal to -VVV

Optional Commands:
scatterplot                             Print a scatter plot with default name: scatter.x.png
                                        Where x is a number from 0 to %d
save path                               Saves the file at the specified path with a specified name
                                        path is the path including the filename

Authors:
Erik Kamph, MDH Solar Team 2020
    """ % (arg, version, sys.maxsize))


def set_conf(conf: configparser.ConfigParser, args):
    conf.set("DEVICE", "baudrate", str(args.baudrate))
    if args.device != "auto":
        conf.set("DEVICE", "location", args.device)
        conf.set("DEVICE", "auto_detect", str(False))
    else:
        conf.set("DEVICE", "location", "None")
        conf.set("DEVICE", "auto_detect", str(True))
    conf.set("DEFAULT", "scatter_name", args.scatter)
    conf.set("DEFAULT", "plt_location", args.save)
    if args.verbose is not None:
        conf.set("DEFAULT", "verbosity", str(args.verbose))
    print(conf.get("DEFAULT", "verbosity"))
    return conf


class arguments(object):
    def __init__(self, add_help=True):
        self.parser = argparse.ArgumentParser(add_help=add_help)
        self.add_arguments()

    def add_arguments(self):
        self.parser.add_argument("-h", "--help", dest="help", action="store_true",
                                 required=False, help="Display this help")
        self.parser.add_argument("-br", "--baudrate", choices=accepted,
                                 default=115200, dest="baudrate", required=False,
                                 help="Set a baudrate other than the default value specified as 115200.")
        self.parser.add_argument("-d", "--device", default="auto", dest="device",
                                 required=False, help="Set the path to the device connected to the computer")
        self.parser.add_argument("-v", "--version", required=False, action="store_true",
                                 dest="version", help="Display the version number of the software")
        self.parser.add_argument("-V", "--verbose", required=False, action="count",
                                 help="Set the verbose level of the software,"
                                      " more of this flag means higher level. Highest level is 3")

    def parse(self, param):
        parsed = self.parser.parse_known_args(param)
        return parsed[0], parsed[1]
