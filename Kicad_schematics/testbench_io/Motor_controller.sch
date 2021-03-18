EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 7
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
P 3700 5100
F 0 "D701" H 3700 4900 50  0000 C CNN
F 1 "LED" H 3700 5000 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 3700 5100 50  0001 C CNN
F 3 "~" H 3700 5100 50  0001 C CNN
	1    3700 5100
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R701
U 1 1 603BBB1A
P 3700 5350
F 0 "R701" V 3600 5350 50  0000 C CNN
F 1 "R_Small" V 3800 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3700 5350 50  0001 C CNN
F 3 "~" H 3700 5350 50  0001 C CNN
	1    3700 5350
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_DIP_x08 SW704
U 1 1 603BBB20
P 3600 4300
F 0 "SW704" H 3600 4967 50  0000 C CNN
F 1 "SW_DIP_x08" H 3600 4876 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 3600 4300 50  0001 C CNN
F 3 "~" H 3600 4300 50  0001 C CNN
	1    3600 4300
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
Text Label 3950 5100 0    50   ~ 0
TRM_14
Text Label 3400 5100 2    50   ~ 0
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
	3400 5100 3550 5100
Wire Wire Line
	3850 5100 3900 5100
Wire Wire Line
	3900 5100 3900 5350
Wire Wire Line
	3900 5350 3800 5350
Connection ~ 3900 5100
Wire Wire Line
	3900 5100 3950 5100
Text GLabel 3400 5350 0    50   Input ~ 0
GND_MCU
Wire Wire Line
	3400 5350 3600 5350
Text Label 4000 3900 0    50   ~ 0
TRM_01
Wire Wire Line
	4000 3900 3900 3900
Wire Wire Line
	4000 4000 3900 4000
Wire Wire Line
	4000 4100 3900 4100
Wire Wire Line
	4000 4200 3900 4200
Wire Wire Line
	4000 4300 3900 4300
Wire Wire Line
	4000 4400 3900 4400
Wire Wire Line
	4000 4500 3900 4500
Wire Wire Line
	4000 4600 3900 4600
Text Label 4000 4000 0    50   ~ 0
TRM_02
Text Label 4000 4200 0    50   ~ 0
TRM_22
Text Label 4000 4500 0    50   ~ 0
TRM_25
Text Label 4000 4400 0    50   ~ 0
TRM_05
Text Label 4000 4600 0    50   ~ 0
TRM_15
Wire Wire Line
	3300 4600 3200 4600
Wire Wire Line
	3300 4500 3200 4500
Wire Wire Line
	3300 4400 3200 4400
Wire Wire Line
	3300 4300 3200 4300
Wire Wire Line
	3300 4200 3200 4200
Wire Wire Line
	3300 4100 3200 4100
Wire Wire Line
	3300 4000 3200 4000
Wire Wire Line
	3300 3900 3200 3900
Text GLabel 4000 4300 2    50   Input ~ 0
TRM_GND
Text GLabel 3200 4300 0    50   Input ~ 0
GND_MCU
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
Text GLabel 3200 4100 0    50   Input ~ 0
MCU_5V
Text GLabel 4000 4100 2    50   Input ~ 0
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
F 2 "Solar_team:MFP120" H 3600 2550 50  0001 C CNN
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
F 2 "Solar_team:MFP120" H 3600 2950 50  0001 C CNN
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
F 2 "Solar_team:MFP120" H 3600 3350 50  0001 C CNN
F 3 "~" H 3600 3350 50  0001 C CNN
	1    3600 3350
	1    0    0    -1  
$EndComp
Text GLabel 6500 1350 0    50   Input ~ 0
GND
Text HLabel 3200 3900 0    50   Input ~ 0
MC_sw
Text HLabel 3200 4000 0    50   Input ~ 0
Acc_vol
Text HLabel 3200 4200 0    50   Input ~ 0
Brake_vol
Text HLabel 3200 4400 0    50   Input ~ 0
P-E_sw
Text HLabel 3200 4500 0    50   Input ~ 0
F-R_sw
Text HLabel 3200 4600 0    50   Input ~ 0
MC_LED
$Comp
L Connector:DB37_Male_MountingHoles J701
U 1 1 60491720
P 6700 3350
F 0 "J701" H 6880 3272 50  0000 L CNN
F 1 "DB37_Male_MountingHoles" H 6880 3363 50  0000 L CNN
F 2 "Solar_team:Wurth_Dsub_37_angled_male_8.08mm" H 6700 3350 50  0001 C CNN
F 3 " ~" H 6700 3350 50  0001 C CNN
	1    6700 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	6500 1350 6700 1350
