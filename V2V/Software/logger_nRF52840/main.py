import os
import random
import re
import sys
import configparser
from time import sleep

from modules.logger.DataParser import DataParser
from modules.logger.DataReader import DataReader
from modules.argumentparsers.arguments import arguments, print_version, print_help, set_conf
from modules.argumentparsers.commands import commands

command_list = ["scatter_plot", "save"]

if __name__ == "__main__":
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

    # data = DataReader()
    #
    # try:
    #     data.setup_threads()
    # except KeyboardInterrupt:
    #     print("Interrupted by keyboard")
    #
    # with open(conf.defaults().get("log_location") + "datalog_test.txt", "w+") as log:
    #     log.writelines(data.data)

    vlevel = conf.defaults().get("verbosity")
    dP = DataParser("", verbosity=int(vlevel))
    dR = DataReader()
    dR.set_dp(dP)

    tmp_file = os.getcwd() + "/logs/log" + str(random.randint(0, sys.maxsize)) + ".log"

    try:
        while 1:
            data = dP.make_copy_of_data()
            with open(tmp_file, "w+") as tmp:
                tmp.write("Test\n")
            sleep(1)
    except KeyboardInterrupt:
        print("Caught interrupt signal from keyboard.")
    # TODO: Save to file after some time has passed repeatedly
