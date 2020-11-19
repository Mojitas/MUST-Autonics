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
P 6800 1650
F 0 "SW3" H 6800 1325 50  0000 C CNN
F 1 "SW_DPDT_x2" H 6800 1416 50  0000 C CNN
F 2 "" H 6800 1650 50  0001 C CNN
F 3 "~" H 6800 1650 50  0001 C CNN
	1    6800 1650
	-1   0    0    1   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5FAC31CD
P 5700 1950
F 0 "BT1" H 5818 2046 50  0000 L CNN
F 1 "Battery_Cell" H 5818 1955 50  0000 L CNN
F 2 "" V 5700 2010 50  0001 C CNN
F 3 "~" V 5700 2010 50  0001 C CNN
	1    5700 1950
	1    0    0    -1  
$EndComp
$Comp
L Relay:DIPxx-1Axx-11x K1
U 1 1 5FAC473E
P 8400 1550
F 0 "K1" V 8867 1550 50  0000 C CNN
F 1 "DIPxx-1Axx-11x" V 8776 1550 50  0000 C CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 8750 1500 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 8400 1550 50  0001 C CNN
	1    8400 1550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 5FAC7545
P 9050 2300
F 0 "R2" V 8843 2300 50  0000 C CNN
F 1 "R" V 8950 2300 50  0000 C CNN
F 2 "" V 8980 2300 50  0001 C CNN
F 3 "~" H 9050 2300 50  0001 C CNN
	1    9050 2300
	0    1    1    0   
$EndComp
$Comp
L Relay:DIPxx-1Axx-11x K3
U 1 1 5FAC7BA1
P 8400 3450
F 0 "K3" V 8867 3450 50  0000 C CNN
F 1 "DIPxx-1Axx-11x" V 8776 3450 50  0000 C CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 8750 3400 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 8400 3450 50  0001 C CNN
	1    8400 3450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Shunt R1
U 1 1 5FAC96AA
P 7300 2750
F 0 "R1" H 7150 2800 50  0000 C CNN
F 1 "R_Shunt" H 7100 2700 50  0000 C CNN
F 2 "" V 7230 2750 50  0001 C CNN
F 3 "~" H 7300 2750 50  0001 C CNN
	1    7300 2750
	-1   0    0    1   
$EndComp
$Comp
L Device:Fuse F1
U 1 1 5FAC9F50
P 5300 1850
F 0 "F1" H 5360 1896 50  0000 L CNN
F 1 "Fuse" H 5360 1805 50  0000 L CNN
F 2 "" V 5230 1850 50  0001 C CNN
F 3 "~" H 5300 1850 50  0001 C CNN
	1    5300 1850
	1    0    0    -1  
$EndComp
Text Notes 3300 1800 0    79   ~ 16
BMS
$Comp
L Device:Fuse F4
U 1 1 5FAC2391
P 7400 1350
F 0 "F4" V 7203 1350 50  0000 C CNN
F 1 "10A" V 7294 1350 50  0000 C CNN
F 2 "" V 7330 1350 50  0001 C CNN
F 3 "~" H 7400 1350 50  0001 C CNN
	1    7400 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 1650 7050 1350
Connection ~ 7800 1350
Wire Wire Line
	7800 1350 8100 1350
Wire Wire Line
	9200 2300 9200 1350
Wire Wire Line
	9200 1350 8700 1350
$Comp
L Converter_DCDC:ATA00BB36S-L U1
U 1 1 5FAD0EF9
P 5500 2850
F 0 "U1" V 5454 2520 50  0000 R CNN
F 1 "ATA00BB36S-L" V 5545 2520 50  0000 R CNN
F 2 "Converter_DCDC:Converter_DCDC_Artesyn_ATA_SMD" H 5500 2500 50  0001 C CIN
F 3 "https://www.artesyn.com/power/assets/ata_series_ds_01apr2015_79c25814fd.pdf" H 5500 2400 50  0001 C CNN
	1    5500 2850
	0    -1   1    0   
