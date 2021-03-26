EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5700 2500 5600 2500
Wire Wire Line
	5700 2400 5600 2400
Text GLabel 5650 2800 0    50   Input ~ 0
GND_MCU
Text HLabel 5600 2400 0    50   Input ~ 0
CRX
Text HLabel 5600 2500 0    50   Input ~ 0
CTX
Text Label 6500 2600 0    50   ~ 0
CAN_P
Text Label 6500 2700 0    50   ~ 0
CAN_N
$Comp
L Solarteam:CJMCU_MCP2551 U601
U 1 1 60350ACB
P 6050 2650
F 0 "U601" H 6050 3125 50  0000 C CNN
F 1 "CJMCU_MCP2551" H 6050 3034 50  0000 C CNN
F 2 "Solar_team:CJMCU_2551" H 6050 2650 50  0001 C CNN
F 3 "" H 6050 2650 50  0001 C CNN
	1    6050 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 2700 6500 2700
Wire Wire Line
	6400 2600 6500 2600
$Comp
L Connector_Generic:Conn_01x08 J?
U 1 1 605F191C
P 7800 3500
F 0 "J?" H 7880 3492 50  0000 L CNN
F 1 "Conn_01x08" H 7880 3401 50  0000 L CNN
F 2 "" H 7800 3500 50  0001 C CNN
F 3 "~" H 7800 3500 50  0001 C CNN
	1    7800 3500
	1    0    0    -1  
$EndComp
Text Label 7500 3900 2    50   ~ 0
CAN_P
Text Label 7500 3800 2    50   ~ 0
CAN_N
Text GLabel 7500 3200 0    50   Input ~ 0
GND_MCU
Text GLabel 7500 3400 0    50   Input ~ 0
GND_MCU
Text GLabel 7500 3600 0    50   Input ~ 0
GND_MCU
Text GLabel 7500 3300 0    50   Input ~ 0
V_external
Text GLabel 7500 3500 0    50   Input ~ 0
V_external
Text GLabel 7500 3700 0    50   Input ~ 0
V_external
Text GLabel 5650 2900 0    50   Input ~ 0
MCU_5V
Wire Wire Line
	5650 2900 5700 2900
Wire Wire Line
	5650 2800 5700 2800
Wire Wire Line
	7600 3200 7500 3200
Wire Wire Line
	7600 3300 7500 3300
Wire Wire Line
	7600 3400 7500 3400
Wire Wire Line
	7600 3500 7500 3500
Wire Wire Line
	7600 3600 7500 3600
Wire Wire Line
	7600 3700 7500 3700
Wire Wire Line
	7600 3800 7500 3800
Wire Wire Line
	7600 3900 7500 3900
$Comp
L Connector_Generic:Conn_01x08 J?
U 1 1 605FCD1E
P 7800 2600
F 0 "J?" H 7880 2592 50  0000 L CNN
F 1 "Conn_01x08" H 7880 2501 50  0000 L CNN
F 2 "" H 7800 2600 50  0001 C CNN
F 3 "~" H 7800 2600 50  0001 C CNN
	1    7800 2600
	1    0    0    -1  
$EndComp
Text Label 7500 3000 2    50   ~ 0
CAN_P
Text Label 7500 2900 2    50   ~ 0
CAN_N
Text GLabel 7500 2300 0    50   Input ~ 0
GND_MCU
Text GLabel 7500 2500 0    50   Input ~ 0
GND_MCU
Text GLabel 7500 2700 0    50   Input ~ 0
GND_MCU
Text GLabel 7500 2400 0    50   Input ~ 0
V_external
Text GLabel 7500 2600 0    50   Input ~ 0
V_external
Text GLabel 7500 2800 0    50   Input ~ 0
V_external
Wire Wire Line
	7600 2300 7500 2300
Wire Wire Line
	7600 2400 7500 2400
Wire Wire Line
	7600 2500 7500 2500
Wire Wire Line
	7600 2600 7500 2600
Wire Wire Line
	7600 2700 7500 2700
Wire Wire Line
	7600 2800 7500 2800
Wire Wire Line
	7600 2900 7500 2900
Wire Wire Line
	7600 3000 7500 3000
Text Notes 8000 2400 0    50   ~ 0
Power
Text Notes 7950 3300 0    50   ~ 0
Ethernet connector
$EndSCHEMATC
