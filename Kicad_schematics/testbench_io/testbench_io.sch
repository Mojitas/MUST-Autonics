EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 6050 3400 0    50   ~ 0
Battery_pot
Wire Wire Line
	5950 3400 6050 3400
Wire Wire Line
	5950 3300 6050 3300
Wire Wire Line
	5950 4500 6050 4500
Wire Wire Line
	3750 5100 3650 5100
Wire Wire Line
	5950 5000 6050 5000
Wire Wire Line
	5950 5400 6050 5400
Wire Wire Line
	5950 4600 6050 4600
Wire Wire Line
	5950 5600 6050 5600
Wire Wire Line
	5950 5700 6050 5700
Wire Wire Line
	5950 3900 6050 3900
Text Label 6050 3300 0    50   ~ 0
Fan_pot
Text Label 6050 4500 0    50   ~ 0
Acc_vol
Text Label 3650 5100 2    50   ~ 0
Down
Text Label 6050 5000 0    50   ~ 0
Up
Text Label 6050 4600 0    50   ~ 0
MC_sw
Text Label 6100 3500 0    50   ~ 0
Left_LED
Text Label 6050 5400 0    50   ~ 0
Right_LED
Text Label 6050 5600 0    50   ~ 0
F-R_sw
Text Label 6050 5700 0    50   ~ 0
P-E_sw
Text Label 3650 4900 2    50   ~ 0
Fan_pwm
Text Label 3650 5000 2    50   ~ 0
Horn_sw
Wire Wire Line
	3750 5700 3650 5700
Wire Wire Line
	3750 5200 3650 5200
Wire Wire Line
	3750 5600 3650 5600
Wire Wire Line
	5950 3100 6050 3100
Wire Wire Line
	5950 3200 6050 3200
Text Label 3650 5700 2    50   ~ 0
DRL_sw
Text Label 3650 5600 2    50   ~ 0
HL_sw
Text Label 3650 5200 2    50   ~ 0
Select
Text Label 6050 4800 0    50   ~ 0
Brake_LED
Text Label 6050 4200 0    50   ~ 0
Left_sw
Wire Wire Line
	6050 4200 5950 4200
Text GLabel 4750 1900 1    50   Input ~ 0
VDD_MCU
Wire Wire Line
	4750 1900 4750 2200
Text GLabel 4250 6300 0    50   Input ~ 0
GND_MCU
$Sheet
S 10400 3050 650  300 
U 60E58F6E
F0 "LCD_I2C" 50
F1 "LCD_I2C.sch" 50
F2 "SDA" I L 10400 3150 50 
F3 "SCL" I L 10400 3250 50 
$EndSheet
Wire Wire Line
	3750 4300 3650 4300
NoConn ~ 3750 4100
NoConn ~ 3750 5500
NoConn ~ 5950 5100
NoConn ~ 3750 5400
NoConn ~ 5950 4000
NoConn ~ 3750 4600
NoConn ~ 5950 2800
NoConn ~ 5950 2700
NoConn ~ 5950 3600
NoConn ~ 3750 5300
NoConn ~ 3750 5800
NoConn ~ 5950 3700
Wire Wire Line
	4650 1900 4650 2200
Text GLabel 4650 1900 1    50   Input ~ 0
MCU_5V
Text GLabel 4250 6400 0    50   Input ~ 0
GND
NoConn ~ 5350 2200
NoConn ~ 4950 2200
NoConn ~ 4850 2200
NoConn ~ 4250 2200
NoConn ~ 4550 2200
NoConn ~ 4450 2200
NoConn ~ 4350 2200
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 6034E1C9
P 10900 6250
F 0 "#FLG0101" H 10900 6325 50  0001 C CNN
F 1 "PWR_FLAG" H 10900 6423 50  0000 C CNN
F 2 "" H 10900 6250 50  0001 C CNN
F 3 "~" H 10900 6250 50  0001 C CNN
	1    10900 6250
	1    0    0    -1  
