EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R_POT RV701
U 1 1 603BBB08
P 3450 1750
F 0 "RV701" H 3400 1700 50  0000 R CNN
F 1 "R_POT" H 3380 1795 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 3450 1750 50  0001 C CNN
F 3 "~" H 3450 1750 50  0001 C CNN
	1    3450 1750
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT RV702
U 1 1 603BBB0E
P 3950 1750
F 0 "RV702" H 4250 1500 50  0000 R CNN
F 1 "R_POT" H 4250 1600 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 3950 1750 50  0001 C CNN
F 3 "~" H 3950 1750 50  0001 C CNN
	1    3950 1750
	1    0    0    1   
$EndComp
$Comp
L Device:LED D701
U 1 1 603BBB14
P 3850 6050
F 0 "D701" H 3850 5850 50  0000 C CNN
F 1 "LED" H 3850 5950 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 3850 6050 50  0001 C CNN
F 3 "~" H 3850 6050 50  0001 C CNN
	1    3850 6050
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R701
U 1 1 603BBB1A
P 3850 6300
F 0 "R701" V 3750 6300 50  0000 C CNN
F 1 "R_Small" V 3950 6300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3850 6300 50  0001 C CNN
F 3 "~" H 3850 6300 50  0001 C CNN
	1    3850 6300
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_DIP_x08 SW704
U 1 1 603BBB20
P 3700 4700
F 0 "SW704" H 3700 5367 50  0000 C CNN
F 1 "SW_DIP_x08" H 3700 5276 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 3700 4700 50  0001 C CNN
F 3 "~" H 3700 4700 50  0001 C CNN
	1    3700 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 1600 3950 1600
Wire Wire Line
	3450 1900 3950 1900
Text GLabel 3450 2100 0    50   Input ~ 0
TRM_GND
Text Label 3950 1400 0    50   ~ 0
TRM_23
Text Label 3100 1750 2    50   ~ 0
TRM_02
Text Label 3450 2050 2    50   ~ 0
TRM_21
Text Label 3950 2050 0    50   ~ 0
TRM_04
Text Label 4300 1750 0    50   ~ 0
TRM_22
Wire Wire Line
	3950 1600 3950 1400
Connection ~ 3950 1600
Wire Wire Line
	3100 1750 3300 1750
Wire Wire Line
	3450 1900 3450 2100
Connection ~ 3450 1900
Wire Wire Line
	3950 2050 3950 1900
Connection ~ 3950 1900
Wire Wire Line
	4300 1750 4100 1750
Text Label 3300 2550 2    50   ~ 0
TRM_01
Text Label 3900 2550 0    50   ~ 0
TRM_20
Text Label 3300 2950 2    50   ~ 0
TRM_25
Text Label 3900 3350 0    50   ~ 0
TRM_06
Text Label 3900 2950 0    50   ~ 0
TRM_7
Text Label 3300 3350 2    50   ~ 0
TRM_05
Text Label 4100 6050 0    50   ~ 0
TRM_14
Text Label 3550 6050 2    50   ~ 0
TRM_15
Wire Wire Line
	3300 3350 3400 3350
Wire Wire Line
	3800 3350 3900 3350
Wire Wire Line
	3300 2950 3400 2950
Wire Wire Line
	3900 2950 3800 2950
Wire Wire Line
	3400 2550 3300 2550
Wire Wire Line
	3900 2550 3800 2550
Wire Wire Line
	3550 6050 3700 6050
Wire Wire Line
	4000 6050 4050 6050
Wire Wire Line
	4050 6050 4050 6300
Wire Wire Line
	4050 6300 3950 6300
Connection ~ 4050 6050
Wire Wire Line
	4050 6050 4100 6050
Text GLabel 3550 6300 0    50   Input ~ 0
GND_MCU
Wire Wire Line
	3550 6300 3750 6300
Text Label 4100 4300 0    50   ~ 0
TRM_01
Wire Wire Line
	4100 4300 4000 4300
Wire Wire Line
	4100 4400 4000 4400
Wire Wire Line
	4100 4500 4000 4500
Wire Wire Line
	4100 4600 4000 4600
Wire Wire Line
	4100 4700 4000 4700
Wire Wire Line
	4100 4800 4000 4800
Wire Wire Line
	4100 4900 4000 4900
Wire Wire Line
	4100 5000 4000 5000
Text Label 4100 4400 0    50   ~ 0
TRM_02
Text Label 4100 4600 0    50   ~ 0
TRM_22
Text Label 4100 4900 0    50   ~ 0
TRM_25
Text Label 4100 4800 0    50   ~ 0
TRM_05
Text Label 4100 5000 0    50   ~ 0
TRM_15
Wire Wire Line
	3400 5000 3300 5000
Wire Wire Line
	3400 4900 3300 4900
Wire Wire Line
	3400 4800 3300 4800
Wire Wire Line
	3400 4700 3300 4700
Wire Wire Line
	3400 4600 3300 4600
Wire Wire Line
	3400 4500 3300 4500
Wire Wire Line
	3400 4400 3300 4400
Wire Wire Line
	3400 4300 3300 4300
Text GLabel 4100 4700 2    50   Input ~ 0
TRM_GND
Text GLabel 3300 4700 0    50   Input ~ 0
GND_MCU
Text Label 6250 5150 0    50   ~ 0
TRM_01
Wire Wire Line
	6150 2350 6250 2350
