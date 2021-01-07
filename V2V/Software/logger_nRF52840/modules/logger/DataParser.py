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
        """
        self.name = name
        self.file = file
        self.buffer = []
        self.verbosity = verbosity
        self.lock = Lock()

        self.hasName = True if self.name != "" else False
        self.saveToFile = True if self.file != "" else False
        self.leveldic = {"debug": self.__debug, "warning": self.__warning, "info": self.__info, "error": self.__error}

    def __parse(self, to_parse: str):
        parsed = ""
        if self.verbosity == 3:
            parsed = to_parse
        else:
            pattern = "\[([0-9]{2}:[0-9]{2}:[0-9]{2}.[0-9]{3},[0-9]{3})\] \<([A-Za-z]{,10})\> app: (.*)"
            regex = re.compile(pattern)
            result = re.findall(regex, to_parse)
            parsed = {
                "timestamp": result[0][0],
                "type": result[0][1],
                "msg": result[0][2]
            }

        if self.verbosity == 0:
            parsed["msg"] = self.__parse_msg(parsed["msg"])
        return parsed

    def __debug(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.__writeBuffer("%s,%s,%s\n" % ("DEBUG", pre_str, str(formatted)))

    def __warning(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.__writeBuffer("%s,%s,%s\n" % ("WARNING", pre_str, str(formatted)))

    def __info(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.__writeBuffer("%s,%s,%s\n" % ("INFO", pre_str, str(formatted)))

    def __error(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.__writeBuffer("%s,%s,%s\n" % ("ERROR", pre_str, str(formatted)))

    def write(self, message, level=None):
        formatted = self.__parse(message)["type"]
        func = self.leveldic[formatted if formatted != "" else level]
        func(message=message)

    @staticmethod
    def __get_start_msg():
        ts = datetime.now()
        return "%d/%d/%d,%d:%d:%d:%d" % (ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second, ts.microsecond)

    def __parse_msg(self, param):
        data = {"RSSI": 0, "PowerMode": 0, "Channel": 0, "": 0, "addr": "", "mode": "", "status": "", "error": ""}
        if re.search("Output power .*", param):
            pattern = "(([0-9]{0,}) dBm)"
            regex = re.compile(pattern)
            find = re.findall(regex, param)
            data["PowerMode"] = find[0][0]
        elif re.search("RSSI changed", param):
            pattern = "(new: (-[0-9]{0,}),) (channel: ([0-9]{0,}))"
            regex = re.compile(pattern)
            find = re.findall(regex, param)
            data["RSSI"] = find[0][1]
            data["Channel"] = find[0][3]
        elif re.search("Disconnected:", param):
            pattern = "(Disconnected): (reason (0x[0-9A-Z][0-9A-Z]))"
            regex = re.compile(pattern)
            find = re.findall(regex, param)
            if len(find) != 0:
                data["status"] = find[0][0]
                data["error"] = find[0][2]
        elif re.search("(Starting scan|Connecting on)", param):
            pattern = "(([0-9])Mbps|coded phy)"
            regex = re.compile(pattern)
            find = re.findall(regex, param)
            data["status"] = "Connected"
            data["mode"] = find[0][0]
            data["error"] = "None"
        # elif re.search("RTT")
        return data

    def make_copy_of_data(self):
        with self.lock:
            t = deepcopy(self.buffer)
        return t

    def __writeBuffer(self, param):
        with self.lock:
            self.buffer.append(param)
