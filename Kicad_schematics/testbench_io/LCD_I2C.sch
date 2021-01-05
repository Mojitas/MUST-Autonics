EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Solarteam:LCD_backpack U?
U 1 1 60E600B8
P 5250 3500
AR Path="/60E600B8" Ref="U?"  Part="1" 
AR Path="/60E58F6E/60E600B8" Ref="U?"  Part="1" 
F 0 "U?" H 5200 3500 50  0000 L CNN
F 1 "LCD_backpack" H 5000 3800 50  0000 L CNN
F 2 "" H 5250 3300 50  0001 C CNN
F 3 "" H 5250 3300 50  0001 C CNN
	1    5250 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3300 4900 3300
Wire Wire Line
	4800 3400 4900 3400
Wire Wire Line
	4800 3600 4900 3600
Wire Wire Line
	4800 3700 4900 3700
Text HLabel 4800 3400 0    50   Input ~ 0
SDA
Text HLabel 4800 3300 0    50   Input ~ 0
SCL
Text GLabel 4800 3600 0    50   Input ~ 0
VDD_MCU
Text GLabel 4800 3700 0    50   Input ~ 0
GND_MCU
$EndSCHEMATC