Wire Wire Line
	6150 2550 6250 2550
Wire Wire Line
	6150 3950 6250 3950
Wire Wire Line
	6150 4050 6250 4050
Wire Wire Line
	6150 4150 6250 4150
Wire Wire Line
	6150 4350 6250 4350
Wire Wire Line
	6150 4450 6250 4450
Wire Wire Line
	6150 4550 6250 4550
Wire Wire Line
	6150 4650 6250 4650
Wire Wire Line
	6150 4750 6250 4750
Wire Wire Line
	6150 4850 6250 4850
Wire Wire Line
	6150 4950 6250 4950
Wire Wire Line
	6150 5050 6250 5050
Wire Wire Line
	6150 5150 6250 5150
Text Label 6250 4950 0    50   ~ 0
TRM_02
Text Label 6250 4650 0    50   ~ 0
TRM_22
Text Label 6250 4050 0    50   ~ 0
TRM_25
Text Label 6250 4350 0    50   ~ 0
TRM_05
Text Label 6250 2350 0    50   ~ 0
TRM_15
Text Label 6250 5050 0    50   ~ 0
TRM_20
Text Label 6250 3950 0    50   ~ 0
TRM_7
Text Label 6250 4150 0    50   ~ 0
TRM_06
Text Label 6250 4550 0    50   ~ 0
TRM_04
Text Label 6250 4450 0    50   ~ 0
TRM_23
Text Label 6250 4750 0    50   ~ 0
TRM_03
Text Label 6250 4850 0    50   ~ 0
TRM_21
Text Label 6250 2550 0    50   ~ 0
TRM_14
Connection ~ 3450 1600
Wire Wire Line
	3450 1600 3450 1350
Text Label 3450 1400 0    50   ~ 0
TRM_03
Text GLabel 3450 1350 0    50   Input ~ 0
TRM_VDD
Text Notes 3900 2600 0    50   ~ 0
Motor controller\n
Text Notes 3900 3000 0    50   ~ 0
Forward/reverse\n
Text Notes 3900 3400 0    50   ~ 0
Power/Eco\n
Text GLabel 3300 4500 0    50   Input ~ 0
MCU_5V
NoConn ~ 6150 1550
NoConn ~ 6150 1650
NoConn ~ 6150 1750
NoConn ~ 6150 1850
NoConn ~ 6150 1950
NoConn ~ 6150 2050
NoConn ~ 6150 2150
$Comp
L Connector:DB37_Female_MountingHoles J701
U 1 1 603BBB99
P 5850 3350
F 0 "J701" H 6030 3259 50  0000 L CNN
F 1 "DB37_Female_MountingHoles" V 6050 3450 50  0000 L CNN
F 2 "Connector_Dsub:DSUB-37_Female_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm" H 5850 3350 50  0001 C CNN
F 3 " ~" H 5850 3350 50  0001 C CNN
	1    5850 3350
	-1   0    0    1   
$EndComp
NoConn ~ 6150 2250
NoConn ~ 6150 2450
NoConn ~ 6150 2650
NoConn ~ 6150 2750
NoConn ~ 6150 2850
NoConn ~ 6150 2950
NoConn ~ 6150 3050
NoConn ~ 6150 3150
NoConn ~ 6150 3250
NoConn ~ 6150 3350
NoConn ~ 6150 3450
NoConn ~ 6150 3550
NoConn ~ 6150 3650
NoConn ~ 6150 3750
NoConn ~ 6150 3850
NoConn ~ 6150 4250
Text GLabel 4100 4500 2    50   Input ~ 0
TRM_VDD
Text Notes 2650 1850 0    50   ~ 0
Acc volume\n
Text Notes 4300 1850 0    50   ~ 0
Brake volume\n
$Comp
L Switch:SW_SPST SW701
U 1 1 603BBBB2
P 3600 2550
F 0 "SW701" H 3600 2785 50  0000 C CNN
F 1 "SW_SPST" H 3600 2694 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 3600 2550 50  0001 C CNN
F 3 "~" H 3600 2550 50  0001 C CNN
	1    3600 2550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW702
U 1 1 603BBBB8
P 3600 2950
F 0 "SW702" H 3600 3185 50  0000 C CNN
F 1 "SW_SPST" H 3600 3094 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 3600 2950 50  0001 C CNN
F 3 "~" H 3600 2950 50  0001 C CNN
	1    3600 2950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW703
U 1 1 603BBBBE
P 3600 3350
F 0 "SW703" H 3600 3585 50  0000 C CNN
F 1 "SW_SPST" H 3600 3494 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 3600 3350 50  0001 C CNN
F 3 "~" H 3600 3350 50  0001 C CNN
	1    3600 3350
	1    0    0    -1  
$EndComp
Text GLabel 5800 1350 0    50   Input ~ 0
GND
Wire Wire Line
	5800 1350 5850 1350
Text HLabel 3300 4300 0    50   Input ~ 0
MC_sw
Text HLabel 3300 4400 0    50   Input ~ 0
Acc_vol
Text HLabel 3300 4600 0    50   Input ~ 0
Brake_vol
Text HLabel 3300 4800 0    50   Input ~ 0
P-E_sw
Text HLabel 3300 4900 0    50   Input ~ 0
F-R_sw
Text HLabel 3300 5000 0    50   Input ~ 0
MC_LED
$EndSCHEMATC
