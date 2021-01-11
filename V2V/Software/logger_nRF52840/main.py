import os
import random
import sys
import configparser
import pandas as pd
import serial

from modules.logger import autodetect
from modules.logger.DataParser import DataParser
from modules.logger.DataReader import DataReader
from modules.argumentparsers.arguments import arguments, print_version, print_help, set_conf
from modules.argumentparsers.commands import commands

command_list = ["scatter_plot", "save"]

if __name__ == "__main__":
    """
    Parse arguments and commands, print help or version if those commands are supplied.
    Otherwise read the configuration file and set the rest of the options that are not
    set by command or flag. Follow-up by initializing the DataReader and DataParser that
    will read and parse the incoming data from the device. Then after all of that start
    the loop that will run until the device is disconnected or a CTRL+C command is sent
    from the keyboard interrupting the script.
    """
    argp = arguments(False)
    args, cmdx = argp.parse(sys.argv[1:])
    cmdp = commands()
    cmds = cmdp.parse_commands(cmdx)
    args = cmdp.setargs(args, cmds)

    if args.version:
        print_version()
        exit(0)
    elif args.help:
        print_help(sys.argv[0])
        exit(0)

    conf = configparser.ConfigParser(allow_no_value=True)
    conf.read(os.getcwd() + "/configs/defaults.ini")
    conf.set("DEFAULT", "log_location", os.getcwd() + "/logs/")
    conf = set_conf(conf, args)

    tmp_file = os.getcwd() + "/logs/log" + str(random.randint(0, sys.maxsize)) + ".csv"
    vlevel = conf.defaults().get("verbosity")
    dP = DataParser("", verbosity=int(vlevel), name=__name__)
    dR = DataReader(conf)
    dR.set_dp(dP)

    print(f'Running with verbosity level set to {vlevel}')
    print(f'Filename for temporary csv file: {tmp_file}')
    try:
        with open(tmp_file, "w+") as log:
            while True:
                keys, data = dR.parse()
                df = pd.DataFrame(data=data, columns=keys).replace(to_replace="", value="None")
                if len(df.values) % 100:
                    df.to_csv(path_or_buf=tmp_file)
    except (KeyboardInterrupt, serial.SerialException):
        print("Caught interrupt signal that was either device disconnect or keyboard.")
