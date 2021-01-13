EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
	6750 3850 6750 3750
Text Label 6750 3750 1    50   ~ 0
Front_lights
Text GLabel 6900 4300 2    50   Input ~ 0
GND
Connection ~ 6750 4300
Wire Wire Line
	6750 4300 6900 4300
Wire Wire Line
	6750 4300 6750 4250
Wire Wire Line
	6600 4300 6750 4300
Wire Wire Line
	6400 4050 6400 4300
Wire Wire Line
	6450 4050 6400 4050
$Comp
L Device:R_Small R?
U 1 1 60041E0C
P 6500 4300
AR Path="/60041E0C" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E0C" Ref="R?"  Part="1" 
F 0 "R?" V 6400 4300 50  0000 C CNN
F 1 "R_Small" V 6600 4300 50  0000 C CNN
F 2 "" H 6500 4300 50  0001 C CNN
F 3 "~" H 6500 4300 50  0001 C CNN
	1    6500 4300
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:BUK9M42-60EX Q?
U 1 1 60041E12
P 6650 4050
AR Path="/60041E12" Ref="Q?"  Part="1" 
AR Path="/6001478F/60041E12" Ref="Q?"  Part="1" 
F 0 "Q?" H 6550 4200 50  0000 L CNN
F 1 "BUK9M42-60EX" V 6950 3850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:LFPAK33" H 6850 3975 50  0001 L CIN
F 3 "https://assets.nexperia.com/documents/data-sheet/BUK9M42-60E.pdf" V 6650 4050 50  0001 L CNN
	1    6650 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3850 5950 3750
Text Label 5950 3750 1    50   ~ 0
Right_indicator
Text GLabel 6100 4300 2    50   Input ~ 0
GND
Connection ~ 5950 4300
Wire Wire Line
	5950 4300 6100 4300
Wire Wire Line
	5950 4300 5950 4250
Wire Wire Line
	5800 4300 5950 4300
Wire Wire Line
	5600 4050 5600 4300
Wire Wire Line
	5650 4050 5600 4050
$Comp
L Device:R_Small R?
U 1 1 60041E22
P 5700 4300
AR Path="/60041E22" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E22" Ref="R?"  Part="1" 
F 0 "R?" V 5600 4300 50  0000 C CNN
F 1 "R_Small" V 5800 4300 50  0000 C CNN
F 2 "" H 5700 4300 50  0001 C CNN
F 3 "~" H 5700 4300 50  0001 C CNN
	1    5700 4300
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:BUK9M42-60EX Q?
U 1 1 60041E28
P 5850 4050
AR Path="/60041E28" Ref="Q?"  Part="1" 
AR Path="/6001478F/60041E28" Ref="Q?"  Part="1" 
F 0 "Q?" H 5750 4200 50  0000 L CNN
F 1 "BUK9M42-60EX" V 6150 3850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:LFPAK33" H 6050 3975 50  0001 L CIN
F 3 "https://assets.nexperia.com/documents/data-sheet/BUK9M42-60E.pdf" V 5850 4050 50  0001 L CNN
	1    5850 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3850 5150 3750
Text Label 5150 3750 1    50   ~ 0
Left_indicator
Text GLabel 5300 4300 2    50   Input ~ 0
GND
Connection ~ 5150 4300
Wire Wire Line
	5150 4300 5300 4300
Wire Wire Line
	5150 4300 5150 4250
Wire Wire Line
	5000 4300 5150 4300
Wire Wire Line
	4800 4050 4800 4300
Wire Wire Line
	4850 4050 4800 4050
$Comp
L Device:R_Small R?
U 1 1 60041E38
P 4900 4300
AR Path="/60041E38" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E38" Ref="R?"  Part="1" 
F 0 "R?" V 4800 4300 50  0000 C CNN
F 1 "R_Small" V 5000 4300 50  0000 C CNN
F 2 "" H 4900 4300 50  0001 C CNN
F 3 "~" H 4900 4300 50  0001 C CNN
	1    4900 4300
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:BUK9M42-60EX Q?
U 1 1 60041E3E
P 5050 4050
AR Path="/60041E3E" Ref="Q?"  Part="1" 
AR Path="/6001478F/60041E3E" Ref="Q?"  Part="1" 
F 0 "Q?" H 4950 4200 50  0000 L CNN
F 1 "BUK9M42-60EX" V 5350 3850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:LFPAK33" H 5250 3975 50  0001 L CIN
F 3 "https://assets.nexperia.com/documents/data-sheet/BUK9M42-60E.pdf" V 5050 4050 50  0001 L CNN
	1    5050 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3850 4350 3750
Text Label 4350 3750 1    50   ~ 0
Brake_lights
Text GLabel 4500 4300 2    50   Input ~ 0
GND
Connection ~ 4350 4300
Wire Wire Line
	4350 4300 4500 4300
Wire Wire Line
	4350 4300 4350 4250
Wire Wire Line
	4200 4300 4350 4300
Wire Wire Line
	4000 4050 4000 4300
Wire Wire Line
	4050 4050 4000 4050
$Comp
L Device:R_Small R?
U 1 1 60041E4E
P 4100 4300
AR Path="/60041E4E" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E4E" Ref="R?"  Part="1" 
F 0 "R?" V 4000 4300 50  0000 C CNN
F 1 "R_Small" V 4200 4300 50  0000 C CNN
F 2 "" H 4100 4300 50  0001 C CNN
F 3 "~" H 4100 4300 50  0001 C CNN
	1    4100 4300
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:BUK9M42-60EX Q?
U 1 1 60041E54
P 4250 4050
AR Path="/60041E54" Ref="Q?"  Part="1" 
AR Path="/6001478F/60041E54" Ref="Q?"  Part="1" 
F 0 "Q?" H 4150 4200 50  0000 L CNN
F 1 "BUK9M42-60EX" V 4550 3850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:LFPAK33" H 4450 3975 50  0001 L CIN
F 3 "https://assets.nexperia.com/documents/data-sheet/BUK9M42-60E.pdf" V 4250 4050 50  0001 L CNN
	1    4250 4050
	1    0    0    -1  
$EndComp
Text HLabel 4000 4050 1    50   Input ~ 0
Brake_acti
Text HLabel 4800 4050 1    50   Input ~ 0
Left_acti
Text HLabel 5600 4050 1    50   Input ~ 0
Right_acti
Text HLabel 6400 4050 1    50   Input ~ 0
Front_acti
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 60130D83
P 7400 4200
F 0 "J?" V 7364 3912 50  0000 R CNN
F 1 "Conn_01x04" V 7273 3912 50  0000 R CNN
F 2 "" H 7400 4200 50  0001 C CNN
F 3 "~" H 7400 4200 50  0001 C CNN
	1    7400 4200
	-1   0    0    1   
$EndComp
Text Label 7700 4300 0    50   ~ 0
Brake_lights
Text Label 7700 4200 0    50   ~ 0
Left_indicator
Text Label 7700 4100 0    50   ~ 0
Right_indicator
Text Label 7700 4000 0    50   ~ 0
Front_lights
Wire Wire Line
	7600 4300 7700 4300
Wire Wire Line
	7600 4000 7700 4000
Wire Wire Line
	7600 4100 7700 4100
Wire Wire Line
	7600 4200 7700 4200
$EndSCHEMATC
