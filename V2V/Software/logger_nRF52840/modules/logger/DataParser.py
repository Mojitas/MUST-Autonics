from datetime import datetime
import re


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

        self.hasName = True if self.name != "" else False
        self.saveToFile = True if self.file != "" else False
        self.leveldic = {"DEBUG": self.debug, "WARNING": self.warning, "INFO": self.info, "ERROR": self.error}

    def __parse(self, to_parse: str):
        parsed = ""
        if self.verbosity == 3:
            parsed = to_parse
        elif self.verbosity == 2:
            pass
        else:
            pattern = "([0-9]{0,2}:){0,2}[0-9]{0.2}\.[0-9]{0,3},[0-9]{0,3}"
            regex = re.compile(pattern)
            result = re.findall(regex, to_parse)
            print(result)
            pass
        return parsed

    def debug(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.buffer.append("%s,%s,%s" % ("DEBUG", pre_str, formatted))

    def warning(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.buffer.append("%s,%s,%s" % ("WARNING", pre_str, formatted))

    def info(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.buffer.append("%s,%s,%s" % ("INFO", pre_str, formatted))

    def error(self, message):
        formatted = self.__parse(message)
        pre_str = self.__get_start_msg()
        self.buffer.append("%s,%s,%s" % ("ERROR", pre_str, formatted))

    def write(self, message, level=None):
        func = self.leveldic[level]
        func(message=message)

    @staticmethod
    def __get_start_msg():
        ts = datetime.now()
        return "%d/%d/%d,%d:%d:%d:%d" % (ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second, ts.microsecond)
