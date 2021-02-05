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
L Switch:SW_Push SW?
U 1 1 605136BD
P 6750 4250
AR Path="/605136BD" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/605136BD" Ref="SW401"  Part="1" 
F 0 "SW401" H 6750 4535 50  0000 C CNN
F 1 "SW_Push" H 6750 4444 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6750 4450 50  0001 C CNN
F 3 "~" H 6750 4450 50  0001 C CNN
	1    6750 4250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 605136C3
P 6750 4600
AR Path="/605136C3" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/605136C3" Ref="SW402"  Part="1" 
F 0 "SW402" H 6750 4885 50  0000 C CNN
F 1 "SW_Push" H 6750 4794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6750 4800 50  0001 C CNN
F 3 "~" H 6750 4800 50  0001 C CNN
	1    6750 4600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 605136C9
P 6750 4950
AR Path="/605136C9" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/605136C9" Ref="SW403"  Part="1" 
F 0 "SW403" H 6750 5235 50  0000 C CNN
F 1 "SW_Push" H 6750 5144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6750 5150 50  0001 C CNN
F 3 "~" H 6750 5150 50  0001 C CNN
	1    6750 4950
	1    0    0    -1  
$EndComp
Text GLabel 7050 4250 2    50   Input ~ 0
GND_MCU
Text GLabel 7050 4600 2    50   Input ~ 0
GND_MCU
Text GLabel 7050 4950 2    50   Input ~ 0
GND_MCU
Wire Wire Line
	6550 4250 6450 4250
Wire Wire Line
	6550 4600 6450 4600
Wire Wire Line
	6550 4950 6450 4950
Wire Wire Line
	7050 4950 6950 4950
Wire Wire Line
	6950 4600 7050 4600
Wire Wire Line
	6950 4250 7050 4250
Wire Notes Line
	7500 5400 6100 5400
Wire Notes Line
	6100 5400 6100 3900
Text Notes 7150 4000 0    50   ~ 0
Menu
Wire Notes Line
	6100 3900 7500 3900
Wire Notes Line
	7500 3900 7500 5400
Connection ~ 5200 4100
Text Notes 4900 4650 0    50   ~ 0
Fan and battery sim
Wire Notes Line
	4800 3900 6050 3900
Wire Notes Line
	4800 4650 4800 3900
Wire Notes Line
	6050 4650 4800 4650
Wire Notes Line
	6050 3900 6050 4650
Wire Wire Line
	5550 4050 5550 4250
Wire Wire Line
	5050 4250 5050 4550
Connection ~ 5700 4400
Wire Wire Line
	5700 4400 5700 4500
Wire Wire Line
	5200 4000 5200 4100
Wire Wire Line
	5200 4100 5700 4100
Wire Wire Line
	5200 4400 5700 4400
Text GLabel 5700 4500 0    50   Input ~ 0
GND
$Comp
L Device:R_POT RV?
U 1 1 60513708
P 5700 4250
AR Path="/60513708" Ref="RV?"  Part="1" 
AR Path="/6050AF4F/60513708" Ref="RV402"  Part="1" 
F 0 "RV402" H 5630 4204 50  0000 R CNN
F 1 "R_POT" H 5630 4295 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 5700 4250 50  0001 C CNN
F 3 "~" H 5700 4250 50  0001 C CNN
	1    5700 4250
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 6051370E
P 5200 4250
AR Path="/6051370E" Ref="RV?"  Part="1" 
AR Path="/6050AF4F/6051370E" Ref="RV401"  Part="1" 
F 0 "RV401" H 5130 4204 50  0000 R CNN
F 1 "R_POT" H 5130 4295 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 5200 4250 50  0001 C CNN
F 3 "~" H 5200 4250 50  0001 C CNN
	1    5200 4250
	-1   0    0    1   
$EndComp
Text GLabel 5200 4000 0    50   Input ~ 0
MCU_5V
$Comp
L Switch:SW_Push SW?
U 1 1 60513715
P 6750 5300
AR Path="/60513715" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/60513715" Ref="SW404"  Part="1" 
F 0 "SW404" H 6750 5585 50  0000 C CNN
F 1 "SW_Push" H 6750 5494 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6750 5500 50  0001 C CNN
F 3 "~" H 6750 5500 50  0001 C CNN
	1    6750 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 5300 6400 5300
Text GLabel 7050 5300 2    50   Input ~ 0
GND_MCU
Wire Wire Line
	7050 5300 6950 5300