$EndComp
Wire Wire Line
	5700 2050 5700 2250
Wire Wire Line
	5300 2000 5300 2350
Wire Wire Line
	5700 1750 6600 1750
Wire Wire Line
	5300 1350 5300 1700
Connection ~ 7050 1350
Wire Wire Line
	7050 1650 7000 1650
Connection ~ 5700 2250
Wire Wire Line
	5700 2250 5700 2350
Wire Wire Line
	7300 2950 7300 3250
$Comp
L Connector:Conn_Coaxial J3
U 1 1 5FAE8C21
P 9900 2850
F 0 "J3" V 9950 3000 50  0000 L CNN
F 1 "Conn_Coaxial" V 9850 3000 50  0000 L CNN
F 2 "" H 9900 2850 50  0001 C CNN
F 3 " ~" H 9900 2850 50  0001 C CNN
	1    9900 2850
	0    1    -1   0   
$EndComp
Connection ~ 9200 1350
Wire Wire Line
	5700 3350 5700 3550
$Comp
L Device:Fuse F2
U 1 1 5FACBDCA
P 5850 3550
F 0 "F2" V 5653 3550 50  0000 C CNN
F 1 "2A" V 5744 3550 50  0000 C CNN
F 2 "" V 5780 3550 50  0001 C CNN
F 3 "~" H 5850 3550 50  0001 C CNN
	1    5850 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5300 3350 5300 4300
Wire Wire Line
	8700 3250 9300 3250
Wire Wire Line
	9700 3950 9700 2850
Wire Wire Line
	9900 4300 9900 3050
Wire Wire Line
	5700 2250 6550 2250
Wire Wire Line
	7800 1350 7800 2300
$Comp
L Transistor_FET:2N7000 Q3
U 1 1 5FAD6ABB
P 4300 3250
F 0 "Q3" V 4550 3300 50  0000 L CNN
F 1 "2N7000" V 4550 2950 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 4500 3175 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 4300 3250 50  0001 L CNN
	1    4300 3250
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET:2N7000 Q1
U 1 1 5FAD9182
P 4300 2150
F 0 "Q1" V 4550 2200 50  0000 L CNN
F 1 "2N7000" V 4550 1850 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 4500 2075 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 4300 2150 50  0001 L CNN
	1    4300 2150
	0    -1   -1   0   
$EndComp
Wire Notes Line
	4800 1600 4800 3950
Wire Notes Line
	4800 3950 2050 3950
Wire Notes Line
	2050 3950 2050 1600
$Comp
L Regulator_Linear:LT1084-3.3 U2
U 1 1 5FAEAEF1
P 2950 1900
F 0 "U2" H 2950 2142 50  0000 C CNN
F 1 "LT1084-3.3" H 2950 2051 50  0000 C CNN
F 2 "" H 2950 2150 50  0001 C CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/1083ffe.pdf" H 2950 1900 50  0001 C CNN
	1    2950 1900
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:2N7000 Q2
U 1 1 5FAD87E5
P 4300 2700
F 0 "Q2" V 4550 2750 50  0000 L CNN
F 1 "2N7000" V 4550 2400 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 4500 2625 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 4300 2700 50  0001 L CNN
	1    4300 2700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5FB57C37
P 8700 3650
F 0 "#PWR07" H 8700 3400 50  0001 C CNN
F 1 "GND" H 8705 3477 50  0000 C CNN
F 2 "" H 8700 3650 50  0001 C CNN
F 3 "" H 8700 3650 50  0001 C CNN
	1    8700 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FB5E005
P 8700 1750
F 0 "#PWR05" H 8700 1500 50  0001 C CNN
F 1 "GND" H 8705 1577 50  0000 C CNN
F 2 "" H 8700 1750 50  0001 C CNN
F 3 "" H 8700 1750 50  0001 C CNN
	1    8700 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2300 8100 2300
