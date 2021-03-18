EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 6050 3850 0    50   ~ 0
Power connector\n
Text Notes 6800 3350 0    50   ~ 0
Power on\n
Text Notes 5350 4100 0    50   ~ 0
Safe State\n
Wire Notes Line
	4500 3150 7300 3150
Wire Notes Line
	4500 4200 4500 3150
Wire Notes Line
	7300 4200 4500 4200
Wire Notes Line
	7300 3150 7300 4200
Wire Wire Line
	6650 4000 6500 4000
Wire Wire Line
	6650 3900 6500 3900
Wire Wire Line
	6300 3450 6200 3450
Wire Wire Line
	6800 3450 6700 3450
Text GLabel 6800 3450 2    50   Input ~ 0
VDD_MCU
Text GLabel 6200 3450 0    50   Input ~ 0
V_external
Wire Wire Line
	5350 3850 5350 4000
Wire Wire Line
	5350 3700 5350 3750
Text GLabel 6500 4000 0    50   Input ~ 0
GND
Text GLabel 6500 3900 0    50   Input ~ 0
V_external
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 605DE7C5
P 6850 3900
AR Path="/605DE7C5" Ref="J?"  Part="1" 
AR Path="/605DCA87/605DE7C5" Ref="J502"  Part="1" 
F 0 "J502" H 6800 4050 50  0000 L CNN
F 1 "Conn_01x02" H 6600 3700 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S2B-XH-A_1x02_P2.50mm_Horizontal" H 6850 3900 50  0001 C CNN
F 3 "~" H 6850 3900 50  0001 C CNN
	1    6850 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 605DE7CB
P 5550 3750
AR Path="/605DE7CB" Ref="J?"  Part="1" 
AR Path="/605DCA87/605DE7CB" Ref="J501"  Part="1" 
F 0 "J501" H 5450 3900 50  0000 L CNN
F 1 "Conn_01x02" H 5350 3550 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S2B-XH-A_1x02_P2.50mm_Horizontal" H 5550 3750 50  0001 C CNN
F 3 "~" H 5550 3750 50  0001 C CNN
	1    5550 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4000 5350 4000
Wire Wire Line
	5350 3700 5050 3700
Wire Wire Line
	4650 3700 4650 4000
$Comp
L Switch:SW_SPST SW?
U 1 1 605DE7D4
P 4850 3700
AR Path="/605DE7D4" Ref="SW?"  Part="1" 
AR Path="/605DCA87/605DE7D4" Ref="SW501"  Part="1" 
F 0 "SW501" H 4850 3935 50  0000 C CNN
F 1 "SW_SPST" H 4850 3844 50  0000 C CNN
F 2 "Solar_team:MFP120" H 4850 3700 50  0001 C CNN
F 3 "~" H 4850 3700 50  0001 C CNN
	1    4850 3700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 605DE7DA
P 6500 3450
AR Path="/605DE7DA" Ref="SW?"  Part="1" 
AR Path="/605DCA87/605DE7DA" Ref="SW502"  Part="1" 
F 0 "SW502" H 6500 3685 50  0000 C CNN
F 1 "SW_SPST" H 6500 3594 50  0000 C CNN
F 2 "Solar_team:MFP120" H 6500 3450 50  0001 C CNN
F 3 "~" H 6500 3450 50  0001 C CNN
	1    6500 3450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