Text HLabel 6450 4250 0    50   Input ~ 0
Down
Text HLabel 6450 4600 0    50   Input ~ 0
Up
Text HLabel 6450 4950 0    50   Input ~ 0
Select
Text HLabel 6400 5300 0    50   Input ~ 0
Reset
Text HLabel 5050 4550 2    50   Input ~ 0
Fan_pot
Text HLabel 5550 4050 2    50   Input ~ 0
Battery_pot
Text HLabel 5150 3350 0    50   Input ~ 0
Brake_LED
Text HLabel 5150 3000 0    50   Input ~ 0
DRL_LED
Text HLabel 4000 3700 0    50   Input ~ 0
Battery_LED
Text HLabel 4000 3350 0    50   Input ~ 0
Right_LED
Text HLabel 3950 3000 0    50   Input ~ 0
Left_LED
$Comp
L Device:LED D?
U 1 1 60515B5B
P 4200 3000
AR Path="/60515B5B" Ref="D?"  Part="1" 
AR Path="/6050AF4F/60515B5B" Ref="D401"  Part="1" 
F 0 "D401" H 4193 2745 50  0000 C CNN
F 1 "LED" H 4193 2836 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 4200 3000 50  0001 C CNN
F 3 "~" H 4200 3000 50  0001 C CNN
	1    4200 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60515B55
P 4500 3000
AR Path="/60515B55" Ref="R?"  Part="1" 
AR Path="/6050AF4F/60515B55" Ref="R401"  Part="1" 
F 0 "R401" V 4696 3000 50  0000 C CNN
F 1 "R_Small" V 4605 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4500 3000 50  0001 C CNN
F 3 "~" H 4500 3000 50  0001 C CNN
	1    4500 3000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4350 3000 4400 3000
$Comp
L Device:LED D?
U 1 1 60515B4E
P 4250 3350
AR Path="/60515B4E" Ref="D?"  Part="1" 
AR Path="/6050AF4F/60515B4E" Ref="D402"  Part="1" 
F 0 "D402" H 4243 3095 50  0000 C CNN
F 1 "LED" H 4243 3186 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 4250 3350 50  0001 C CNN
F 3 "~" H 4250 3350 50  0001 C CNN
	1    4250 3350
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60515B48
P 4550 3350
AR Path="/60515B48" Ref="R?"  Part="1" 
AR Path="/6050AF4F/60515B48" Ref="R402"  Part="1" 
F 0 "R402" V 4746 3350 50  0000 C CNN
F 1 "R_Small" V 4655 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4550 3350 50  0001 C CNN
F 3 "~" H 4550 3350 50  0001 C CNN
	1    4550 3350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 3350 4450 3350
$Comp
L Device:LED D?
U 1 1 60515B41
P 5400 3000
AR Path="/60515B41" Ref="D?"  Part="1" 
AR Path="/6050AF4F/60515B41" Ref="D404"  Part="1" 
F 0 "D404" H 5393 2745 50  0000 C CNN
F 1 "LED" H 5393 2836 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5400 3000 50  0001 C CNN
F 3 "~" H 5400 3000 50  0001 C CNN
	1    5400 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60515B3B
P 5700 3000
AR Path="/60515B3B" Ref="R?"  Part="1" 
AR Path="/6050AF4F/60515B3B" Ref="R404"  Part="1" 
F 0 "R404" V 5896 3000 50  0000 C CNN
F 1 "R_Small" V 5805 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5700 3000 50  0001 C CNN
F 3 "~" H 5700 3000 50  0001 C CNN
	1    5700 3000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5550 3000 5600 3000
$Comp
L Device:LED D?
U 1 1 60515B34
P 5400 3350
AR Path="/60515B34" Ref="D?"  Part="1" 
AR Path="/6050AF4F/60515B34" Ref="D405"  Part="1" 
F 0 "D405" H 5393 3095 50  0000 C CNN
F 1 "LED" H 5393 3186 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 5400 3350 50  0001 C CNN
F 3 "~" H 5400 3350 50  0001 C CNN
	1    5400 3350
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60515B2E
P 5700 3350
AR Path="/60515B2E" Ref="R?"  Part="1" 
AR Path="/6050AF4F/60515B2E" Ref="R405"  Part="1" 
F 0 "R405" V 5896 3350 50  0000 C CNN
F 1 "R_Small" V 5805 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5700 3350 50  0001 C CNN
F 3 "~" H 5700 3350 50  0001 C CNN
	1    5700 3350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5550 3350 5600 3350
$Comp
L Device:LED D?
U 1 1 60515B27
P 4250 3700
AR Path="/60515B27" Ref="D?"  Part="1" 
AR Path="/6050AF4F/60515B27" Ref="D403"  Part="1" 
F 0 "D403" H 4243 3445 50  0000 C CNN
F 1 "LED" H 4243 3536 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 4250 3700 50  0001 C CNN
F 3 "~" H 4250 3700 50  0001 C CNN
	1    4250 3700
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60515B21
P 4550 3700
AR Path="/60515B21" Ref="R?"  Part="1" 
AR Path="/6050AF4F/60515B21" Ref="R403"  Part="1" 
F 0 "R403" V 4746 3700 50  0000 C CNN
F 1 "R_Small" V 4655 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4550 3700 50  0001 C CNN
F 3 "~" H 4550 3700 50  0001 C CNN
	1    4550 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 3700 4450 3700
