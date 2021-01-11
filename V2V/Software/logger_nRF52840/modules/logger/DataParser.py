from copy import deepcopy
from datetime import datetime
import re
from threading import Lock


class DataParser(object):
    def __init__(self, file: str, name: str = "", verbosity: int = 0):
        """
        DataParser - a parser with a format that it will follow when parsing the information it gets.
        It also takes a timestamp format in which it will format the timestamp after. This format is
        optional and may be specified as an empty string if you don't want a timestamp.

        The parser saves the parsed string in a buffer. This buffer is then written to file, which name
        and path is supplied in the file parameter to this function. The file has 4 different levels of
        logging: 1. DEBUG, 2. WARNING, 3. INFO, 4. ERROR. They are marked respectively, and depending
        on the level of verbosity each will have a more descriptive message the higher the level is.

        The parser is tied to a specific format, this is to make it easier to maintain. The format is
        specified as follows: [Real Time Timestamp] <level> app: information
        Where information can be a lot of different types of strings, check the parser for more information.
        The parser and functions that are tied to it has to be private with other functions public.

        :param file: Take a file name including path where to save the log to
        :param name: Take the name of the program and include it in the debug string
        :param verbosity: The lower the level the more parsed it is going to be, the higher level means less parsing
        """
        self.__name = name
        self.__file = file
        self.__buffer = []
        self.__verbose_level = verbosity
        self.__lock = Lock()

    def __parse(self, to_parse: str):
        pattern = "\[([0-9]{2}:[0-9]{2}:[0-9]{2}.[0-9]{3},[0-9]{3})\] \<([A-Za-z]{,10})\> app: (.*)"
        regex = re.compile(pattern)
        result = re.findall(regex, to_parse)
        parsed = {
            "mcu_ts": result[0][0],
            "msg_type": result[0][1],
            "msg_contents": result[0][2]
        }
        parsed["msg_contents"] = self.__parse_msg(parsed["msg_contents"])
        return parsed

    def write(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        return self.__put_together(formatted, pre_str)

    @staticmethod
    def __get_start_msg():
        ts = datetime.now()
        data = {"date": "%d/%d/%d" % (ts.year, ts.month, ts.day), "time": "%d:%d:%d:%d" % (ts.hour, ts.minute, ts.second, ts.microsecond)}
        return data

    def __parse_msg(self, param):
        data = {"RSSI": 0, "PowerMode": 0, "Channel": 0, "addr": "", "mode": "", "status": "", "error": ""}
        pattern = None
        items = {}
        if re.search("Output power .*", param):
            pattern = "(([0-9]{0,}) dBm)"
            items = {"PowerMode": (0, 0), "status": "Disconnected"}
        elif re.search("RSSI changed", param):
            pattern = "(new: (-[0-9]{0,}),) (channel: ([0-9]{0,}))"
            items = {"RSSI": (0, 1), "Channel": (0, 3), "status": "Connected"}
        elif re.search("Disconnected:", param):
            pattern = "(Disconnected): (reason (0x[0-9A-Z][0-9A-Z]))"
            items = {"status": (0, 0), "error": (0, 2)}
        elif re.search("(Starting scan|Connecting on)", param):
            pattern = "(([0-9])Mbps|coded phy)"
            items = {"status": "Connected" if not re.search("Starting scan", param) else "Disconnected",
                     "mode": (0, 0), "error": "None"}
        elif re.search("Received ADV report,", param):
            pattern = "(RSSI (-[0-9]+)), (phy: (1 Mbps|coded))"
            items = {"status": "Disconnected", "mode": (0, 3), "RSSI": (0, 1)}
        elif re.search("addr", param):
            pattern = "addr (([0-9A-Za-z]+:?){0,6})"
            items = {"addr": (0, 0), "status": "Disconnected"}
        else:
            pattern = None

        if pattern is None:
            return data

        regex = re.compile(pattern)
        find = regex.findall(param)
        if self.__verbose_level == 3:
            print(find)
        for i in items.keys():
            data[i] = items[i] if type(items[i]) == str else find[items[i][0]][items[i][1]]
        return data

    def __writeBuffer(self, param):
        with self.__lock:
            self.__buffer.append(param)
        return param.keys(), self.__buffer

    def __put_together(self, formatted, pre_str):
        total = {k: formatted["msg_contents"][k] for k in formatted["msg_contents"]}
        for k in formatted.keys():
            if k != "msg_contents":
                total[k] = formatted[k]
        for k in pre_str.keys():
            total[k] = pre_str[k]
        return self.__writeBuffer(total)