$EndComp
Text GLabel 10900 6350 0    50   Input ~ 0
VDD_MCU
Wire Wire Line
	10900 6350 10900 6250
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 6035AAFA
P 10900 5800
F 0 "#FLG0102" H 10900 5875 50  0001 C CNN
F 1 "PWR_FLAG" H 10900 5973 50  0000 C CNN
F 2 "" H 10900 5800 50  0001 C CNN
F 3 "~" H 10900 5800 50  0001 C CNN
	1    10900 5800
	1    0    0    -1  
$EndComp
Text GLabel 10900 5900 0    50   Input ~ 0
GND_MCU
Wire Wire Line
	10900 5900 10900 5800
Text Label 3650 2800 2    50   ~ 0
Reset
Wire Wire Line
	3650 2800 3750 2800
NoConn ~ 3750 2700
Wire Wire Line
	4250 6200 4250 6400
NoConn ~ 5950 2900
NoConn ~ 5950 3000
Text Label 6050 3100 0    50   ~ 0
Battery_LED
Text Label 6050 4400 0    50   ~ 0
DRL_LED
Wire Wire Line
	5950 4400 6050 4400
Wire Wire Line
	5950 4800 6050 4800
Text Label 6050 3900 0    50   ~ 0
Right_acti
Wire Wire Line
	3750 4800 3650 4800
Text Label 6050 3800 0    50   ~ 0
Left_acti
Wire Wire Line
	3650 4900 3750 4900
NoConn ~ 5950 4700
Text Label 3650 4800 2    50   ~ 0
Front_acti
Text Label 6050 5500 0    50   ~ 0
Brake_acti
Wire Wire Line
	6050 3800 5950 3800
Wire Wire Line
	5950 5500 6050 5500
NoConn ~ 3750 3800
Text Label 3650 4700 2    50   ~ 0
MC_LED
Wire Wire Line
	3750 4700 3650 4700
Wire Wire Line
	10300 4900 10400 4900
Text Label 10300 4900 2    50   ~ 0
Front_acti
Wire Wire Line
	10300 5000 10400 5000
Text Label 10300 5000 2    50   ~ 0
Brake_acti
Wire Wire Line
	10300 4800 10400 4800
Text Label 10300 4800 2    50   ~ 0
Left_acti
Wire Wire Line
	10300 5200 10400 5200
Text Label 10300 5200 2    50   ~ 0
Right_acti
$Sheet
S 10400 4700 700  650 
U 6001478F
F0 "Solar_lights" 50
F1 "Solar_lights.sch" 50
F2 "Brake_acti" I L 10400 5000 50 
F3 "Left_acti" I L 10400 4800 50 
F4 "Right_acti" I L 10400 5200 50 
F5 "Front_acti" I L 10400 4900 50 
F6 "Fan_acti" I L 10400 5100 50 
F7 "Horn_acti" I L 10400 5300 50 
$EndSheet
Wire Wire Line
	10300 3150 10400 3150
Wire Wire Line
	10300 3250 10400 3250
NoConn ~ 5950 4900
Wire Wire Line
	5950 5300 6050 5300
Wire Wire Line
	5950 5200 6050 5200
Text Label 6050 5300 0    50   ~ 0
CTX
Text Label 6050 5200 0    50   ~ 0
CRX
Text Label 3650 4300 2    50   ~ 0
SCL
Text Label 3650 4400 2    50   ~ 0
SDA
Wire Wire Line
	3750 4400 3650 4400
Wire Wire Line
	6100 3500 5950 3500
Text Label 10300 5100 2    50   ~ 0
Fan_pwm
Wire Wire Line
	10400 5100 10300 5100
Text Label 10300 5300 2    50   ~ 0
Horn_acti
Wire Wire Line
	10300 5300 10400 5300
Text Label 6050 3200 0    50   ~ 0
Horn_acti
Wire Wire Line
	3650 5000 3750 5000
