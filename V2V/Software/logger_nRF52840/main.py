import sys

from modules.parser.arguments import arguments, print_help, print_version
from modules.parser.commands import commands
from modules.autodetect import autodetect

command_list = ["scatterplot", "save"]


if __name__ == "__main__":
    argp = arguments(False)
    args, cmdx = argp.parse(sys.argv[1:])
    cmdp = commands()
    cmds = cmdp.parse_commands(cmdx)
    args = cmdp.setargs(args, cmds)
    print(args)
    exit(0)

    # if arguments.version:
    #     print("%f" % version)
    #     exit(0)
    # elif '-h' in commands:
    #     print_help(sys.argv[0])
    #     exit(0)
    #
    # path = ""
    # if arguments.device != 'auto':
    #     if os.path.exists(arguments.device):
    #         path = arguments.device
    #     else:
    #         print("Device does not exist!")
    #         exit(0)
    #
    # baudrate = 115200
    # if arguments.baudrate != baudrate:
    #     if arguments.baudrate in accepted:
    #         baudrate = arguments.baudrate
    #     else:
    #         print("Invalid baudrate!")
    #
    # verbosity = 0
    # if arguments.verbose != verbosity:
    #     verbosity = arguments.verbose
    #
    # if 'scatterplot' in commands:
    #     arguments.scatterplot = True
    #     commands.pop(commands.index('scatterplot'))
    #
    # print(commands)
    # if 'save' in commands:
    #     p = commands[commands.index('save') + 1]
    #     if p not in command_list:
    #         if not p.startswith("/"):
    #             arguments.fpath = os.getenv("HOME") + "/" + p
    #         else:
    #             arguments.fpath = p
    #
    # print(arguments)
    # ad = autodetect(sys.platform)
    # results = ad.autodetect()
    # dev = results[0]
    # print("Using device: %s" % dev)
    # reader = DataReader(dev, 115200)
    # try:
    #     while 1:
    #         print(reader.read())
    # except KeyboardInterrupt:
    #     print("Got interrupted")
    # reader.close()
