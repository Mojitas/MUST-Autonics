EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
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
L Device:R_POT RV103
U 1 1 5FF4F47D
P 8850 1150
F 0 "RV103" H 8800 1100 50  0000 R CNN
F 1 "R_POT" H 8780 1195 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 8850 1150 50  0001 C CNN
F 3 "~" H 8850 1150 50  0001 C CNN
	1    8850 1150
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT RV104
U 1 1 5FF4FC88
P 9350 1150
F 0 "RV104" H 9650 900 50  0000 R CNN
F 1 "R_POT" H 9650 1000 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 9350 1150 50  0001 C CNN
F 3 "~" H 9350 1150 50  0001 C CNN
	1    9350 1150
	1    0    0    1   
$EndComp
$Comp
L Device:LED D106
U 1 1 5FF5E2E6
P 9050 3100
F 0 "D106" H 9050 2900 50  0000 C CNN
F 1 "LED" H 9050 3000 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 9050 3100 50  0001 C CNN
F 3 "~" H 9050 3100 50  0001 C CNN
	1    9050 3100
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R108
U 1 1 5FF62AAD
P 9050 3350
F 0 "R108" V 8950 3350 50  0000 C CNN
F 1 "R_Small" V 9150 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9050 3350 50  0001 C CNN
F 3 "~" H 9050 3350 50  0001 C CNN
	1    9050 3350
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_DIP_x08 SW108
U 1 1 5FF64911
P 9050 4200
F 0 "SW108" H 9050 4867 50  0000 C CNN
F 1 "SW_DIP_x08" H 9050 4776 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 9050 4200 50  0001 C CNN
F 3 "~" H 9050 4200 50  0001 C CNN
	1    9050 4200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW102
U 1 1 5FF78328
P 8450 5050
F 0 "SW102" H 8450 5335 50  0000 C CNN
F 1 "SW_Push" H 8450 5244 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8450 5250 50  0001 C CNN
F 3 "~" H 8450 5250 50  0001 C CNN
	1    8450 5050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW103
U 1 1 5FF78E87
P 8450 5400
F 0 "SW103" H 8450 5685 50  0000 C CNN
F 1 "SW_Push" H 8450 5594 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8450 5600 50  0001 C CNN
F 3 "~" H 8450 5600 50  0001 C CNN
	1    8450 5400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW104
U 1 1 5FF79991
P 8450 5750
F 0 "SW104" H 8450 6035 50  0000 C CNN
F 1 "SW_Push" H 8450 5944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8450 5950 50  0001 C CNN
F 3 "~" H 8450 5950 50  0001 C CNN
	1    8450 5750
	1    0    0    -1  
$EndComp
Text Label 8150 5050 2    50   ~ 0
Down
Text Label 8150 5400 2    50   ~ 0
Up
Text Label 8150 5750 2    50   ~ 0
Select
Text GLabel 8750 5050 2    50   Input ~ 0
GND_MCU
Text GLabel 8750 5400 2    50   Input ~ 0
GND_MCU
Text GLabel 8750 5750 2    50   Input ~ 0
GND_MCU
Wire Wire Line
	8250 5050 8150 5050
Wire Wire Line
	8250 5400 8150 5400
Wire Wire Line
	8250 5750 8150 5750
Wire Wire Line
	8750 5750 8650 5750
Wire Wire Line
	8650 5400 8750 5400
Wire Wire Line
	8650 5050 8750 5050
Wire Notes Line
	9200 6200 7850 6200
Wire Notes Line
	7850 6200 7850 4700
Text Notes 8850 4800 0    50   ~ 0
Menu
$Comp
L Switch:SW_Push SW110
U 1 1 6008DD55
P 10000 5050
F 0 "SW110" H 10000 5335 50  0000 C CNN
F 1 "SW_Push" H 10000 5244 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 10000 5250 50  0001 C CNN
F 3 "~" H 10000 5250 50  0001 C CNN
	1    10000 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 5750 10300 5750
Text GLabel 10450 5750 2    50   Input ~ 0
GND_MCU
Text Label 9600 5050 2    50   ~ 0
Horn_sw
Wire Wire Line
	9600 5050 9800 5050
Text Label 9600 5400 2    50   ~ 0
DRL_sw
Wire Wire Line
	9600 5400 9700 5400
Text Label 9600 5750 2    50   ~ 0
HL_sw
Wire Wire Line
	9600 5750 9700 5750
Text Label 10750 5050 0    50   ~ 0
Left_sw
Text Label 10750 5250 0    50   ~ 0
Right_sw
Wire Wire Line
	10750 5050 10700 5050
Wire Wire Line
	10300 5750 10450 5750
Wire Notes Line
	11100 4700 11100 6100
Wire Notes Line
	11100 6100 9250 6100
Wire Notes Line
	9250 6100 9250 4700
Wire Notes Line
	9250 4700 11100 4700
