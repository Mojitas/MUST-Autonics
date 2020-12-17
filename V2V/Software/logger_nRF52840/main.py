import os
import re
import sys
import configparser

from modules.logger.DataParser import DataParser
from modules.logger.DataReader import DataReader
from modules.argumentparsers.arguments import arguments, print_version, print_help, set_conf
from modules.argumentparsers.commands import commands

command_list = ["scatter_plot", "save"]

if __name__ == "__main__":
    # argp = arguments(False)
    # args, cmdx = argp.parse(sys.argv[1:])
    # cmdp = commands()
    # cmds = cmdp.parse_commands(cmdx)
    # args = cmdp.setargs(args, cmds)
    #
    # if args.version:
    #     print_version()
    #     exit(0)
    # elif args.help:
    #     print_help(sys.argv[0])
    #     exit(0)
    #
    # conf = configparser.ConfigParser(allow_no_value=True)
    # conf.read(os.getcwd() + "/configs/defaults.ini")
    # conf.set("DEFAULT", "log_location", os.getcwd() + "/logs/")
    # conf = set_conf(conf, args)
    #
    # # data = DataReader()
    # #
    # # try:
    # #     data.setup_threads()
    # # except KeyboardInterrupt:
    # #     print("Interrupted by keyboard")
    # #
    # # with open(conf.defaults().get("log_location") + "datalog_test.txt", "w+") as log:
    # #     log.writelines(data.data)
    #
    # print(conf.defaults().get("verbosity"))
    # dP = DataParser("", verbosity=int(conf.defaults().get("verbosity")))
    # dP.debug("Hello World")
    to_parse = "[00:00:08.062,438]"
    pattern = "\[[0-9]{2}"
    regex = re.compile(pattern)
    result = re.findall(regex, to_parse)
    print(result)
