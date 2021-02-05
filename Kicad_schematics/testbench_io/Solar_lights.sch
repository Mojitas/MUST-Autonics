EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
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
	5550 3200 5550 3100
Text Label 5550 3100 1    50   ~ 0
Front_lights_VSS
Text GLabel 5700 3650 2    50   Input ~ 0
GND
Connection ~ 5550 3650
Wire Wire Line
	5550 3650 5700 3650
Wire Wire Line
	5550 3650 5550 3600
Wire Wire Line
	5400 3650 5550 3650
Wire Wire Line
	5200 3400 5200 3650
Wire Wire Line
	5250 3400 5200 3400
$Comp
L Device:R_Small R?
U 1 1 60041E0C
P 5300 3650
AR Path="/60041E0C" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E0C" Ref="R304"  Part="1" 
F 0 "R304" V 5200 3650 50  0000 C CNN
F 1 "100k" V 5400 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5300 3650 50  0001 C CNN
F 3 "~" H 5300 3650 50  0001 C CNN
	1    5300 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 3200 4750 3100
Text Label 4750 3100 1    50   ~ 0
Right_indicator_VSS
Text GLabel 4900 3650 2    50   Input ~ 0
GND
Connection ~ 4750 3650
Wire Wire Line
	4750 3650 4900 3650
Wire Wire Line
	4750 3650 4750 3600
Wire Wire Line
	4600 3650 4750 3650
Wire Wire Line
	4400 3400 4400 3650
Wire Wire Line
	4450 3400 4400 3400
$Comp
L Device:R_Small R?
U 1 1 60041E22
P 4500 3650
AR Path="/60041E22" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E22" Ref="R303"  Part="1" 
F 0 "R303" V 4400 3650 50  0000 C CNN
F 1 "10k" V 4600 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4500 3650 50  0001 C CNN
F 3 "~" H 4500 3650 50  0001 C CNN
	1    4500 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	3950 3200 3950 3100
Text Label 3950 3100 1    50   ~ 0
Left_indicator_VSS
Text GLabel 4100 3650 2    50   Input ~ 0
GND
Connection ~ 3950 3650
Wire Wire Line
	3950 3650 4100 3650
Wire Wire Line
	3950 3650 3950 3600
Wire Wire Line
	3800 3650 3950 3650
Wire Wire Line
	3600 3400 3600 3650
Wire Wire Line
	3650 3400 3600 3400
$Comp
L Device:R_Small R?
U 1 1 60041E38
P 3700 3650
AR Path="/60041E38" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E38" Ref="R302"  Part="1" 
F 0 "R302" V 3600 3650 50  0000 C CNN
F 1 "10k" V 3800 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3700 3650 50  0001 C CNN
F 3 "~" H 3700 3650 50  0001 C CNN
	1    3700 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 4550 5650 4450
Text Label 5650 4450 1    50   ~ 0
Brake_lights_VSS
Text GLabel 5800 5000 2    50   Input ~ 0
GND
Connection ~ 5650 5000
Wire Wire Line
	5650 5000 5800 5000
Wire Wire Line
	5650 5000 5650 4950
Wire Wire Line
	5500 5000 5650 5000
Wire Wire Line
	5300 4750 5300 5000
Wire Wire Line
	5350 4750 5300 4750
$Comp
L Device:R_Small R?
U 1 1 60041E4E
P 5400 5000
AR Path="/60041E4E" Ref="R?"  Part="1" 
AR Path="/6001478F/60041E4E" Ref="R301"  Part="1" 
F 0 "R301" V 5300 5000 50  0000 C CNN
F 1 "10k" V 5500 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5400 5000 50  0001 C CNN
F 3 "~" H 5400 5000 50  0001 C CNN
	1    5400 5000
	0    1    1    0   
$EndComp
Text HLabel 5300 4750 1    50   Input ~ 0
Brake_acti
Text HLabel 3600 3400 1    50   Input ~ 0
Left_acti
Text HLabel 4400 3400 1    50   Input ~ 0
Right_acti
Text HLabel 5200 3400 1    50   Input ~ 0
Front_acti
Text Label 6800 5200 0    50   ~ 0
Brake_lights_VSS
Text Label 6800 5000 0    50   ~ 0
Left_indicator_VSS
Text Label 6800 4550 0    50   ~ 0
Right_indicator_VSS
Text Label 6800 4350 0    50   ~ 0
Front_lights_VSS
Wire Wire Line
	6700 4350 6800 4350