Text Notes 10500 4800 0    50   ~ 0
Vehicle signals
Connection ~ 10300 5750
Wire Wire Line
	8850 1000 9350 1000
Wire Wire Line
	8850 1300 9350 1300
Text GLabel 8850 1500 0    50   Input ~ 0
TRM_GND
Text Label 9350 800  0    50   ~ 0
TRM_23
Text Label 8500 1150 2    50   ~ 0
TRM_02
Text Label 8850 1450 2    50   ~ 0
TRM_21
Text Label 9350 1450 0    50   ~ 0
TRM_04
Text Label 9700 1150 0    50   ~ 0
TRM_22
Wire Wire Line
	9350 1000 9350 800 
Connection ~ 9350 1000
Wire Wire Line
	8500 1150 8700 1150
Wire Wire Line
	8850 1300 8850 1500
Connection ~ 8850 1300
Wire Wire Line
	9350 1450 9350 1300
Connection ~ 9350 1300
Wire Wire Line
	9700 1150 9500 1150
Text Label 8700 1950 2    50   ~ 0
TRM_01
Text Label 9300 1950 0    50   ~ 0
TRM_20
Text Label 8700 2350 2    50   ~ 0
TRM_25
Text Label 9300 2750 0    50   ~ 0
TRM_06
Text Label 9300 2350 0    50   ~ 0
TRM_7
Text Label 8700 2750 2    50   ~ 0
TRM_05
Text Label 9300 3100 0    50   ~ 0
TRM_14
Text Label 8750 3100 2    50   ~ 0
TRM_15
Wire Wire Line
	8700 2750 8800 2750
Wire Wire Line
	9200 2750 9300 2750
Wire Wire Line
	8700 2350 8800 2350
Wire Wire Line
	9300 2350 9200 2350
Wire Wire Line
	8800 1950 8700 1950
Wire Wire Line
	9300 1950 9200 1950
Wire Wire Line
	8750 3100 8900 3100
Wire Wire Line
	9200 3100 9250 3100
Wire Wire Line
	9250 3100 9250 3350
Wire Wire Line
	9250 3350 9150 3350
Connection ~ 9250 3100
Wire Wire Line
	9250 3100 9300 3100
Text GLabel 8750 3350 0    50   Input ~ 0
GND_MCU
Wire Wire Line
	8750 3350 8950 3350
Text Label 9450 3800 0    50   ~ 0
TRM_01
Wire Wire Line
	9450 3800 9350 3800
Wire Wire Line
	9450 3900 9350 3900
Wire Wire Line
	9450 4000 9350 4000
Wire Wire Line
	9450 4100 9350 4100
Wire Wire Line
	9450 4200 9350 4200
Wire Wire Line
	9450 4300 9350 4300
Wire Wire Line
	9450 4400 9350 4400
Wire Wire Line
	9450 4500 9350 4500
Text Label 9450 3900 0    50   ~ 0
TRM_02
Text Label 9450 4100 0    50   ~ 0
TRM_22
Text Label 9450 4400 0    50   ~ 0
TRM_25
Text Label 9450 4300 0    50   ~ 0
TRM_05
Text Label 9450 4500 0    50   ~ 0
TRM_15
Wire Wire Line
	8750 4500 8650 4500
Wire Wire Line
	8750 4400 8650 4400
Wire Wire Line
	8750 4300 8650 4300
Wire Wire Line
	8750 4200 8650 4200
Wire Wire Line
	8750 4100 8650 4100
Wire Wire Line
	8750 4000 8650 4000
Wire Wire Line
	8750 3900 8650 3900
Wire Wire Line
	8750 3800 8650 3800
Text GLabel 9450 4200 2    50   Input ~ 0
TRM_GND
Text Label 8650 3800 2    50   ~ 0
MC_sw
Text Label 8650 3900 2    50   ~ 0
Acc_vol
Text Label 8650 4100 2    50   ~ 0
Brake_vol
Text Label 8650 4400 2    50   ~ 0
F-R_sw
Text Label 8650 4300 2    50   ~ 0
P-E_sw
Text Label 8650 4500 2    50   ~ 0
MC_LED
Text GLabel 8650 4200 0    50   Input ~ 0
GND_MCU
Text Label 10400 4450 2    50   ~ 0
TRM_01
Wire Wire Line
	10500 1650 10400 1650
Wire Wire Line
	10500 1850 10400 1850
Wire Wire Line
	10500 3250 10400 3250
Wire Wire Line
	10500 3350 10400 3350
Wire Wire Line
	10500 3450 10400 3450
Wire Wire Line
	10500 3650 10400 3650
Wire Wire Line
	10500 3750 10400 3750
Wire Wire Line
	10500 3850 10400 3850
Wire Wire Line
	10500 3950 10400 3950
Wire Wire Line
	10500 4050 10400 4050
Wire Wire Line
	10500 4150 10400 4150
Wire Wire Line
	10500 4250 10400 4250