NoConn ~ 7100 2450
NoConn ~ 7100 2850
NoConn ~ 7100 2950
NoConn ~ 7100 3050
NoConn ~ 7100 3150
NoConn ~ 7100 3250
NoConn ~ 7100 3350
NoConn ~ 7100 3450
NoConn ~ 7100 3550
NoConn ~ 7100 3650
NoConn ~ 7100 3750
NoConn ~ 7100 3850
NoConn ~ 7100 3950
NoConn ~ 7100 4050
NoConn ~ 7100 4250
NoConn ~ 7100 4450
NoConn ~ 7100 4550
NoConn ~ 7100 4650
NoConn ~ 7100 4750
NoConn ~ 7100 4850
NoConn ~ 7100 4950
NoConn ~ 7100 5050
NoConn ~ 7100 5150
Text Label 7100 4150 0    50   ~ 0
TRM_14
Text Label 7100 1850 0    50   ~ 0
TRM_21
Text Label 7100 1950 0    50   ~ 0
TRM_03
Text Label 7100 2250 0    50   ~ 0
TRM_23
Text Label 7100 2150 0    50   ~ 0
TRM_04
Text Label 7100 2550 0    50   ~ 0
TRM_06
Text Label 7100 2750 0    50   ~ 0
TRM_7
Text Label 7100 1650 0    50   ~ 0
TRM_20
Text Label 7100 4350 0    50   ~ 0
TRM_15
Text Label 7100 2350 0    50   ~ 0
TRM_05
Text Label 7100 2650 0    50   ~ 0
TRM_25
Text Label 7100 2050 0    50   ~ 0
TRM_22
Text Label 7100 1750 0    50   ~ 0
TRM_02
Wire Wire Line
	7000 1550 7100 1550
Wire Wire Line
	7000 1650 7100 1650
Wire Wire Line
	7000 1750 7100 1750
Wire Wire Line
	7000 1850 7100 1850
Wire Wire Line
	7000 1950 7100 1950
Wire Wire Line
	7000 2050 7100 2050
Wire Wire Line
	7000 2150 7100 2150
Wire Wire Line
	7000 2250 7100 2250
Wire Wire Line
	7000 2350 7100 2350
Wire Wire Line
	7000 2550 7100 2550
Wire Wire Line
	7000 2650 7100 2650
Wire Wire Line
	7000 2750 7100 2750
Wire Wire Line
	7000 4150 7100 4150
Wire Wire Line
	7000 4350 7100 4350
Text Label 7100 1550 0    50   ~ 0
TRM_01
Wire Wire Line
	7000 2450 7100 2450
Wire Wire Line
	7000 2850 7100 2850
Wire Wire Line
	7000 2950 7100 2950
Wire Wire Line
	7000 3050 7100 3050
Wire Wire Line
	7000 3150 7100 3150
Wire Wire Line
	7000 3250 7100 3250
Wire Wire Line
	7000 3350 7100 3350
Wire Wire Line
	7000 3450 7100 3450
Wire Wire Line
	7000 3550 7100 3550
Wire Wire Line
	7000 3650 7100 3650
Wire Wire Line
	7000 3750 7100 3750
Wire Wire Line
	7000 3850 7100 3850
Wire Wire Line
	7000 3950 7100 3950
Wire Wire Line
	7000 4050 7100 4050
Wire Wire Line
	7000 4250 7100 4250
Wire Wire Line
	7000 4450 7100 4450
Wire Wire Line
	7000 4550 7100 4550
Wire Wire Line
	7000 4650 7100 4650
Wire Wire Line
	7000 4750 7100 4750
Wire Wire Line
	7000 4850 7100 4850
Wire Wire Line
	7000 4950 7100 4950
Wire Wire Line
	7000 5050 7100 5050
Wire Wire Line
	7000 5150 7100 5150
$EndSCHEMATC