Wire Wire Line
	3950 3000 4050 3000
Wire Wire Line
	4000 3350 4100 3350
Wire Wire Line
	4000 3700 4100 3700
Wire Wire Line
	5150 3000 5250 3000
Wire Wire Line
	5150 3350 5250 3350
Wire Wire Line
	4600 3000 4650 3000
Wire Wire Line
	4650 3000 4650 3350
Wire Wire Line
	4650 3700 5800 3700
Wire Wire Line
	5800 3700 5800 3350
Connection ~ 5800 3350
Wire Wire Line
	5800 3350 5800 3000
Connection ~ 4650 3350
Wire Wire Line
	4650 3350 4650 3700
Connection ~ 4650 3700
Text GLabel 5800 3700 2    50   Input ~ 0
GND
Text Notes 5000 3600 0    50   ~ 0
Dashboard LEDs\n
Wire Notes Line
	6050 3850 6050 2650
Wire Notes Line
	6050 2650 3450 2650
Wire Notes Line
	3450 2650 3450 3850
Wire Notes Line
	3450 3850 6050 3850
Text HLabel 7650 3200 2    50   Input ~ 0
Right_sw
Text HLabel 7650 3000 2    50   Input ~ 0
Left_sw
Text HLabel 6500 3700 0    50   Input ~ 0
HL_sw
Text HLabel 6500 3350 0    50   Input ~ 0
DRL_sw
Text HLabel 6500 3000 0    50   Input ~ 0
Horn_sw
Wire Notes Line
	8050 2650 8050 3850
Wire Notes Line
	8050 3850 6100 3850
$Comp
L Switch:SW_DPDT_x2 SW?
U 1 1 60513733
P 7400 3100
AR Path="/60513733" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/60513733" Ref="SW408"  Part="1" 
F 0 "SW408" H 7400 3385 50  0000 C CNN
F 1 "SW_DPDT_x2" H 7400 3294 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 7400 3100 50  0001 C CNN
F 3 "~" H 7400 3100 50  0001 C CNN
	1    7400 3100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 6051372D
P 6800 3700
AR Path="/6051372D" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/6051372D" Ref="SW406"  Part="1" 
F 0 "SW406" H 6800 3935 50  0000 C CNN
F 1 "SW_SPST" H 6800 3844 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 6800 3700 50  0001 C CNN
F 3 "~" H 6800 3700 50  0001 C CNN
	1    6800 3700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW?
U 1 1 60513727
P 6800 3350
AR Path="/60513727" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/60513727" Ref="SW405"  Part="1" 
F 0 "SW405" H 6800 3585 50  0000 C CNN
F 1 "SW_SPST" H 6800 3494 50  0000 C CNN
F 2 "Solar_team:RND-Slide-Switch" H 6800 3350 50  0001 C CNN
F 3 "~" H 6800 3350 50  0001 C CNN
	1    6800 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 3350 7100 3700
Connection ~ 7100 3350
Wire Wire Line
	7000 3350 7100 3350
Connection ~ 7100 3700
Wire Wire Line
	7000 3700 7100 3700
Wire Wire Line
	7100 3000 7100 3350
Wire Wire Line
	7650 3200 7600 3200
Wire Wire Line
	7200 3100 7200 3700
Connection ~ 7200 3700
Text Notes 7400 2750 0    50   ~ 0
Vehicle signals
Wire Notes Line
	6100 2650 8050 2650
Wire Notes Line
	6100 3850 6100 2650
Wire Wire Line
	7200 3700 7350 3700
Wire Wire Line
	7650 3000 7600 3000
Wire Wire Line
	6500 3700 6600 3700
Wire Wire Line
	6500 3350 6600 3350
Wire Wire Line
	6500 3000 6700 3000
Text GLabel 7350 3700 2    50   Input ~ 0
GND_MCU
Wire Wire Line
	7100 3700 7200 3700
$Comp
L Switch:SW_Push SW?
U 1 1 605136DE
P 6900 3000
AR Path="/605136DE" Ref="SW?"  Part="1" 
AR Path="/6050AF4F/605136DE" Ref="SW407"  Part="1" 
F 0 "SW407" H 6900 3285 50  0000 C CNN
F 1 "SW_Push" H 6900 3194 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6900 3200 50  0001 C CNN
F 3 "~" H 6900 3200 50  0001 C CNN
	1    6900 3000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