Wire Wire Line
	10500 4350 10400 4350
Wire Wire Line
	10500 4450 10400 4450
Text Label 10400 4250 2    50   ~ 0
TRM_02
Text Label 10400 3950 2    50   ~ 0
TRM_22
Text Label 10400 3350 2    50   ~ 0
TRM_25
Text Label 10400 3650 2    50   ~ 0
TRM_05
Text Label 10400 1650 2    50   ~ 0
TRM_15
Text Label 10400 4350 2    50   ~ 0
TRM_20
Text Label 10400 3250 2    50   ~ 0
TRM_7
Text Label 10400 3450 2    50   ~ 0
TRM_06
Text Label 10400 3850 2    50   ~ 0
TRM_04
Text Label 10400 3750 2    50   ~ 0
TRM_23
Text Label 10400 4050 2    50   ~ 0
TRM_03
Text Label 10400 4150 2    50   ~ 0
TRM_21
Text Label 10400 1850 2    50   ~ 0
TRM_14
Wire Notes Line
	11150 550  11100 4650
Wire Notes Line
	7850 4700 9200 4700
Wire Notes Line
	9200 4700 9200 6200
Connection ~ 8850 1000
Wire Notes Line
	8000 550  11150 550 
Wire Wire Line
	8850 1000 8850 750 
Text Label 8850 800  0    50   ~ 0
TRM_03
Text GLabel 8850 750  0    50   Input ~ 0
TRM_VDD
Connection ~ 7100 3100
Text Notes 6800 3650 0    50   ~ 0
Fan and battery sim
Wire Notes Line
	6700 2900 7950 2900
Wire Notes Line
	6700 3650 6700 2900
Wire Notes Line
	7950 3650 6700 3650
Wire Notes Line
	7950 2900 7950 3650
Wire Wire Line
	7450 3050 7450 3250
Wire Wire Line
	6950 3250 6950 3550
Connection ~ 7600 3400
Wire Wire Line
	7600 3400 7600 3500
Wire Wire Line
	7100 3000 7100 3100
Wire Wire Line
	7100 3100 7600 3100
Wire Wire Line
	7100 3400 7600 3400
Text Label 7450 3050 0    50   ~ 0
Battery_pot
Text Label 6950 3550 0    50   ~ 0
Fan_pot
Text GLabel 7600 3500 0    50   Input ~ 0
GND
Wire Notes Line
	5450 1750 7950 1750
Wire Notes Line
	5450 550  5450 1750
Wire Notes Line
	7950 550  5450 550 
Wire Notes Line
	7950 1750 7950 550 
Text Notes 6900 1500 0    50   ~ 0
Dashboard LEDs\n
Text GLabel 7700 1600 2    50   Input ~ 0
GND
Connection ~ 6550 1600
Wire Wire Line
	6550 1250 6550 1600
Connection ~ 6550 1250
Wire Wire Line
	7700 1250 7700 900 
Connection ~ 7700 1250
Wire Wire Line
	7700 1600 7700 1250
Wire Wire Line
	6550 1600 7700 1600
Wire Wire Line
	6550 900  6550 1250
Wire Wire Line
	6500 900  6550 900 
Wire Wire Line
	7050 1250 7150 1250
Wire Wire Line
	7050 900  7150 900 
Wire Wire Line
	5900 1600 6000 1600
Wire Wire Line
	5900 1250 6000 1250
Wire Wire Line
	5850 900  5950 900 
Text Label 7050 1250 2    50   ~ 0
Brake_LED
Text Label 7050 900  2    50   ~ 0
DRL_LED
Text Label 5900 1600 2    50   ~ 0
Battery_LED
Text Label 5900 1250 2    50   ~ 0
Right_LED
Text Label 5850 900  2    50   ~ 0
Left_LED
Wire Wire Line
	6300 1600 6350 1600
$Comp
L Device:R_Small R103
U 1 1 601CEF13
P 6450 1600
F 0 "R103" V 6646 1600 50  0000 C CNN
F 1 "R_Small" V 6555 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6450 1600 50  0001 C CNN
F 3 "~" H 6450 1600 50  0001 C CNN
	1    6450 1600
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D103
U 1 1 601CEF0D
P 6150 1600
F 0 "D103" H 6143 1345 50  0000 C CNN
F 1 "LED" H 6143 1436 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 6150 1600 50  0001 C CNN
F 3 "~" H 6150 1600 50  0001 C CNN
	1    6150 1600
	-1   0    0    1   
$EndComp
Wire Wire Line
	7450 1250 7500 1250
$Comp
L Device:R_Small R106
U 1 1 601CDD49
P 7600 1250
F 0 "R106" V 7796 1250 50  0000 C CNN
F 1 "R_Small" V 7705 1250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7600 1250 50  0001 C CNN
F 3 "~" H 7600 1250 50  0001 C CNN
	1    7600 1250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D105
