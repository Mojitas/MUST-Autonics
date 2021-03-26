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
Text Notes 7200 3400 0    50   ~ 0
Power on\n
Text Notes 5400 3900 0    50   ~ 0
Safe State\n
Wire Notes Line
	4500 3150 7700 3150
Wire Notes Line
	4500 4000 4500 3150
Wire Notes Line
	7700 4000 4500 4000
Wire Notes Line
	7700 3150 7700 4000
Wire Wire Line
	6700 3500 6600 3500
Wire Wire Line
	7200 3500 7100 3500
Text GLabel 7200 3500 2    50   Input ~ 0
VDD_MCU
Text GLabel 6600 3500 0    50   Input ~ 0
V_external
Wire Wire Line
	5400 3650 5400 3800
Wire Wire Line
	5400 3500 5400 3550
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 605DE7CB
P 5600 3550
AR Path="/605DE7CB" Ref="J?"  Part="1" 
AR Path="/605DCA87/605DE7CB" Ref="J501"  Part="1" 
F 0 "J501" H 5500 3700 50  0000 L CNN
F 1 "Conn_01x02" H 5400 3350 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S2B-XH-A_1x02_P2.50mm_Horizontal" H 5600 3550 50  0001 C CNN
F 3 "~" H 5600 3550 50  0001 C CNN
	1    5600 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3800 5400 3800
Wire Wire Line
	5400 3500 5100 3500
Wire Wire Line
	4700 3500 4700 3800
$Comp
L Switch:SW_SPST SW?
U 1 1 605DE7D4
P 4900 3500
AR Path="/605DE7D4" Ref="SW?"  Part="1" 
AR Path="/605DCA87/605DE7D4" Ref="SW501"  Part="1" 
F 0 "SW501" H 4900 3735 50  0000 C CNN
F 1 "SW_SPST" H 4900 3644 50  0000 C CNN
F 2 "Solar_team:MFP120" H 4900 3500 50  0001 C CNN
F 3 "~" H 4900 3500 50  0001 C CNN
	1    4900 3500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 605DE7DA
P 6900 3500
AR Path="/605DE7DA" Ref="SW?"  Part="1" 
AR Path="/605DCA87/605DE7DA" Ref="SW502"  Part="1" 
F 0 "SW502" H 6900 3735 50  0000 C CNN
F 1 "SW_SPST" H 6900 3644 50  0000 C CNN
F 2 "Solar_team:MFP120" H 6900 3500 50  0001 C CNN
F 3 "~" H 6900 3500 50  0001 C CNN
	1    6900 3500
	1    0    0    -1  
$EndComp
$EndSCHEMATC
