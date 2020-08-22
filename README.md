# Logging system for energy-team
This program is developed by some or all of the electronics team for the energy teams logging device.
## Version
- v1 - Initial version with one graph containing all sensors
- v2 - Fixed a problem with the queues which might have presented the data wrong when plotting
- v3 - Live plotting seven different graphs in seven different windows
- v4 - Implementation of arduino autodetecter and autoscale for plots
- v5 - Made it look more like a library to easier access different files
- v6 - Moved three files into modules directory for a more modular build
- __vx__ - Version number has gone completely out of hand, unittests have been added to prevent the script from failing. Though if it is failing, we can complain on energy since they don't have what the script requires.

## Structure
The structure of this project is as follows to separate source files from data files and figures.
It should be kept this way for easier access and maintenance.
```
| Root
   \| Figures
    | Logs
    | Source
       \| Arduino
        | Python
    | venv (if exists)
    | README.md (this)
    | requirements.txt
```

Examples of how the log file and overview that will be written in `Figures` respectively `Logs` is available in respective directories names example.png and example.csv.
Now the lines won't be as flat as in the example files but keep in mind that those are just examples of how it can look.

## TODO
This is a list over stuff that needs to be done before the deadline, if anything comes up it will be added here.
Please don't touch any of the files in `source/python` while I'm working in these files otherwise it might break the code.

- [x] Make a dataPlotter.py
- [x] Error check on subplots why they don't continuously draw data
- [ ] Check for other possible errors

## Checklist
The third one might not be met or all of them depending on the system. Check under respective header for information
- [x] Python 3 or latest
- [x] pip3 or latest
- [x] Installed packages in requirements

### Python and pip
Install python from [Python](https://python.org)

### Packages in requirements
In this project there is a requirements.txt it is configured with packages required to run.
To get it running install those packages with following command
````bash
pip install -r requirements.txt
````
Once the requirements are met move forward on "How to run".

## How to run?
### Feeling lazy?
1. ```cd source/```
2. If ```run.sh``` doesn't have executable flag run ```chmod +x run.sh```
3. ```./run.sh -i``` if first time running else ```./run.sh```

### Want to do everything by hand?
Everything inside following brackets ```[]``` are optional parameters to the script. The script may handle the finding of the arduino device itself or you may provide a path to it yourself. The baudrate is changable, default configured in the script is 9600, options for baudrate are displayed with the help of ```python main.py -h```. In the help of the script is also all parameters you can give, as well as description and if there is a name behind it, then there needs to be a value for it to function.

1. change into to the source files directory ```cd source/python```
2. check python version ```python --version```
3. if python == 3.x -> ```python main.py [-h] [-dev arduino_tty_path] [-b baudrate]``` otherwise go to next step
4. Install python if you haven't done it already otherwise go to next step
5. ```python3 main.py [-h] [-dev arduino_tty_path] [-b baudrate]```

### Parameters
Name | Flag | Required | Description
-----|------|----------|------------
help | -h | No | Display the help of the program
arduino_tty_path | -dev, --device | No | The path to a filedescriptor coming from the arduino card e.g. /dev/tty.usbmodem142201 or /dev/ttyACMT01
baudrate | -b, --baudrate | No | The baudrate which the writing is happening on in the serial interface in the form of number of bits per second.

If any of the parameters are supplied to the script then the script will override with those values, unless ````-h```` is supplied then it shows the help.

## The script
What does it do?
1. Gets data from arduino at "arduino_tty_path"
1. Generating graphs each second
1. On exit generates a csv file containing the data from the sensors.

## Useful links
1. https://guides.github.com/features/mastering-markdown/
2. https://education.github.com/git-cheat-sheet-education.pdf