U 1 1 601CDD43
P 7300 1250
F 0 "D105" H 7293 995 50  0000 C CNN
F 1 "LED" H 7293 1086 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 7300 1250 50  0001 C CNN
F 3 "~" H 7300 1250 50  0001 C CNN
	1    7300 1250
	-1   0    0    1   
$EndComp
Wire Wire Line
	7450 900  7500 900 
$Comp
L Device:R_Small R105
U 1 1 601CCC8A
P 7600 900
F 0 "R105" V 7796 900 50  0000 C CNN
F 1 "R_Small" V 7705 900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7600 900 50  0001 C CNN
F 3 "~" H 7600 900 50  0001 C CNN
	1    7600 900 
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D104
U 1 1 601CCC84
P 7300 900
F 0 "D104" H 7293 645 50  0000 C CNN
F 1 "LED" H 7293 736 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 7300 900 50  0001 C CNN
F 3 "~" H 7300 900 50  0001 C CNN
	1    7300 900 
	-1   0    0    1   
$EndComp
Wire Wire Line
	6300 1250 6350 1250
$Comp
L Device:R_Small R102
U 1 1 601CBB7A
P 6450 1250
F 0 "R102" V 6646 1250 50  0000 C CNN
F 1 "R_Small" V 6555 1250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6450 1250 50  0001 C CNN
F 3 "~" H 6450 1250 50  0001 C CNN
	1    6450 1250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D102
U 1 1 601CBB74
P 6150 1250
F 0 "D102" H 6143 995 50  0000 C CNN
F 1 "LED" H 6143 1086 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 6150 1250 50  0001 C CNN
F 3 "~" H 6150 1250 50  0001 C CNN
	1    6150 1250
	-1   0    0    1   
$EndComp
Wire Wire Line
	6250 900  6300 900 
$Comp
L Device:R_POT RV102
U 1 1 5FF46152
P 7600 3250
F 0 "RV102" H 7530 3204 50  0000 R CNN
F 1 "R_POT" H 7530 3295 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 7600 3250 50  0001 C CNN
F 3 "~" H 7600 3250 50  0001 C CNN
	1    7600 3250
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT RV101
U 1 1 5FF4580A
P 7100 3250
F 0 "RV101" H 7030 3204 50  0000 R CNN
F 1 "R_POT" H 7030 3295 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 7100 3250 50  0001 C CNN
F 3 "~" H 7100 3250 50  0001 C CNN
	1    7100 3250
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R101
U 1 1 5FF35639
P 6400 900
F 0 "R101" V 6596 900 50  0000 C CNN
F 1 "R_Small" V 6505 900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6400 900 50  0001 C CNN
F 3 "~" H 6400 900 50  0001 C CNN
	1    6400 900 
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D101
U 1 1 5FF31937
P 6100 900
F 0 "D101" H 6093 645 50  0000 C CNN
F 1 "LED" H 6093 736 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 6100 900 50  0001 C CNN
F 3 "~" H 6100 900 50  0001 C CNN
	1    6100 900 
	-1   0    0    1   
$EndComp
Wire Notes Line
	8000 4650 8000 550 
Wire Notes Line
	11100 4650 8000 4650
Text Notes 6700 2500 0    50   ~ 0
Power connector\n
Text Notes 7450 2000 0    50   ~ 0
Power on\n
Text Notes 6000 2750 0    50   ~ 0
Safe State\n
Wire Notes Line
	5150 1800 7950 1800
Wire Notes Line
	5150 2850 5150 1800
Wire Notes Line
	7950 2850 5150 2850
Wire Notes Line
	7950 1800 7950 2850
Wire Wire Line
	7300 2650 7150 2650
Wire Wire Line
	7300 2550 7150 2550
Wire Wire Line
	6950 2100 6850 2100
Wire Wire Line
	7450 2100 7350 2100
Text GLabel 7450 2100 2    50   Input ~ 0
VDD_MCU
Text GLabel 6850 2100 0    50   Input ~ 0
V_external
Wire Wire Line
	6000 2500 6000 2650
Wire Wire Line
	6000 2350 6000 2400
Text GLabel 7150 2650 0    50   Input ~ 0
GND
Text GLabel 7150 2550 0    50   Input ~ 0
V_external
$Comp
L Connector_Generic:Conn_01x02 J103
U 1 1 6002D616
P 7500 2550
F 0 "J103" H 7450 2700 50  0000 L CNN
F 1 "Conn_01x02" H 7250 2350 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S2B-XH-A-1_1x02_P2.50mm_Horizontal" H 7500 2550 50  0001 C CNN
F 3 "~" H 7500 2550 50  0001 C CNN
	1    7500 2550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J101
U 1 1 6002CD07
P 6200 2400
F 0 "J101" H 6100 2550 50  0000 L CNN
F 1 "Conn_01x02" H 6000 2200 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S2B-XH-A-1_1x02_P2.50mm_Horizontal" H 6200 2400 50  0001 C CNN
F 3 "~" H 6200 2400 50  0001 C CNN
	1    6200 2400
	1    0    0    -1  
