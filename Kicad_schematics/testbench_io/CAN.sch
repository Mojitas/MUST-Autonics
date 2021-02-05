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
Wire Wire Line
	5400 3450 5300 3450
Wire Wire Line
	5400 3350 5300 3350
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 605E666D
P 6600 3550
AR Path="/605E666D" Ref="J?"  Part="1" 
AR Path="/605E5633/605E666D" Ref="J601"  Part="1" 
F 0 "J601" H 6680 3542 50  0000 L CNN
F 1 "Conn_01x02" H 6680 3451 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S2B-XH-A_1x02_P2.50mm_Horizontal" H 6600 3550 50  0001 C CNN
F 3 "~" H 6600 3550 50  0001 C CNN
	1    6600 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3550 6400 3550
Wire Wire Line
	6150 4000 6150 3950
Wire Wire Line
	6350 4000 6350 3950
Connection ~ 6350 3550
Wire Wire Line
	6350 3650 6350 3550
Connection ~ 6150 3650
Wire Wire Line
	6150 3750 6150 3650
Wire Wire Line
	6100 3550 6350 3550
$Comp
L Jumper:SolderJumper_2_Open JP?
U 1 1 605E667B
P 6350 3800
AR Path="/605E667B" Ref="JP?"  Part="1" 
AR Path="/605E5633/605E667B" Ref="JP601"  Part="1" 
F 0 "JP601" V 6304 3868 50  0000 L CNN
F 1 "SolderJumper_2_Open" V 6395 3868 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 6350 3800 50  0001 C CNN
F 3 "~" H 6350 3800 50  0001 C CNN
	1    6350 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 3650 6150 3650
Text GLabel 5350 4000 2    50   Input ~ 0
MCU_5V
Wire Wire Line
	5250 3750 5400 3750
Text GLabel 5250 4100 2    50   Input ~ 0
GND_MCU
Wire Wire Line
	6150 4000 6350 4000
$Comp
L Device:R_Small R?
U 1 1 605E6686
P 6150 3850
AR Path="/605E6686" Ref="R?"  Part="1" 
AR Path="/605E5633/605E6686" Ref="R601"  Part="1" 
F 0 "R601" V 6250 3850 50  0000 C CNN
F 1 "120" V 6050 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6150 3850 50  0001 C CNN
F 3 "~" H 6150 3850 50  0001 C CNN
	1    6150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 3850 5400 3850
$Comp
L Solarteam:CJMCU_MCP2551 U?
U 1 1 605E668D
P 5750 3600
AR Path="/605E668D" Ref="U?"  Part="1" 
AR Path="/605E5633/605E668D" Ref="U601"  Part="1" 
F 0 "U601" H 5600 3600 50  0000 C CNN
F 1 "CJMCU_MCP2551" H 5750 3950 50  0000 C CNN
F 2 "Solar_team:CJMCU_2551" H 5750 3600 50  0001 C CNN
F 3 "" H 5750 3600 50  0001 C CNN
	1    5750 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3650 6350 3650
Connection ~ 6350 3650
Wire Wire Line
	6350 3650 6400 3650
Wire Notes Line
	7300 3200 7300 4250
Wire Notes Line
	7300 4250 5050 4250
Wire Notes Line
	5050 4250 5050 3200
Wire Notes Line
	5050 3200 7300 3200
Wire Wire Line
	5250 4100 5250 3750
Wire Wire Line
	5350 3850 5350 4000
Text HLabel 5300 3350 0    50   Input ~ 0
CRX
Text HLabel 5300 3450 0    50   Input ~ 0
CTX
$EndSCHEMATC
