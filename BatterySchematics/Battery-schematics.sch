EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "MUST Battery schematics"
Date "2020-11-18"
Rev "1.2"
Comp "Malardalen University Solar Team"
Comment1 "Author: Mathias Strand, msd16007"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_DPDT_x2 SW3
U 1 1 5FAC1B6E
P 5900 2100
F 0 "SW3" H 6050 1850 50  0000 C CNN
F 1 "SW_DPDT_x2" H 6050 1950 50  0000 C CNN
F 2 "" H 5900 2100 50  0001 C CNN
F 3 "~" H 5900 2100 50  0001 C CNN
	1    5900 2100
	-1   0    0    1   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5FAC31CD
P 5200 2400
F 0 "BT1" H 5318 2496 50  0000 L CNN
F 1 "Battery_Cell" H 5318 2405 50  0000 L CNN
F 2 "" V 5200 2460 50  0001 C CNN
F 3 "~" V 5200 2460 50  0001 C CNN
	1    5200 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5FAC7545
P 9050 2000
F 0 "R2" V 8843 2000 50  0000 C CNN
F 1 "R" V 8950 2000 50  0000 C CNN
F 2 "" V 8980 2000 50  0001 C CNN
F 3 "~" H 9050 2000 50  0001 C CNN
	1    9050 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Shunt R1
U 1 1 5FAC96AA
P 6500 3200
F 0 "R1" H 6350 3250 50  0000 C CNN
F 1 "R_Shunt" H 6300 3150 50  0000 C CNN
F 2 "" V 6430 3200 50  0001 C CNN
F 3 "~" H 6500 3200 50  0001 C CNN
	1    6500 3200
	-1   0    0    1   
$EndComp
$Comp
L Device:Fuse F1
U 1 1 5FAC9F50
P 4800 2300
F 0 "F1" H 4860 2346 50  0000 L CNN
F 1 "Fuse" H 4860 2255 50  0000 L CNN
F 2 "" V 4730 2300 50  0001 C CNN
F 3 "~" H 4800 2300 50  0001 C CNN
	1    4800 2300
	1    0    0    -1  
$EndComp
Text Notes 3550 2000 0    79   ~ 16
BMS
$Comp
L Device:Fuse F4
U 1 1 5FAC2391
P 6600 1800
F 0 "F4" V 6403 1800 50  0000 C CNN
F 1 "10A" V 6494 1800 50  0000 C CNN
F 2 "" V 6530 1800 50  0001 C CNN
F 3 "~" H 6600 1800 50  0001 C CNN
	1    6600 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 2100 6200 1800
Connection ~ 7100 1800
Wire Wire Line
	7100 1800 7450 1800
Wire Wire Line
	9050 1850 9050 1800
$Comp
L Converter_DCDC:ATA00BB36S-L U1
U 1 1 5FAD0EF9
P 5000 3300
F 0 "U1" V 4954 2970 50  0000 R CNN
F 1 "ATA00BB36S-L" V 5045 2970 50  0000 R CNN
F 2 "Converter_DCDC:Converter_DCDC_Artesyn_ATA_SMD" H 5000 2950 50  0001 C CIN
F 3 "https://www.artesyn.com/power/assets/ata_series_ds_01apr2015_79c25814fd.pdf" H 5000 2850 50  0001 C CNN
	1    5000 3300
	0    -1   1    0   
$EndComp
Wire Wire Line
	5200 2500 5200 2700
Wire Wire Line
	4800 2450 4800 2800
Wire Wire Line
	5200 2200 5700 2200
Wire Wire Line
	4800 1800 4800 2150
Connection ~ 6200 1800
Wire Wire Line
	6200 2100 6100 2100
Connection ~ 5200 2700
Wire Wire Line
	5200 2700 5200 2800
Wire Wire Line
	6500 3400 6500 4100
$Comp
L Connector:Conn_Coaxial J3
U 1 1 5FAE8C21
P 9750 3900
F 0 "J3" V 9800 4050 50  0000 L CNN
F 1 "Conn_Coaxial" V 9700 4050 50  0000 L CNN
F 2 "" H 9750 3900 50  0001 C CNN
F 3 " ~" H 9750 3900 50  0001 C CNN
	1    9750 3900
	0    1    -1   0   
$EndComp
Wire Wire Line
	5200 3800 5200 4000