$EndComp
Text Notes 9300 2000 0    50   ~ 0
Motor controller\n
Text Notes 9300 2400 0    50   ~ 0
Forward/reverse\n
Text Notes 9300 2800 0    50   ~ 0
Power/Eco\n
Text Label 4000 4100 0    50   ~ 0
Battery_pot
Wire Wire Line
	3900 4100 4000 4100
Wire Wire Line
	3900 4000 4000 4000
Wire Wire Line
	3900 5200 4000 5200
Wire Wire Line
	1700 5800 1600 5800
Wire Wire Line
	3900 5700 4000 5700
Wire Wire Line
	1700 5200 1600 5200
Wire Wire Line
	3900 5300 4000 5300
Wire Wire Line
	3900 6500 4000 6500
Wire Wire Line
	3900 6300 4000 6300
Wire Wire Line
	3900 6400 4000 6400
Wire Wire Line
	3900 4600 4000 4600
Text Label 4000 4000 0    50   ~ 0
Fan_pot
Text Label 4000 5200 0    50   ~ 0
Acc_vol
Text Label 1600 5800 2    50   ~ 0
Down
Text Label 4000 5700 0    50   ~ 0
Up
Text Label 4000 5300 0    50   ~ 0
MC_sw
Text Label 1550 4600 2    50   ~ 0
Left_LED
Text Label 1600 5200 2    50   ~ 0
Right_LED
Text Label 4000 6500 0    50   ~ 0
Brake_vol
Text Label 4000 6300 0    50   ~ 0
F-R_sw
Text Label 4000 6400 0    50   ~ 0
P-E_sw
Text Label 1600 5600 2    50   ~ 0
Fan_pwm
Text Label 1600 5700 2    50   ~ 0
Horn_sw
Wire Wire Line
	1700 6400 1600 6400
Wire Wire Line
	1700 5900 1600 5900
Wire Wire Line
	1700 6300 1600 6300
Wire Wire Line
	3900 3800 4000 3800
Wire Wire Line
	3900 3900 4000 3900
Text Label 1600 6400 2    50   ~ 0
DRL_sw
Text Label 1600 6300 2    50   ~ 0
HL_sw
Text Label 1600 5900 2    50   ~ 0
Select
Text Label 1600 5300 2    50   ~ 0
Brake_LED
Text Label 4000 4900 0    50   ~ 0
Left_sw
Text Label 4000 4800 0    50   ~ 0
Right_sw
Wire Wire Line
	4000 4900 3900 4900
Wire Wire Line
	4000 4800 3900 4800
Text GLabel 2700 2600 1    50   Input ~ 0
VDD_MCU
Wire Wire Line
	2700 2600 2700 2900
Text GLabel 2200 7000 0    50   Input ~ 0
GND_MCU
$Sheet
S 6150 7300 650  300 
U 60E58F6E
F0 "LCD_I2C" 50
F1 "LCD_I2C.sch" 50
F2 "SDA" I L 6150 7400 50 
F3 "SCL" I L 6150 7500 50 
$EndSheet
Wire Wire Line
	1700 5000 1600 5000
NoConn ~ 1700 4800
NoConn ~ 1700 6200
NoConn ~ 3900 5800
NoConn ~ 1700 6100
NoConn ~ 3900 6100
NoConn ~ 3900 4700
NoConn ~ 3900 4200
NoConn ~ 2300 6900
NoConn ~ 2400 6900
NoConn ~ 2500 6900
NoConn ~ 2600 6900
NoConn ~ 2700 6900
NoConn ~ 2800 6900
NoConn ~ 2900 6900
NoConn ~ 3000 6900
NoConn ~ 3100 6900
NoConn ~ 3300 6900
NoConn ~ 3900 3500
NoConn ~ 3900 3400
NoConn ~ 3900 4300
NoConn ~ 1700 6000
NoConn ~ 1700 6500
NoConn ~ 3900 5500
NoConn ~ 3900 4400
Wire Wire Line
	2600 2600 2600 2900
Text GLabel 2600 2600 1    50   Input ~ 0
MCU_5V
Text GLabel 7100 3000 0    50   Input ~ 0
MCU_5V
Text GLabel 8650 4000 0    50   Input ~ 0
MCU_5V
Text GLabel 2200 7100 0    50   Input ~ 0
GND
NoConn ~ 10500 850 
NoConn ~ 10500 950 
NoConn ~ 10500 1050
NoConn ~ 10500 1150
NoConn ~ 10500 1250
NoConn ~ 10500 1350
NoConn ~ 10500 1450
$Comp
L Connector:DB37_Female_MountingHoles J104
U 1 1 5FF5230E
P 10800 2650
F 0 "J104" H 10980 2559 50  0000 L CNN
F 1 "DB37_Female_MountingHoles" V 11000 2750 50  0000 L CNN
F 2 "Connector_Dsub:DSUB-37_Female_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm" H 10800 2650 50  0001 C CNN
F 3 " ~" H 10800 2650 50  0001 C CNN
	1    10800 2650
	1    0    0    1   
