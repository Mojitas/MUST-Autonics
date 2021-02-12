# Software
All the software developed for the external communication system is to be put in this folder.
Currently the software includes a logger and code for the central device which is the receiver in the solar car.
The software will include programs, ommunication, loggers, debuggers and other software developed for the external communication.
The TODO folder is how it was supposed to be implemented, but is not since some things are wrong with the code and therefore it's put in TODO to be completed later by someone else.

## Structure
```
root (this)
   \| embedded-code
    | TODO
       \| sender
        | receiver
    | logger_nrf52840
       \| configs
        | logs
        | modules
        | plots
        | main.py
        | .gitignore
```

## Code for Central/Peripheral
The code for the central(receiver) is written for mbed and uses platformio.
### How to setup platformio
1. Make a directory where you want to put the code
2. Open a terminal and type `pio init -d . --ide <ide> -b nrf52840_dk` where `<ide>` is the ide you'll be developing in.
3. Change framework from arduino to mbed in `platformio.ini`
4. Make a file `main.cpp` in `src`-folder and write:
```cpp
#include <mbed.h>
#include <ble/BLE.h>

using namespace std::chrono;
using namespace std::literals::chrono_literals;

int main(void)
{
  //Some example code to see that it is working
  DigitalOut _led1(LED1);
  const std::chrono::milliseconds delay = 500ms;

  while (true)
  {
    _led1 = !_led1;
    ThisThread::sleep_for(delay)
  }
}
```
5. Execute `pio run`, it might take a while so take a coffee while waiting.
6. If no errors while compiling then the code should work when uploaded to the board and you should see LED1 blinking with a 500ms delay.
7. If you see the led blinking you can start coding in mbed using an ide of your choice.

#### Side notes
You might want to change monitor speed to 115200 in platformio.ini by setting `monitor_speed = 115200` for faster output.

## LED Configurations
|LEDs | State | Blink Rate |
|-----|-------|------------|
|LED1 | \<\<blinking\>\> Scanning | 500ms |
|<br> |       |            |
|LED2 | \<\<blinking\>\> Advertising | 250ms |
|<br> |       |            |
|LED3 |\<\<blinking\>\> Connecting| 300ms |
|     |\<\<on\>\> Connected|    |
|LED4 |\<\<on\>\> Sending/receiving data|
|     |\<\<blinking\>\> Waiting to send/receive| 400ms |
|     |\<\<off\>\> Transmission done|

<!-- Remove the comment if there is any button configuration
# Button configurations
| Button | Action |
|--------|--------|
-->

## logger_nrf52840
A logger made for solar team that reads the output from the nrf52840 on a computer.
Its modular so any module can be removed with small changes in the other module files.

### Modules
The current structure for modules and its modules in the logger are seen below.
```
root (modules)
  \| argumentparsers
      \| arguments.py
       | commands.py
   | logger
      \| autodetect.py
       | DataParser.py
       | DataReader.py
   | tests
      \| TBD (To be developed)
```

### Data Parser
The dataparser currently follows the output of the nRF52 BLE Long Range Demo from Nordic found at [1].
It can follow any ouput of choice because it uses the re library for python which uses regular expressions
to match strings that should be parsed. The re library can be found at [2] and a good tester for regex
can be found at [3]. In the regex online tester[3] you need to change from PHP to Python on the left
because the regex will be used in the python library re.

[1]: https://github.com/NordicPlayground/nRF52-ble-long-range-demo
[2]: https://docs.python.org/3/library/re.html
[3]: https://regex101.com/