$Comp
L power:GND #PWR06
U 1 1 5FB5D6EC
P 8700 2700
F 0 "#PWR06" H 8700 2450 50  0001 C CNN
F 1 "GND" H 8705 2527 50  0000 C CNN
F 2 "" H 8700 2700 50  0001 C CNN
F 3 "" H 8700 2700 50  0001 C CNN
	1    8700 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2300 8900 2300
$Comp
L Relay:DIPxx-1Axx-11x K2
U 1 1 5FAC6202
P 8400 2500
F 0 "K2" V 8867 2500 50  0000 C CNN
F 1 "DIPxx-1Axx-11x" V 8776 2500 50  0000 C CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 8750 2450 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 8400 2500 50  0001 C CNN
	1    8400 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3600 2800 3600 2350
Wire Wire Line
	3600 2350 4300 2350
Wire Wire Line
	3550 3000 3800 3000
Wire Wire Line
	3800 3000 3800 3450
Wire Wire Line
	3800 3450 4300 3450
Wire Wire Line
	4100 2050 4100 2600
Wire Wire Line
	4100 2600 4100 3150
Connection ~ 4100 2600
Wire Wire Line
	4550 2600 4500 2600
Wire Wire Line
	4500 3150 4550 3150
Text GLabel 8100 3650 0    50   Input ~ 0
K3
Text GLabel 8100 2700 0    50   Input ~ 0
K2
Text GLabel 8100 1750 0    50   Input ~ 0
K1
Text GLabel 4550 2050 2    50   Input ~ 0
K1
Text GLabel 4550 2600 2    50   Input ~ 0
K2
Text GLabel 4550 3150 2    50   Input ~ 0
K3
$Comp
L power:GND #PWR04
U 1 1 5FBBFAAC
P 2950 3800
F 0 "#PWR04" H 2950 3550 50  0001 C CNN
F 1 "GND" H 3100 3800 50  0000 C CNN
F 2 "" H 2950 3800 50  0001 C CNN
F 3 "" H 2950 3800 50  0001 C CNN
	1    2950 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5FBC0118
P 2650 2050
F 0 "#PWR02" H 2650 1800 50  0001 C CNN
F 1 "GND" H 2655 1877 50  0000 C CNN
F 2 "" H 2650 2050 50  0001 C CNN
F 3 "" H 2650 2050 50  0001 C CNN
	1    2650 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 2200 2950 2400
Wire Wire Line
	2650 1900 2650 2050
Wire Notes Line
	2050 1600 4800 1600
$Comp
L MCU_Microchip_ATtiny:ATtiny804-SS U3
U 1 1 5FBDF042
P 2950 3100
F 0 "U3" H 2950 3981 50  0000 C CNN
F 1 "n-BMS" H 2950 3150 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 2950 3100 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny804_1604-Data-Sheet-40002028A.pdf" H 2950 3100 50  0001 C CNN
	1    2950 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2900 4300 2900
Wire Wire Line
	3550 2800 3600 2800
Wire Wire Line
	2350 2700 1850 2700
Wire Wire Line
	1850 2700 1850 2250
Wire Wire Line
	2350 2800 1350 2800
Wire Wire Line
	1350 2800 1350 2250
Wire Wire Line
	3550 3400 3550 4100
Wire Wire Line
	3550 3300 3650 3300
Wire Wire Line
	3650 3300 3650 4100
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5FBEE707
P 3650 4300
F 0 "J1" V 3522 4380 50  0000 L CNN
F 1 "Conn_01x02" V 3613 4380 50  0000 L CNN
F 2 "" H 3650 4300 50  0001 C CNN
F 3 "~" H 3650 4300 50  0001 C CNN
	1    3650 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	5300 4300 5850 4300
$Comp
L Device:Fuse F3
U 1 1 5FACA6B1
P 6000 4300
F 0 "F3" V 5803 4300 50  0000 C CNN
F 1 "20A" V 5894 4300 50  0000 C CNN
F 2 "" V 5930 4300 50  0001 C CNN
F 3 "~" H 6000 4300 50  0001 C CNN
	1    6000 4300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5FBF912C