$EndComp
NoConn ~ 10500 1550
NoConn ~ 10500 1750
NoConn ~ 10500 1950
NoConn ~ 10500 2050
NoConn ~ 10500 2150
NoConn ~ 10500 2250
NoConn ~ 10500 2350
NoConn ~ 10500 2450
NoConn ~ 10500 2550
NoConn ~ 10500 2650
NoConn ~ 10500 2750
NoConn ~ 10500 2850
NoConn ~ 10500 2950
NoConn ~ 10500 3050
NoConn ~ 10500 3150
NoConn ~ 10500 3550
NoConn ~ 3300 2900
NoConn ~ 2900 2900
NoConn ~ 2800 2900
NoConn ~ 2200 2900
NoConn ~ 2500 2900
NoConn ~ 2400 2900
NoConn ~ 2300 2900
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 6034E1C9
P 1050 1350
F 0 "#FLG0101" H 1050 1425 50  0001 C CNN
F 1 "PWR_FLAG" H 1050 1523 50  0000 C CNN
F 2 "" H 1050 1350 50  0001 C CNN
F 3 "~" H 1050 1350 50  0001 C CNN
	1    1050 1350
	1    0    0    -1  
$EndComp
Text GLabel 1050 1450 0    50   Input ~ 0
VDD_MCU
Wire Wire Line
	1050 1450 1050 1350
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 6035AAFA
P 1050 900
F 0 "#FLG0102" H 1050 975 50  0001 C CNN
F 1 "PWR_FLAG" H 1050 1073 50  0000 C CNN
F 2 "" H 1050 900 50  0001 C CNN
F 3 "~" H 1050 900 50  0001 C CNN
	1    1050 900 
	1    0    0    -1  
$EndComp
Text GLabel 1050 1000 0    50   Input ~ 0
GND_MCU
Wire Wire Line
	1050 1000 1050 900 
$Comp
L Switch:SW_Push SW105
U 1 1 6037A207
P 8450 6100
F 0 "SW105" H 8450 6385 50  0000 C CNN
F 1 "SW_Push" H 8450 6294 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8450 6300 50  0001 C CNN
F 3 "~" H 8450 6300 50  0001 C CNN
	1    8450 6100
	1    0    0    -1  
$EndComp
Text Label 8100 6100 2    50   ~ 0
Reset
Wire Wire Line
	8250 6100 8100 6100
Text GLabel 8750 6100 2    50   Input ~ 0
GND_MCU
Wire Wire Line
	8750 6100 8650 6100
Text Label 1600 3500 2    50   ~ 0
Reset
Wire Wire Line
	1600 3500 1700 3500
NoConn ~ 1700 3400
Text GLabel 9450 4000 2    50   Input ~ 0
TRM_VDD
Wire Wire Line
	2200 6900 2200 7100
NoConn ~ 3900 3600
NoConn ~ 3900 3700
Wire Wire Line
	10300 5150 10300 5750
Wire Wire Line
	10750 5250 10700 5250
Wire Wire Line
	10200 5050 10200 5400
Wire Wire Line
	10100 5750 10200 5750
Connection ~ 10200 5750
Wire Wire Line
	10100 5400 10200 5400
Connection ~ 10200 5400
Wire Wire Line
	10200 5400 10200 5750
Wire Wire Line
	5300 2650 6000 2650
Wire Wire Line
	6000 2350 5700 2350
Wire Wire Line
	5300 2350 5300 2650
Text Notes 8050 1250 0    50   ~ 0
Acc volume\n
Text Notes 9700 1250 0    50   ~ 0
Brake volume\n
$Comp
L Switch:SW_SPST SW111
U 1 1 604001E9
P 5500 2350
F 0 "SW111" H 5500 2585 50  0000 C CNN
F 1 "SW_SPST" H 5500 2494 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 5500 2350 50  0001 C CNN
F 3 "~" H 5500 2350 50  0001 C CNN
	1    5500 2350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW101
U 1 1 6042FC2C
P 7150 2100
F 0 "SW101" H 7150 2335 50  0000 C CNN
F 1 "SW_SPST" H 7150 2244 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 7150 2100 50  0001 C CNN
F 3 "~" H 7150 2100 50  0001 C CNN
	1    7150 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW106
U 1 1 6043A393
P 9000 1950
F 0 "SW106" H 9000 2185 50  0000 C CNN
F 1 "SW_SPST" H 9000 2094 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 9000 1950 50  0001 C CNN
F 3 "~" H 9000 1950 50  0001 C CNN
	1    9000 1950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW107
