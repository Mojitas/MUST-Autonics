import os


class cmdparse:
    def __init__(self):
        self.commands = []
        self.cmdlist = []
        self.namespace = {}
        self.ntabs = 7

    def add_command(self, *command: str, requires_arg: bool = False, help: str = "", store: str,
                    default: str = "", required: bool = False):
        command_arr = [i for i in command]
        cmdstr = ""
        for k, v in enumerate(command):
            self.cmdlist.append(v)
            if k < len(command) - 1:
                cmdstr += "%s, " % v if not requires_arg else "%s arg, " % v
            else:
                cmdstr += "%s" % v if not requires_arg else "%s arg" % v
        self.commands.append({"arr": command_arr, "req_arg": requires_arg,
                              "store": store, "def": default, "required": required, "help": help, "cmdstr": cmdstr})

    def print_commands(self):
        for i in self.commands:
            print("%-40s" % i["cmdstr"], end="")
            print(i["help"] + " (Required: " + str(i["required"]) + ")")
            if i["def"] != "":
                print("%40s%s" % ("", "Default: " + i["def"]))

    def parse(self, args):
        for i in args:
            for cmd in self.commands:
                if i in cmd["arr"] and cmd["req_arg"]:
                    self.namespace[cmd["store"]] = args[args.index(i) + 1]
                elif i in cmd["arr"] and not cmd["req_arg"]:
                    self.namespace[cmd["store"]] = True
        self.set_defaults()
        return self.namespace

    def set_defaults(self):
        for cmd in self.commands:
            store = cmd["store"]
            default = cmd["def"]
            if store not in self.namespace.keys():
                self.namespace[store] = default \
                    if default not in ("False", "True") \
                    else True if default == "True" \
                    else False


class commands:
    def __init__(self):
        self.parser = cmdparse()
        self.add_commands()

    def parse_commands(self, cmds):
        return self.parser.parse(cmds)

    def add_commands(self):
        self.parser.add_command("scatterplot", help="Print a scatter plot", default="scatter.png",
                                requires_arg=False, store="scatter")
        self.parser.add_command("save", help="A location for where to save the file",
                                requires_arg=True, store="save", default=os.getcwd() + "/plots/")
        self.parser.add_command("h", "help", store="help", help="Prints this help", default="False")
        self.parser.add_command("v", "version", store="version", help="Display the version number", default="False")

    def setargs(self, args, cmds):
        args.scatter = cmds['scatter']
        args.save = cmds['save']
        args.help = cmds['help'] if args.help is not True else args.help
        args.version = cmds['version'] if args.version is not True else args.version
        return args