$Comp
L Device:Fuse F2
U 1 1 5FACBDCA
P 5350 4000
F 0 "F2" V 5153 4000 50  0000 C CNN
F 1 "2A" V 5244 4000 50  0000 C CNN
F 2 "" V 5280 4000 50  0001 C CNN
F 3 "~" H 5350 4000 50  0001 C CNN
	1    5350 4000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 3800 4800 5450
Wire Wire Line
	9550 5100 9550 3900
Wire Wire Line
	9750 5450 9750 4100
Wire Wire Line
	5200 2700 5800 2700
Wire Wire Line
	7100 1800 7100 2950
Wire Notes Line
	4350 1800 4350 4150
Wire Notes Line
	4350 4150 2400 4150
Wire Notes Line
	2400 4150 2400 1800
$Comp
L Regulator_Linear:LT1084-3.3 U2
U 1 1 5FAEAEF1
P 3200 2100
F 0 "U2" H 3200 2342 50  0000 C CNN
F 1 "LT1084-3.3" H 3200 2251 50  0000 C CNN
F 2 "" H 3200 2350 50  0001 C CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/1083ffe.pdf" H 3200 2100 50  0001 C CNN
	1    3200 2100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FB5E005
P 8400 2350
F 0 "#PWR05" H 8400 2100 50  0001 C CNN
F 1 "GND" H 8405 2177 50  0000 C CNN
F 2 "" H 8400 2350 50  0001 C CNN
F 3 "" H 8400 2350 50  0001 C CNN
	1    8400 2350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7100 2950 7450 2950
$Comp
L power:GND #PWR06
U 1 1 5FB5D6EC
P 8400 3500
F 0 "#PWR06" H 8400 3250 50  0001 C CNN
F 1 "GND" H 8405 3327 50  0000 C CNN
F 2 "" H 8400 3500 50  0001 C CNN
F 3 "" H 8400 3500 50  0001 C CNN
	1    8400 3500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9050 2950 9050 2150
Wire Wire Line
	6200 5500 6200 5450
Wire Wire Line
	6100 5450 6100 5500
Text GLabel 7400 4500 0    50   Input ~ 0
K3
Text GLabel 7400 3350 0    50   Input ~ 0
K2
Text GLabel 7400 2200 0    50   Input ~ 0
K1
Text GLabel 6300 5500 3    50   Input ~ 0
K1
Text GLabel 6200 5500 3    50   Input ~ 0
K2
Text GLabel 6100 5500 3    50   Input ~ 0
K3
$Comp
L power:GND #PWR04
U 1 1 5FBBFAAC
P 3200 4000
F 0 "#PWR04" H 3200 3750 50  0001 C CNN
F 1 "GND" H 3350 4000 50  0000 C CNN
F 2 "" H 3200 4000 50  0001 C CNN
F 3 "" H 3200 4000 50  0001 C CNN
	1    3200 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5FBC0118
P 2900 2250
F 0 "#PWR02" H 2900 2000 50  0001 C CNN
F 1 "GND" H 2905 2077 50  0000 C CNN
F 2 "" H 2900 2250 50  0001 C CNN
F 3 "" H 2900 2250 50  0001 C CNN
	1    2900 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 2400 3200 2600
Wire Wire Line
	2900 2100 2900 2250
Wire Notes Line
	2400 1800 4350 1800
$Comp
L MCU_Microchip_ATtiny:ATtiny804-SS U3
U 1 1 5FBDF042
P 3200 3300
F 0 "U3" H 3200 4181 50  0000 C CNN
F 1 "n-BMS" H 3200 3350 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 3200 3300 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny804_1604-Data-Sheet-40002028A.pdf" H 3200 3300 50  0001 C CNN
	1    3200 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3100 4000 3100
Wire Wire Line
	2600 2900 2100 2900
Wire Wire Line
	2100 2900 2100 2450
Wire Wire Line
	2600 3000 1600 3000
Wire Wire Line
	1600 3000 1600 2450
Wire Wire Line
	3800 3600 3800 4300
Wire Wire Line
	3800 3500 3900 3500