U 1 1 604453C1
P 9000 2350
F 0 "SW107" H 9000 2585 50  0000 C CNN
F 1 "SW_SPST" H 9000 2494 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 9000 2350 50  0001 C CNN
F 3 "~" H 9000 2350 50  0001 C CNN
	1    9000 2350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW109
U 1 1 6044FB2A
P 9000 2750
F 0 "SW109" H 9000 2985 50  0000 C CNN
F 1 "SW_SPST" H 9000 2894 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 9000 2750 50  0001 C CNN
F 3 "~" H 9000 2750 50  0001 C CNN
	1    9000 2750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW112
U 1 1 6046FA60
P 9900 5400
F 0 "SW112" H 9900 5635 50  0000 C CNN
F 1 "SW_SPST" H 9900 5544 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 9900 5400 50  0001 C CNN
F 3 "~" H 9900 5400 50  0001 C CNN
	1    9900 5400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW113
U 1 1 6048486D
P 9900 5750
F 0 "SW113" H 9900 5985 50  0000 C CNN
F 1 "SW_SPST" H 9900 5894 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 9900 5750 50  0001 C CNN
F 3 "~" H 9900 5750 50  0001 C CNN
	1    9900 5750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW114
U 1 1 6048F751
P 10500 5150
F 0 "SW114" H 10500 5435 50  0000 C CNN
F 1 "SW_DPDT_x2" H 10500 5344 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 10500 5150 50  0001 C CNN
F 3 "~" H 10500 5150 50  0001 C CNN
	1    10500 5150
	1    0    0    -1  
$EndComp
Text Label 4000 3800 0    50   ~ 0
Battery_LED
Text Label 4000 5100 0    50   ~ 0
DRL_LED
Wire Wire Line
	3900 5100 4000 5100
Wire Wire Line
	1700 5300 1600 5300
Text Label 4000 4600 0    50   ~ 0
Right_acti
Wire Wire Line
	1700 5500 1600 5500
Text Label 4000 4500 0    50   ~ 0
Left_acti
Wire Wire Line
	1600 5600 1700 5600
NoConn ~ 3900 5400
Text Label 1600 5500 2    50   ~ 0
Front_acti
Text Label 4000 6200 0    50   ~ 0
Brake_acti
Wire Wire Line
	4000 4500 3900 4500
Wire Wire Line
	3900 6200 4000 6200
NoConn ~ 1700 4500
Text Label 1600 5400 2    50   ~ 0
MC_LED
Wire Wire Line
	1700 5400 1600 5400
Wire Wire Line
	6000 6600 6100 6600
Text Label 6000 6600 2    50   ~ 0
Front_acti
Wire Wire Line
	6000 6700 6100 6700
Text Label 6000 6700 2    50   ~ 0
Brake_acti
Wire Wire Line
	6000 6500 6100 6500
Text Label 6000 6500 2    50   ~ 0
Left_acti
Wire Wire Line
	6000 6900 6100 6900
Text Label 6000 6900 2    50   ~ 0
Right_acti
$Sheet
S 6100 6400 700  650 
U 6001478F
F0 "Solar_lights" 50
F1 "Solar_lights.sch" 50
F2 "Brake_acti" I L 6100 6700 50 
F3 "Left_acti" I L 6100 6500 50 
F4 "Right_acti" I L 6100 6900 50 
F5 "Front_acti" I L 6100 6600 50 
F6 "Fan_acti" I L 6100 6800 50 
F7 "Horn_acti" I L 6100 7000 50 
$EndSheet
Text Label 6050 7400 2    50   ~ 0
SDA
Wire Wire Line
	6050 7400 6150 7400
Text Label 6050 7500 2    50   ~ 0
SCL
Wire Wire Line
	6050 7500 6150 7500
NoConn ~ 3900 5600
Wire Wire Line
	2200 900  2100 900 
Wire Wire Line
	2200 800  2100 800 
Text Label 2100 900  2    50   ~ 0
CTX
Text Label 2100 800  2    50   ~ 0
CRX
$Comp
L Connector_Generic:Conn_01x02 J102
U 1 1 60157786
P 3400 1000
F 0 "J102" H 3480 992 50  0000 L CNN
F 1 "Conn_01x02" H 3480 901 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S2B-XH-A-1_1x02_P2.50mm_Horizontal" H 3400 1000 50  0001 C CNN
F 3 "~" H 3400 1000 50  0001 C CNN
	1    3400 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 1000 3200 1000
Wire Wire Line
	2950 1450 2950 1400
Wire Wire Line
	3150 1450 3150 1400
Connection ~ 3150 1000
Wire Wire Line
	3150 1100 3150 1000
Connection ~ 2950 1100
Wire Wire Line
	2950 1200 2950 1100
Wire Wire Line
	2900 1000 3150 1000