$Comp
L Mechanical:MountingHole_Pad H101
U 1 1 60650EDA
P 9300 5600
F 0 "H101" V 9254 5750 50  0000 L CNN
F 1 "MountingHole_Pad" V 9345 5750 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9300 5600 50  0001 C CNN
F 3 "~" H 9300 5600 50  0001 C CNN
	1    9300 5600
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H102
U 1 1 6065DA9C
P 9300 5800
F 0 "H102" V 9254 5950 50  0000 L CNN
F 1 "MountingHole_Pad" V 9345 5950 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9300 5800 50  0001 C CNN
F 3 "~" H 9300 5800 50  0001 C CNN
	1    9300 5800
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H103
U 1 1 6065DD09
P 9300 6000
F 0 "H103" V 9254 6150 50  0000 L CNN
F 1 "MountingHole_Pad" V 9345 6150 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9300 6000 50  0001 C CNN
F 3 "~" H 9300 6000 50  0001 C CNN
	1    9300 6000
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H104
U 1 1 6065DFA5
P 9300 6200
F 0 "H104" V 9254 6350 50  0000 L CNN
F 1 "MountingHole_Pad" V 9345 6350 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9300 6200 50  0001 C CNN
F 3 "~" H 9300 6200 50  0001 C CNN
	1    9300 6200
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H105
U 1 1 6065E101
P 9300 6400
F 0 "H105" V 9254 6550 50  0000 L CNN
F 1 "MountingHole_Pad" V 9345 6550 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9300 6400 50  0001 C CNN
F 3 "~" H 9300 6400 50  0001 C CNN
	1    9300 6400
	0    1    1    0   
$EndComp
Wire Wire Line
	9200 5600 9200 5800
Connection ~ 9200 5800
Wire Wire Line
	9200 5800 9200 6000
Connection ~ 9200 6000
Wire Wire Line
	9200 6000 9200 6200
Connection ~ 9200 6200
Wire Wire Line
	9200 6200 9200 6400
Text GLabel 9200 6400 0    50   Input ~ 0
GND
$Comp
L Solarteam:NUCLEO64-F476RG U101
U 1 1 601A040E
P 4850 4200
F 0 "U101" H 4850 6381 50  0000 C CNN
F 1 "NUCLEO64-F476RG" H 4850 6290 50  0000 C CNN
F 2 "Solar_team:MODULE_NUCLEO-F476RG" H 5400 2300 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/data_brief/DM00105918.pdf" H 3950 2800 50  0001 C CNN
	1    4850 4200
	1    0    0    -1  
$EndComp
NoConn ~ 3750 4500
Wire Wire Line
	6050 4100 5950 4100
Text Label 6050 4100 0    50   ~ 0
Right_sw
NoConn ~ 3750 3900
Text Label 6050 5800 0    50   ~ 0
Brake_vol
Wire Wire Line
	5950 5800 6050 5800
Wire Wire Line
	4250 6200 4350 6200
Connection ~ 4250 6200
Connection ~ 4350 6200
Wire Wire Line
	4350 6200 4450 6200
Connection ~ 4450 6200
Wire Wire Line
	4450 6200 4550 6200
Connection ~ 4550 6200
Wire Wire Line
	4550 6200 4650 6200
Connection ~ 4650 6200
Wire Wire Line
	4650 6200 4750 6200
Connection ~ 4750 6200
Wire Wire Line
	4750 6200 4850 6200
Connection ~ 4850 6200
Wire Wire Line
	4850 6200 4950 6200
Connection ~ 4950 6200
Wire Wire Line
	4950 6200 5050 6200
Connection ~ 5050 6200
Wire Wire Line
	5050 6200 5150 6200
Text Label 9950 3800 2    50   ~ 0
MC_sw
Text Label 9950 3900 2    50   ~ 0
Acc_vol
Text Label 9950 4300 2    50   ~ 0
MC_LED
Text Label 9950 4200 2    50   ~ 0
F-R_sw
Text Label 9950 4100 2    50   ~ 0
P-E_sw
Text Label 9950 4000 2    50   ~ 0
Brake_vol
Wire Wire Line
	10050 3800 9950 3800
Wire Wire Line
	10050 3900 9950 3900
Wire Wire Line
	10050 4000 9950 4000
Wire Wire Line
	10050 4100 9950 4100
Wire Wire Line
	10050 4200 9950 4200
Wire Wire Line
	10050 4300 9950 4300