Wire Wire Line
	3900 3500 3900 4300
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5FBEE707
P 3900 4500
F 0 "J1" V 3772 4580 50  0000 L CNN
F 1 "Conn_01x02" V 3863 4580 50  0000 L CNN
F 2 "" H 3900 4500 50  0001 C CNN
F 3 "~" H 3900 4500 50  0001 C CNN
	1    3900 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 5450 5350 5450
$Comp
L Device:Fuse F3
U 1 1 5FACA6B1
P 5500 5450
F 0 "F3" V 5600 5450 50  0000 C CNN
F 1 "20A" V 5650 5450 50  0000 C CNN
F 2 "" V 5430 5450 50  0001 C CNN
F 3 "~" H 5500 5450 50  0001 C CNN
	1    5500 5450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5FBF912C
P 5800 2700
F 0 "#PWR03" H 5800 2450 50  0001 C CNN
F 1 "GND" H 5805 2527 50  0000 C CNN
F 2 "" H 5800 2700 50  0001 C CNN
F 3 "" H 5800 2700 50  0001 C CNN
	1    5800 2700
	1    0    0    -1  
$EndComp
Connection ~ 5800 2700
Wire Wire Line
	5800 2700 6500 2700
Text Notes 2150 2900 0    50   ~ 0
Discharge
Text Notes 1100 2000 0    50   ~ 0
Only one can be on at a time
$Comp
L Switch:SW_SPST SW1
U 1 1 5FC0EDE4
P 1600 2250
F 0 "SW1" V 1646 2162 50  0000 R CNN
F 1 "SW_SPST" V 1555 2162 50  0000 R CNN
F 2 "" H 1600 2250 50  0001 C CNN
F 3 "~" H 1600 2250 50  0001 C CNN
	1    1600 2250
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_SPST SW2
U 1 1 5FC123B6
P 2100 2250
F 0 "SW2" V 2146 2162 50  0000 R CNN
F 1 "SW_SPST" V 2055 2162 50  0000 R CNN
F 2 "" H 2100 2250 50  0001 C CNN
F 3 "~" H 2100 2250 50  0001 C CNN
	1    2100 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1550 2050 1600 2050
Connection ~ 1600 2050
Wire Wire Line
	1600 2050 2100 2050
Text Notes 3600 4650 0    50   ~ 0
CAN_H & CAN_L
Text Notes 3950 4250 0    50   ~ 0
CAN_L: brown
Text Notes 3250 4250 0    50   ~ 0
CAN_H: white
Wire Wire Line
	6300 5500 6300 5450
Text Notes 550  700  0    79   ~ 0
Based on the old schematics. This is not for manufacturing, only for learning purposes
Text Notes 5950 2300 0    50   ~ 0
Main switch on battery
Text GLabel 6300 3300 0    50   Input ~ 0
V+
Text GLabel 6300 3100 0    50   Input ~ 0
V-
Text GLabel 2600 3100 0    50   Input ~ 0
V+
Text GLabel 2600 3200 0    50   Input ~ 0
V-
Text GLabel 1550 2050 0    50   Input ~ 0
GND_GPIO
Text GLabel 5500 4000 2    50   Input ~ 0
GND_GPIO
Connection ~ 5200 4000
Wire Wire Line
	5200 4000 5200 5100
Wire Wire Line
	6500 3000 6500 2700
Wire Wire Line
	8800 3650 9750 3650
Connection ~ 9550 3250
Wire Wire Line
	9550 3250 9550 3450
Wire Wire Line
	9550 1800 9550 3250
$Comp
L Connector:Conn_Coaxial_x2 J2
U 1 1 5FAE7C6A
P 9750 3350
F 0 "J2" H 9850 3325 50  0000 L CNN
F 1 "Conn_Coaxial_x2" H 9850 3234 50  0000 L CNN
F 2 "" H 9750 3250 50  0001 C CNN
F 3 " ~" H 9750 3250 50  0001 C CNN
	1    9750 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 5100 9550 5100
Wire Wire Line
	6750 1800 7100 1800
Wire Wire Line
	4800 1800 6200 1800
Wire Wire Line
	6200 1800 6450 1800
Text GLabel 6000 5500 3    50   Input ~ 0
BMS_pwr
Wire Wire Line
	5650 5450 6000 5450
Text GLabel 3200 1700 0    50   Input ~ 0
BMS_pwr
Wire Wire Line
	3200 1700 3200 1800