Wire Wire Line
	6700 4550 6800 4550
$Comp
L Transistor_FET:IPD50R380CE Q301
U 1 1 600FBD09
P 5550 4750
F 0 "Q301" H 5755 4796 50  0000 L CNN
F 1 "IPD50R380CE" H 5755 4705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 5750 4675 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-IPD50R380CE-DS-v02_01-en.pdf?fileId=db3a30433ecb86d4013ed0a2ef580f38" H 5550 4750 50  0001 L CNN
	1    5550 4750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IPD50R380CE Q302
U 1 1 600FF05E
P 3850 3400
F 0 "Q302" H 4055 3446 50  0000 L CNN
F 1 "IPD50R380CE" H 4055 3355 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 4050 3325 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-IPD50R380CE-DS-v02_01-en.pdf?fileId=db3a30433ecb86d4013ed0a2ef580f38" H 3850 3400 50  0001 L CNN
	1    3850 3400
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IPD50R380CE Q303
U 1 1 600FF654
P 4650 3400
F 0 "Q303" H 4855 3446 50  0000 L CNN
F 1 "IPD50R380CE" H 4855 3355 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 4850 3325 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-IPD50R380CE-DS-v02_01-en.pdf?fileId=db3a30433ecb86d4013ed0a2ef580f38" H 4650 3400 50  0001 L CNN
	1    4650 3400
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IPD50R380CE Q304
U 1 1 600FFC56
P 5450 3400
F 0 "Q304" H 5655 3446 50  0000 L CNN
F 1 "IPD50R380CE" H 5655 3355 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 5650 3325 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-IPD50R380CE-DS-v02_01-en.pdf?fileId=db3a30433ecb86d4013ed0a2ef580f38" H 5450 3400 50  0001 L CNN
	1    5450 3400
	1    0    0    -1  
$EndComp
Text GLabel 7650 3800 2    50   Input ~ 0
VDD_MCU
Wire Wire Line
	6700 5000 6800 5000
Wire Wire Line
	6700 5200 6800 5200
Wire Wire Line
	7650 4450 7650 4650
Wire Wire Line
	6700 4650 7650 4650
Connection ~ 7650 4650
Wire Wire Line
	6700 5100 7650 5100
Wire Wire Line
	7650 4650 7650 5100
Wire Wire Line
	7650 5100 7650 5300
Wire Wire Line
	6700 5300 7650 5300
Connection ~ 7650 5100
Wire Wire Line
	4800 4550 4800 4450
Text GLabel 4950 5000 2    50   Input ~ 0
GND
Connection ~ 4800 5000
Wire Wire Line
	4800 5000 4950 5000
Wire Wire Line
	4800 5000 4800 4950
Wire Wire Line
	4650 5000 4800 5000
Wire Wire Line
	4450 4750 4450 5000
Wire Wire Line
	4500 4750 4450 4750
$Comp
L Device:R_Small R?
U 1 1 601B6BDF
P 4550 5000
AR Path="/601B6BDF" Ref="R?"  Part="1" 
AR Path="/6001478F/601B6BDF" Ref="R305"  Part="1" 
F 0 "R305" V 4450 5000 50  0000 C CNN
F 1 "R_Small" V 4650 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4550 5000 50  0001 C CNN
F 3 "~" H 4550 5000 50  0001 C CNN
	1    4550 5000
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:IPD50R380CE Q305
U 1 1 601B6BE6
P 4700 4750
AR Path="/6001478F/601B6BE6" Ref="Q305"  Part="1" 
AR Path="/601B6BE6" Ref="Q?"  Part="1" 
F 0 "Q305" H 4905 4796 50  0000 L CNN
F 1 "IPD50R380CE" V 5150 4600 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 4900 4675 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-IPD50R380CE-DS-v02_01-en.pdf?fileId=db3a30433ecb86d4013ed0a2ef580f38" H 4700 4750 50  0001 L CNN
	1    4700 4750
	1    0    0    -1  