P 6550 2250
F 0 "#PWR03" H 6550 2000 50  0001 C CNN
F 1 "GND" H 6555 2077 50  0000 C CNN
F 2 "" H 6550 2250 50  0001 C CNN
F 3 "" H 6550 2250 50  0001 C CNN
	1    6550 2250
	1    0    0    -1  
$EndComp
Connection ~ 6550 2250
Wire Wire Line
	6550 2250 7300 2250
Text Notes 1900 2700 0    50   ~ 0
Discharge
Text Notes 850  1800 0    50   ~ 0
Only one can be on at a time
$Comp
L Switch:SW_SPST SW1
U 1 1 5FC0EDE4
P 1350 2050
F 0 "SW1" V 1396 1962 50  0000 R CNN
F 1 "SW_SPST" V 1305 1962 50  0000 R CNN
F 2 "" H 1350 2050 50  0001 C CNN
F 3 "~" H 1350 2050 50  0001 C CNN
	1    1350 2050
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_SPST SW2
U 1 1 5FC123B6
P 1850 2050
F 0 "SW2" V 1896 1962 50  0000 R CNN
F 1 "SW_SPST" V 1805 1962 50  0000 R CNN
F 2 "" H 1850 2050 50  0001 C CNN
F 3 "~" H 1850 2050 50  0001 C CNN
	1    1850 2050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1300 1850 1350 1850
Connection ~ 1350 1850
Wire Wire Line
	1350 1850 1850 1850
Text Notes 3350 4450 0    50   ~ 0
CAN_H & CAN_L
Text Notes 3700 4050 0    50   ~ 0
CAN_L: brown
Text Notes 3000 4050 0    50   ~ 0
CAN_H: white
Wire Wire Line
	4550 2050 4500 2050
Text Notes 550  700  0    79   ~ 0
Based on the old schematics. This is not for manufacturing, only learning purposes
Text Notes 6450 1900 0    50   ~ 0
Main switch on battery
Text GLabel 7150 2850 0    50   Input ~ 0
V+
Text GLabel 7150 2650 0    50   Input ~ 0
V-
Text GLabel 2350 2900 0    50   Input ~ 0
V+
Text GLabel 2350 3000 0    50   Input ~ 0
V-
Text GLabel 1300 1850 0    50   Input ~ 0
Power_Sw
Text GLabel 6000 3550 2    50   Input ~ 0
Power_Sw
Connection ~ 5700 3550
Wire Wire Line
	5700 3550 5700 3950
Wire Wire Line
	7300 2550 7300 2250
Wire Wire Line
	9200 1350 9700 1350
Wire Wire Line
	9300 3250 9300 2650
Wire Wire Line
	9300 2650 9900 2650
Connection ~ 9700 2250
Wire Wire Line
	9700 2250 9700 2450
Wire Wire Line
	9700 1350 9700 2250
$Comp
L Connector:Conn_Coaxial_x2 J2
U 1 1 5FAE7C6A
P 9900 2350
F 0 "J2" H 10000 2325 50  0000 L CNN
F 1 "Conn_Coaxial_x2" H 10000 2234 50  0000 L CNN
F 2 "" H 9900 2250 50  0001 C CNN
F 3 " ~" H 9900 2250 50  0001 C CNN
	1    9900 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3950 9700 3950
Wire Wire Line
	7300 3250 8100 3250
Wire Wire Line
	7550 1350 7800 1350
Wire Wire Line
	5300 1350 7050 1350
Wire Wire Line
	7050 1350 7250 1350
Text GLabel 6650 4300 3    50   Input ~ 0
MOSFET_pwr
Text GLabel 4100 2050 0    50   Input ~ 0
MOSFET_pwr
Text GLabel 6500 4300 3    50   Input ~ 0
BMS_pwr
Wire Wire Line
	6150 4300 9900 4300
Text GLabel 2950 1500 0    50   Input ~ 0
BMS_pwr
Wire Wire Line
	2950 1500 2950 1600
$EndSCHEMATC