$Comp
L Battery-schematics-rescue:GV200BAB-1-Solar_team_library K?
U 1 1 5FE02FF4
P 7900 4500
F 0 "K?" H 7900 4600 50  0000 C CNN
F 1 "GV200BAB-1" H 7950 5050 50  0000 C CNN
F 2 "" H 7900 4400 50  0001 C CNN
F 3 "" H 7900 4400 50  0001 C CNN
	1    7900 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 4100 6500 4100
Wire Wire Line
	8350 4100 8800 4100
Wire Wire Line
	8800 4100 8800 3650
Wire Wire Line
	7400 4500 7450 4500
$Comp
L Battery-schematics-rescue:GV200BAB-1-Solar_team_library K?
U 1 1 5FE7E1D8
P 7900 3350
F 0 "K?" H 7900 3450 50  0000 C CNN
F 1 "GV200BAB-1" H 7950 3900 50  0000 C CNN
F 2 "" H 7900 3250 50  0001 C CNN
F 3 "" H 7900 3250 50  0001 C CNN
	1    7900 3350
	1    0    0    -1  
$EndComp
$Comp
L Battery-schematics-rescue:GV200BAB-1-Solar_team_library K?
U 1 1 5FE96AE9
P 7900 2200
F 0 "K?" H 7900 2300 50  0000 C CNN
F 1 "GV200BAB-1" H 7950 2750 50  0000 C CNN
F 2 "" H 7900 2100 50  0001 C CNN
F 3 "" H 7900 2100 50  0001 C CNN
	1    7900 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3350 7450 3350
Wire Wire Line
	7400 2200 7450 2200
Wire Wire Line
	6300 3100 6350 3100
Wire Wire Line
	6300 3300 6350 3300
Wire Wire Line
	8350 4500 8400 4500
Wire Wire Line
	8350 3650 8400 3650
Wire Wire Line
	8400 3650 8400 3500
Wire Wire Line
	8400 3350 8350 3350
Wire Wire Line
	8400 3350 8400 3500
Connection ~ 8400 3500
Wire Wire Line
	8400 4500 8400 4650
Connection ~ 8400 4650
Wire Wire Line
	8350 4800 8400 4800
$Comp
L power:GND #PWR07
U 1 1 5FB57C37
P 8400 4650
F 0 "#PWR07" H 8400 4400 50  0001 C CNN
F 1 "GND" H 8405 4477 50  0000 C CNN
F 2 "" H 8400 4650 50  0001 C CNN
F 3 "" H 8400 4650 50  0001 C CNN
	1    8400 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8400 4800 8400 4650
Wire Wire Line
	8350 2200 8400 2200
Wire Wire Line
	8400 2200 8400 2350
Wire Wire Line
	8400 2350 8400 2500
Wire Wire Line
	8400 2500 8350 2500
Connection ~ 8400 2350
Text GLabel 7400 2500 0    50   Input ~ 0
aux_1
Text GLabel 7400 3650 0    50   Input ~ 0
aux_2
Text GLabel 7400 4800 0    50   Input ~ 0
aux_3
Wire Wire Line
	7400 2500 7450 2500
Wire Wire Line
	7400 3650 7450 3650
Wire Wire Line
	7400 4800 7450 4800
Wire Wire Line
	3800 3200 4000 3200
Wire Wire Line
	3800 3000 4000 3000
Text GLabel 4000 3200 2    50   Input ~ 0
aux_3
Text GLabel 4000 3100 2    50   Input ~ 0
aux_2
Text GLabel 4000 3000 2    50   Input ~ 0
aux_1
Connection ~ 6100 5450
Wire Wire Line
	6100 5450 6200 5450
Connection ~ 6200 5450
Connection ~ 6300 5450
Wire Wire Line
	6300 5450 9750 5450
Wire Wire Line
	6200 5450 6300 5450
Wire Wire Line
	6000 5500 6000 5450
Connection ~ 6000 5450
Wire Wire Line
	6000 5450 6100 5450
Text Notes 1600 3100 0    50   ~ 0
Charge
Wire Wire Line
	8350 1800 9050 1800
Connection ~ 9050 1800
Wire Wire Line
	9050 1800 9550 1800
Wire Wire Line
	9050 2950 8350 2950
Text Notes 10250 1750 2    50   ~ 0
Power resistor for current limited charging
$EndSCHEMATC