$EndComp
Text HLabel 4450 4750 1    50   Input ~ 0
Fan_acti
Wire Wire Line
	7650 4000 7650 4450
Text Label 4800 4450 1    50   ~ 0
Fan_VSS
Wire Wire Line
	6700 4450 7650 4450
Text Label 6800 3900 0    50   ~ 0
Fan_VSS
Wire Wire Line
	6800 3900 6700 3900
Wire Wire Line
	6700 4000 7650 4000
Wire Wire Line
	3900 4600 3900 4500
Text GLabel 4050 5050 2    50   Input ~ 0
GND
Connection ~ 3900 5050
Wire Wire Line
	3900 5050 4050 5050
Wire Wire Line
	3900 5050 3900 5000
Wire Wire Line
	3750 5050 3900 5050
Wire Wire Line
	3550 4800 3550 5050
Wire Wire Line
	3600 4800 3550 4800
$Comp
L Device:R_Small R?
U 1 1 603A50A6
P 3650 5050
AR Path="/603A50A6" Ref="R?"  Part="1" 
AR Path="/6001478F/603A50A6" Ref="R306"  Part="1" 
F 0 "R306" V 3550 5050 50  0000 C CNN
F 1 "R_Small" V 3750 5050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3650 5050 50  0001 C CNN
F 3 "~" H 3650 5050 50  0001 C CNN
	1    3650 5050
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:IPD50R380CE Q306
U 1 1 603A50AC
P 3800 4800
AR Path="/6001478F/603A50AC" Ref="Q306"  Part="1" 
AR Path="/603A50AC" Ref="Q?"  Part="1" 
F 0 "Q306" H 4005 4846 50  0000 L CNN
F 1 "IPD50R380CE" V 4250 4650 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 4000 4725 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-IPD50R380CE-DS-v02_01-en.pdf?fileId=db3a30433ecb86d4013ed0a2ef580f38" H 3800 4800 50  0001 L CNN
	1    3800 4800
	1    0    0    -1  
$EndComp
Text HLabel 3550 4800 1    50   Input ~ 0
Horn_acti
Text Label 3900 4500 1    50   ~ 0
Horn_VSS
Text Label 6800 3700 0    50   ~ 0
Horn_VSS
Wire Wire Line
	6700 3800 7650 3800
Wire Wire Line
	7650 3800 7650 4000
Connection ~ 7650 4000
Wire Wire Line
	6800 3700 6700 3700
$Comp
L Connector_Generic:Conn_01x04 J301
U 1 1 6019E71D
P 6500 3900
F 0 "J301" H 6418 3475 50  0000 C CNN
F 1 "Conn_01x04" H 6418 3566 50  0000 C CNN
F 2 "Connector_JST:JST_XH_S4B-XH-A_1x04_P2.50mm_Horizontal" H 6500 3900 50  0001 C CNN
F 3 "~" H 6500 3900 50  0001 C CNN
	1    6500 3900
	-1   0    0    1   
$EndComp
Connection ~ 7650 4450
$Comp
L Connector_Generic:Conn_01x04 J302
U 1 1 601C60D2
P 6500 4550
F 0 "J302" H 6418 4125 50  0000 C CNN
F 1 "Conn_01x04" H 6418 4216 50  0000 C CNN
F 2 "Connector_JST:JST_XH_S4B-XH-A_1x04_P2.50mm_Horizontal" H 6500 4550 50  0001 C CNN
F 3 "~" H 6500 4550 50  0001 C CNN
	1    6500 4550
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J303
U 1 1 601C67E7
P 6500 5200
F 0 "J303" H 6418 4775 50  0000 C CNN
F 1 "Conn_01x04" H 6418 4866 50  0000 C CNN
F 2 "Connector_JST:JST_XH_S4B-XH-A_1x04_P2.50mm_Horizontal" H 6500 5200 50  0001 C CNN
F 3 "~" H 6500 5200 50  0001 C CNN
	1    6500 5200
	-1   0    0    1   
$EndComp
$EndSCHEMATC