$Comp
L Jumper:SolderJumper_2_Open JP101
U 1 1 604D19E9
P 3150 1250
F 0 "JP101" V 3104 1318 50  0000 L CNN
F 1 "SolderJumper_2_Open" V 3195 1318 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 3150 1250 50  0001 C CNN
F 3 "~" H 3150 1250 50  0001 C CNN
	1    3150 1250
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 1100 2950 1100
Text GLabel 2100 1300 3    50   Input ~ 0
MCU_5V
Wire Wire Line
	2000 1200 2200 1200
Text GLabel 2000 1200 3    50   Input ~ 0
GND_MCU
Wire Wire Line
	2950 1450 3150 1450
$Comp
L Device:R_Small R104
U 1 1 5FFE6CBC
P 2950 1300
F 0 "R104" V 3050 1300 50  0000 C CNN
F 1 "120" V 2850 1300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2950 1300 50  0001 C CNN
F 3 "~" H 2950 1300 50  0001 C CNN
	1    2950 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1300 2200 1300
$Comp
L Solarteam:CJMCU_MCP2551 U102
U 1 1 5FFB993E
P 2550 1050
F 0 "U102" H 2400 1050 50  0000 C CNN
F 1 "CJMCU_MCP2551" H 2550 1400 50  0000 C CNN
F 2 "Solar_team:CJMCU_2551" H 2550 1050 50  0001 C CNN
F 3 "" H 2550 1050 50  0001 C CNN
	1    2550 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 6000 4000 6000
Wire Wire Line
	3900 5900 4000 5900
Text Label 4000 6000 0    50   ~ 0
CTX
Text Label 4000 5900 0    50   ~ 0
CRX
Text Label 1600 5000 2    50   ~ 0
SCL
Text Label 1600 5100 2    50   ~ 0
SDA
Wire Wire Line
	1700 5100 1600 5100
Wire Wire Line
	2950 1100 3200 1100
Wire Wire Line
	1550 4600 1700 4600
Text GLabel 10850 650  2    50   Input ~ 0
GND
Wire Wire Line
	10850 650  10800 650 
Text Label 6000 6800 2    50   ~ 0
Fan_pwm
Wire Wire Line
	6100 6800 6000 6800
Text Label 6000 7000 2    50   ~ 0
Horn_acti
Wire Wire Line
	6000 7000 6100 7000
Text Label 4000 3900 0    50   ~ 0
Horn_acti
Wire Wire Line
	1600 5700 1700 5700
$Comp
L Mechanical:MountingHole_Pad H101
U 1 1 60650EDA
P 7000 3950
F 0 "H101" V 6954 4100 50  0000 L CNN
F 1 "MountingHole_Pad" V 7045 4100 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7000 3950 50  0001 C CNN
F 3 "~" H 7000 3950 50  0001 C CNN
	1    7000 3950
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H102
U 1 1 6065DA9C
P 7000 4150
F 0 "H102" V 6954 4300 50  0000 L CNN
F 1 "MountingHole_Pad" V 7045 4300 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7000 4150 50  0001 C CNN
F 3 "~" H 7000 4150 50  0001 C CNN
	1    7000 4150
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H103
U 1 1 6065DD09
P 7000 4350
F 0 "H103" V 6954 4500 50  0000 L CNN
F 1 "MountingHole_Pad" V 7045 4500 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7000 4350 50  0001 C CNN
F 3 "~" H 7000 4350 50  0001 C CNN
	1    7000 4350
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H104
U 1 1 6065DFA5
P 7000 4550
F 0 "H104" V 6954 4700 50  0000 L CNN
F 1 "MountingHole_Pad" V 7045 4700 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7000 4550 50  0001 C CNN
F 3 "~" H 7000 4550 50  0001 C CNN
	1    7000 4550
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H105
U 1 1 6065E101
P 7000 4750
F 0 "H105" V 6954 4900 50  0000 L CNN
F 1 "MountingHole_Pad" V 7045 4900 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7000 4750 50  0001 C CNN
F 3 "~" H 7000 4750 50  0001 C CNN
	1    7000 4750
	0    1    1    0   
$EndComp
Wire Wire Line
	6900 3950 6900 4150
Connection ~ 6900 4150
Wire Wire Line
	6900 4150 6900 4350
Connection ~ 6900 4350
Wire Wire Line
	6900 4350 6900 4550
Connection ~ 6900 4550
Wire Wire Line
	6900 4550 6900 4750
Text GLabel 6900 4750 0    50   Input ~ 0
GND
$Comp
L Solarteam:NUCLEO64-F476RG U101
U 1 1 601A040E
P 2800 4900
F 0 "U101" H 2800 7081 50  0000 C CNN
F 1 "NUCLEO64-F476RG" H 2800 6990 50  0000 C CNN
F 2 "Solar_team:MODULE_NUCLEO-F476RG" H 3350 3000 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/data_brief/DM00105918.pdf" H 1900 3500 50  0001 C CNN
	1    2800 4900
	1    0    0    -1  
$EndComp
$EndSCHEMATC