$Sheet
S 10400 800  650  1950
U 6050AF4F
F0 "MCU_IO" 50
F1 "MCU_IO.sch" 50
F2 "Down" I L 10400 850 50 
F3 "Up" I L 10400 950 50 
F4 "Select" I L 10400 1050 50 
F5 "Reset" I L 10400 1150 50 
F6 "Fan_pot" I L 10400 1350 50 
F7 "Battery_pot" I L 10400 1450 50 
F8 "Brake_LED" I L 10400 1650 50 
F9 "DRL_LED" I L 10400 1750 50 
F10 "Battery_LED" I L 10400 1850 50 
F11 "Right_LED" I L 10400 1950 50 
F12 "Left_LED" I L 10400 2050 50 
F13 "Right_sw" I L 10400 2250 50 
F14 "Left_sw" I L 10400 2350 50 
F15 "HL_sw" I L 10400 2450 50 
F16 "DRL_sw" I L 10400 2550 50 
F17 "Horn_sw" I L 10400 2650 50 
$EndSheet
Wire Wire Line
	10400 850  10300 850 
Wire Wire Line
	10400 950  10300 950 
Wire Wire Line
	10400 1050 10300 1050
Wire Wire Line
	10400 1150 10300 1150
Wire Wire Line
	10400 1350 10300 1350
Wire Wire Line
	10400 1450 10300 1450
Wire Wire Line
	10400 1650 10300 1650
Wire Wire Line
	10400 1750 10300 1750
Wire Wire Line
	10400 1850 10300 1850
Wire Wire Line
	10400 1950 10300 1950
Wire Wire Line
	10400 2050 10300 2050
Wire Wire Line
	10400 2250 10300 2250
Wire Wire Line
	10400 2350 10300 2350
Wire Wire Line
	10400 2450 10300 2450
Wire Wire Line
	10400 2550 10300 2550
Wire Wire Line
	10400 2650 10300 2650
Text Label 10300 2050 2    50   ~ 0
Left_LED
Text Label 10300 2250 2    50   ~ 0
Right_sw
Text Label 10300 2350 2    50   ~ 0
Left_sw
Text Label 10300 1750 2    50   ~ 0
DRL_LED
Text Label 10300 1950 2    50   ~ 0
Right_LED
Text Label 10300 1850 2    50   ~ 0
Battery_LED
Text Label 10300 1350 2    50   ~ 0
Fan_pot
Text Label 10300 1450 2    50   ~ 0
Battery_pot
Text Label 10300 1050 2    50   ~ 0
Select
Text Label 10300 850  2    50   ~ 0
Down
Text Label 10300 950  2    50   ~ 0
Up
Text Label 10300 1650 2    50   ~ 0
Brake_LED
Text Label 10300 2450 2    50   ~ 0
HL_sw
Text Label 10300 2550 2    50   ~ 0
DRL_sw
Text Label 10300 2650 2    50   ~ 0
Horn_sw
Text Label 10300 1150 2    50   ~ 0
Reset
$Sheet
S 8450 850  850  350 
U 605DCA87
F0 "Power_&_safe_state" 50
F1 "Power_&_safe_state.sch" 50
$EndSheet
Text Label 8650 1600 2    50   ~ 0
CTX
Text Label 8650 1500 2    50   ~ 0
CRX
Wire Wire Line
	8750 1600 8650 1600
Wire Wire Line
	8750 1500 8650 1500
$Sheet
S 8750 1450 550  250 
U 605E5633
F0 "CAN" 50
F1 "CAN.sch" 50
F2 "CRX" I L 8750 1500 50 
F3 "CTX" I L 8750 1600 50 
$EndSheet
$Sheet
S 10050 3700 1050 700 
U 6038AC45
F0 "Motor_controller" 50
F1 "Motor_controller.sch" 50
F2 "MC_sw" I L 10050 3800 50 
F3 "Acc_vol" I L 10050 3900 50 
F4 "Brake_vol" I L 10050 4000 50 
F5 "P-E_sw" I L 10050 4100 50 
F6 "F-R_sw" I L 10050 4200 50 
F7 "MC_LED" I L 10050 4300 50 
$EndSheet
Text Label 10300 3250 2    50   ~ 0
SCL
Text Label 10300 3150 2    50   ~ 0
SDA
$EndSCHEMATC
