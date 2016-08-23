EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:akizuki
LIBS:ftdi
LIBS:SerialUSB-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L FT231XS U2
U 1 1 57BBF529
P 3800 3700
F 0 "U2" H 3250 4500 50  0000 L CNN
F 1 "FT231XS" H 4100 4500 50  0000 L CNN
F 2 "SMD_Packages:SSOP-20" H 3800 3700 50  0000 C CNN
F 3 "" H 3800 3700 50  0000 C CNN
	1    3800 3700
	1    0    0    -1  
$EndComp
$Comp
L USB_OTG P1
U 1 1 57BBF712
P 1400 3500
F 0 "P1" H 1725 3375 50  0000 C CNN
F 1 "USB_OTG" H 1400 3700 50  0000 C CNN
F 2 "Connect:USB_Micro-B" V 1350 3400 50  0001 C CNN
F 3 "" V 1350 3400 50  0000 C CNN
	1    1400 3500
	0    -1   1    0   
$EndComp
$Comp
L R R2
U 1 1 57BBF8AF
P 2750 3400
F 0 "R2" V 2650 3400 50  0000 C CNN
F 1 "27" V 2750 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2680 3400 50  0001 C CNN
F 3 "" H 2750 3400 50  0000 C CNN
	1    2750 3400
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 57BBF8F0
P 2350 3500
F 0 "R1" V 2450 3500 50  0000 C CNN
F 1 "27" V 2350 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2280 3500 50  0001 C CNN
F 3 "" H 2350 3500 50  0000 C CNN
	1    2350 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 3400 2900 3400
Wire Wire Line
	1700 3400 2600 3400
Wire Wire Line
	1700 3500 2200 3500
Wire Wire Line
	2500 3500 3100 3500
$Comp
L GND #PWR01
U 1 1 57BBFA72
P 1800 3800
F 0 "#PWR01" H 1800 3550 50  0001 C CNN
F 1 "GND" H 1800 3650 50  0000 C CNN
F 2 "" H 1800 3800 50  0000 C CNN
F 3 "" H 1800 3800 50  0000 C CNN
	1    1800 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 57BBFA8E
P 3700 4700
F 0 "#PWR02" H 3700 4450 50  0001 C CNN
F 1 "GND" H 3700 4550 50  0000 C CNN
F 2 "" H 3700 4700 50  0000 C CNN
F 3 "" H 3700 4700 50  0000 C CNN
	1    3700 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4700 3700 4600
Wire Wire Line
	2950 4650 3900 4650
Wire Wire Line
	3900 4650 3900 4600
Connection ~ 3700 4650
Wire Wire Line
	1700 3700 1800 3700
Wire Wire Line
	1800 3700 1800 3800
$Comp
L C C2
U 1 1 57BBFACD
P 2100 3800
F 0 "C2" H 2125 3900 50  0000 L CNN
F 1 "47pF" H 2125 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2138 3650 50  0001 C CNN
F 3 "" H 2100 3800 50  0000 C CNN
	1    2100 3800
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 57BBFB00
P 2100 3100
F 0 "C1" H 2125 3200 50  0000 L CNN
F 1 "47pF" H 2125 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2138 2950 50  0001 C CNN
F 3 "" H 2100 3100 50  0000 C CNN
	1    2100 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 3400 2100 3250
Connection ~ 2100 3400
Wire Wire Line
	2100 3500 2100 3650
Connection ~ 2100 3500
$Comp
L GND #PWR03
U 1 1 57BBFB51
P 2100 4050
F 0 "#PWR03" H 2100 3800 50  0001 C CNN
F 1 "GND" H 2100 3900 50  0000 C CNN
F 2 "" H 2100 4050 50  0000 C CNN
F 3 "" H 2100 4050 50  0000 C CNN
	1    2100 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 57BBFB71
P 2350 2950
F 0 "#PWR04" H 2350 2700 50  0001 C CNN
F 1 "GND" H 2350 2800 50  0000 C CNN
F 2 "" H 2350 2950 50  0000 C CNN
F 3 "" H 2350 2950 50  0000 C CNN
	1    2350 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2950 2350 2850
Wire Wire Line
	2350 2850 2100 2850
Wire Wire Line
	2100 2850 2100 2950
Wire Wire Line
	2100 3950 2100 4050
$Comp
L NJU7223DL1-33 U1
U 1 1 57BBFE6F
P 2900 2000
F 0 "U1" H 3000 2250 60  0000 C CNN
F 1 "NJU7223DL1-33" H 3050 1750 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:TO-252-2Lead" H 2900 2000 60  0001 C CNN
F 3 "" H 2900 2000 60  0000 C CNN
	1    2900 2000
	1    0    0    -1  
$EndComp
$Comp
L R FB1
U 1 1 57BBFF1B
P 2050 1900
F 0 "FB1" V 2150 1900 50  0000 C CNN
F 1 "BLM18PG471SN1D" V 1950 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1980 1900 50  0001 C CNN
F 3 "" H 2050 1900 50  0000 C CNN
	1    2050 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	1700 3300 1800 3300
Wire Wire Line
	1800 3300 1800 1900
Wire Wire Line
	1800 1900 1900 1900
Wire Wire Line
	2200 1900 2400 1900
$Comp
L GND #PWR05
U 1 1 57BC0002
P 3600 2300
F 0 "#PWR05" H 3600 2050 50  0001 C CNN
F 1 "GND" H 3600 2150 50  0000 C CNN
F 2 "" H 3600 2300 50  0000 C CNN
F 3 "" H 3600 2300 50  0000 C CNN
	1    3600 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2100 3600 2100
Wire Wire Line
	3600 1600 3600 2300
Wire Wire Line
	3700 2600 3700 2800
Wire Wire Line
	2150 2600 3700 2600
Wire Wire Line
	2300 2600 2300 1100
Connection ~ 2300 1900
$Comp
L C C3
U 1 1 57BC0075
P 2600 1350
F 0 "C3" H 2625 1450 50  0000 L CNN
F 1 "0.1uF" H 2625 1250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2638 1200 50  0001 C CNN
F 3 "" H 2600 1350 50  0000 C CNN
	1    2600 1350
	1    0    0    -1  
$EndComp
$Comp
L C-POL C5
U 1 1 57BC010E
P 3000 1350
F 0 "C5" H 3100 1450 60  0000 C CNN
F 1 "4.7uF" H 3150 1250 60  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" V 3000 1350 60  0001 C CNN
F 3 "" V 3000 1350 60  0000 C CNN
	1    3000 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1200 3000 1100
Wire Wire Line
	2300 1100 6200 1100
Wire Wire Line
	2600 1200 2600 1100
Connection ~ 2600 1100
Wire Wire Line
	2600 1500 2600 1600
Wire Wire Line
	2600 1600 3600 1600
Connection ~ 3600 2100
Wire Wire Line
	3000 1500 3000 1600
Connection ~ 3000 1600
$Comp
L C-POL C6
U 1 1 57BC038F
P 4000 2150
F 0 "C6" H 4100 2250 60  0000 C CNN
F 1 "22uF" H 4200 2050 60  0000 C CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" V 4000 2150 60  0001 C CNN
F 3 "" V 4000 2150 60  0000 C CNN
	1    4000 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2000 4000 1900
Wire Wire Line
	3400 1900 5000 1900
$Comp
L GND #PWR06
U 1 1 57BC0441
P 4000 2400
F 0 "#PWR06" H 4000 2150 50  0001 C CNN
F 1 "GND" H 4000 2250 50  0000 C CNN
F 2 "" H 4000 2400 50  0000 C CNN
F 3 "" H 4000 2400 50  0000 C CNN
	1    4000 2400
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 57BC046B
P 4400 2150
F 0 "C7" H 4425 2250 50  0000 L CNN
F 1 "0.1uF" H 4450 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4438 2000 50  0001 C CNN
F 3 "" H 4400 2150 50  0000 C CNN
	1    4400 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2300 4000 2400
Wire Wire Line
	4000 2350 4400 2350
Wire Wire Line
	4400 2350 4400 2300
Connection ~ 4000 2350
Wire Wire Line
	4400 1900 4400 2000
Connection ~ 4000 1900
$Comp
L 3P-SW SW1
U 1 1 57BC0790
P 5450 2000
F 0 "SW1" H 5500 2250 60  0000 C CNN
F 1 "3P-SW" H 5400 1750 60  0000 C CNN
F 2 "Akizuki:SS-12D01-VG4" H 5435 2000 60  0001 C CNN
F 3 "" H 5435 2000 60  0000 C CNN
	1    5450 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3900 2800 3900 2600
Wire Wire Line
	3900 2600 5450 2600
Wire Wire Line
	5450 2600 5450 2200
Wire Wire Line
	5850 1100 5850 2300
Wire Wire Line
	5850 2300 5600 2300
Wire Wire Line
	5600 2300 5600 2200
Connection ~ 3000 1100
Wire Wire Line
	5300 2200 5300 2300
Wire Wire Line
	5300 2300 5000 2300
Wire Wire Line
	5000 2300 5000 1900
Connection ~ 4400 1900
$Comp
L C C8
U 1 1 57BC0953
P 5650 2600
F 0 "C8" H 5675 2700 50  0000 L CNN
F 1 "0.1uF" H 5700 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5688 2450 50  0001 C CNN
F 3 "" H 5650 2600 50  0000 C CNN
	1    5650 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2450 5650 2400
Wire Wire Line
	5450 2400 9100 2400
Connection ~ 5450 2400
$Comp
L GND #PWR07
U 1 1 57BC09F0
P 5650 2850
F 0 "#PWR07" H 5650 2600 50  0001 C CNN
F 1 "GND" H 5650 2700 50  0000 C CNN
F 2 "" H 5650 2850 50  0000 C CNN
F 3 "" H 5650 2850 50  0000 C CNN
	1    5650 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2850 5650 2750
$Comp
L C C4
U 1 1 57BC0FF1
P 2950 4100
F 0 "C4" H 2975 4200 50  0000 L CNN
F 1 "0.1uF" H 3000 4000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2988 3950 50  0001 C CNN
F 3 "" H 2950 4100 50  0000 C CNN
	1    2950 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 3950 2950 3100
Wire Wire Line
	2950 3100 3100 3100
Wire Wire Line
	2950 4650 2950 4250
$Comp
L CONN_02X05 P2
U 1 1 57BC1304
P 6700 3300
F 0 "P2" H 6700 3600 50  0000 C CNN
F 1 "CONN_02X05" H 6700 3000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05" H 6700 2100 50  0001 C CNN
F 3 "" H 6700 2100 50  0000 C CNN
	1    6700 3300
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X03 P3
U 1 1 57BC13BD
P 8550 3200
F 0 "P3" H 8550 3400 50  0000 C CNN
F 1 "CONN_02X03" H 8550 3000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 8550 2000 50  0001 C CNN
F 3 "" H 8550 2000 50  0000 C CNN
	1    8550 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3200 6250 3200
Wire Wire Line
	6250 3200 6250 3850
$Comp
L GND #PWR08
U 1 1 57BC151D
P 6250 3850
F 0 "#PWR08" H 6250 3600 50  0001 C CNN
F 1 "GND" H 6250 3700 50  0000 C CNN
F 2 "" H 6250 3850 50  0000 C CNN
F 3 "" H 6250 3850 50  0000 C CNN
	1    6250 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 57BC1553
P 8150 3850
F 0 "#PWR09" H 8150 3600 50  0001 C CNN
F 1 "GND" H 8150 3700 50  0000 C CNN
F 2 "" H 8150 3850 50  0000 C CNN
F 3 "" H 8150 3850 50  0000 C CNN
	1    8150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 3850 8150 3200
Wire Wire Line
	8150 3200 8300 3200
Wire Wire Line
	7200 2400 7200 3200
Wire Wire Line
	7200 3200 6950 3200
Connection ~ 5650 2400
Wire Wire Line
	9100 2400 9100 3200
Wire Wire Line
	9100 3200 8800 3200
Connection ~ 7200 2400
Wire Wire Line
	6450 3100 5850 3100
Wire Wire Line
	6450 3300 5850 3300
Wire Wire Line
	6450 3400 5850 3400
Wire Wire Line
	6450 3500 5850 3500
Wire Wire Line
	6950 3100 7450 3100
Wire Wire Line
	6950 3300 7450 3300
Wire Wire Line
	6950 3400 7450 3400
Wire Wire Line
	6950 3500 7450 3500
Wire Wire Line
	8300 3100 7800 3100
Wire Wire Line
	8300 3300 7800 3300
Wire Wire Line
	8800 3100 9450 3100
Wire Wire Line
	8800 3300 9450 3300
Entry Wire Line
	5750 3200 5850 3100
Entry Wire Line
	5750 3400 5850 3300
Entry Wire Line
	5750 3500 5850 3400
Entry Wire Line
	5750 3600 5850 3500
Entry Wire Line
	7450 3100 7550 3200
Entry Wire Line
	7450 3300 7550 3400
Entry Wire Line
	7450 3400 7550 3500
Entry Wire Line
	7450 3500 7550 3600
Wire Wire Line
	4500 3100 4850 3100
Wire Wire Line
	4500 3200 4850 3200
Wire Wire Line
	4500 3300 4850 3300
Wire Wire Line
	4500 3400 4850 3400
Wire Wire Line
	4500 3500 4850 3500
Wire Wire Line
	4500 3600 4850 3600
Wire Wire Line
	4500 3700 4850 3700
Wire Wire Line
	4500 3800 4850 3800
Entry Wire Line
	4850 3100 4950 3200
Entry Wire Line
	4850 3200 4950 3300
Entry Wire Line
	4850 3300 4950 3400
Entry Wire Line
	4850 3400 4950 3500
Entry Wire Line
	4850 3500 4950 3600
Entry Wire Line
	4850 3600 4950 3700
Entry Wire Line
	4850 3700 4950 3800
Entry Wire Line
	4850 3800 4950 3900
Wire Bus Line
	4950 3200 4950 4050
Wire Bus Line
	4950 4050 5000 4100
Wire Bus Line
	5000 4100 9500 4100
Wire Bus Line
	5700 4100 5750 4050
Wire Bus Line
	5750 4050 5750 3200
Wire Bus Line
	7500 4100 7550 4050
Wire Bus Line
	7550 4050 7550 3200
Text Label 4650 3100 0    60   ~ 0
TXD
Text Label 4650 3200 0    60   ~ 0
RXD
Text Label 4600 3300 0    60   ~ 0
/RTS
Text Label 4600 3400 0    60   ~ 0
/CTS
Text Label 4600 3500 0    60   ~ 0
/DTR
Text Label 4600 3600 0    60   ~ 0
/DSR
Text Label 4600 3700 0    60   ~ 0
/DCD
Text Label 4600 3800 0    60   ~ 0
/RI
Text Label 5850 3100 0    60   ~ 0
RXD
Text Label 7250 3100 0    60   ~ 0
TXD
Text Label 5850 3300 0    60   ~ 0
/RTS
Text Label 7250 3300 0    60   ~ 0
/CTS
Text Label 5850 3400 0    60   ~ 0
/DTR
Text Label 5850 3500 0    60   ~ 0
/DCD
Text Label 7250 3400 0    60   ~ 0
/DSR
Text Label 7250 3500 0    60   ~ 0
/RI
Entry Wire Line
	7700 3200 7800 3100
Entry Wire Line
	7700 3400 7800 3300
Entry Wire Line
	9450 3100 9550 3200
Entry Wire Line
	9450 3300 9550 3400
Wire Bus Line
	7700 3200 7700 4050
Wire Bus Line
	7700 4050 7650 4100
Wire Bus Line
	9550 3200 9550 4050
Wire Bus Line
	9550 4050 9500 4100
Text Label 7800 3100 0    60   ~ 0
RXD
Text Label 7800 3300 0    60   ~ 0
/RTS
Text Label 9250 3100 0    60   ~ 0
TXD
Text Label 9200 3300 0    60   ~ 0
/CTS
$Comp
L LED D3
U 1 1 57BC30A0
P 6200 1400
F 0 "D3" H 6200 1500 50  0000 C CNN
F 1 "BLUE" H 6200 1300 50  0000 C CNN
F 2 "LEDs:LED_0603" H 6200 1400 50  0001 C CNN
F 3 "" H 6200 1400 50  0000 C CNN
	1    6200 1400
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 57BC3231
P 6200 1850
F 0 "R5" V 6300 1850 50  0000 C CNN
F 1 "760" V 6100 1850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6130 1850 50  0001 C CNN
F 3 "" H 6200 1850 50  0000 C CNN
	1    6200 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1700 6200 1600
Wire Wire Line
	6200 1100 6200 1200
Connection ~ 5850 1100
$Comp
L GND #PWR010
U 1 1 57BC33AB
P 6200 2100
F 0 "#PWR010" H 6200 1850 50  0001 C CNN
F 1 "GND" H 6200 1950 50  0000 C CNN
F 2 "" H 6200 2100 50  0000 C CNN
F 3 "" H 6200 2100 50  0000 C CNN
	1    6200 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2100 6200 2000
Wire Wire Line
	3100 3700 2950 3700
Connection ~ 2950 3700
$Comp
L LED D1
U 1 1 57BC37C0
P 5200 4800
F 0 "D1" H 5200 4900 50  0000 C CNN
F 1 "GREEN" H 5200 4700 50  0000 C CNN
F 2 "LEDs:LED_0603" H 5200 4800 50  0001 C CNN
F 3 "" H 5200 4800 50  0000 C CNN
	1    5200 4800
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 57BC3809
P 5200 5200
F 0 "D2" H 5200 5300 50  0000 C CNN
F 1 "RED" H 5200 5100 50  0000 C CNN
F 2 "LEDs:LED_0603" H 5200 5200 50  0001 C CNN
F 3 "" H 5200 5200 50  0000 C CNN
	1    5200 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4800 4800 4800
Wire Wire Line
	4800 4800 4800 4100
Wire Wire Line
	4800 4100 4500 4100
Wire Wire Line
	4500 4200 4700 4200
Wire Wire Line
	4700 4200 4700 5200
Wire Wire Line
	4700 5200 5000 5200
$Comp
L R R3
U 1 1 57BC3961
P 5650 4800
F 0 "R3" V 5750 4800 50  0000 C CNN
F 1 "1.2K" V 5550 4800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5580 4800 50  0001 C CNN
F 3 "" H 5650 4800 50  0000 C CNN
	1    5650 4800
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 57BC39AA
P 5650 5200
F 0 "R4" V 5750 5200 50  0000 C CNN
F 1 "1.2K" V 5550 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5580 5200 50  0001 C CNN
F 3 "" H 5650 5200 50  0000 C CNN
	1    5650 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 4800 5400 4800
Wire Wire Line
	5500 5200 5400 5200
$Comp
L +5V #PWR011
U 1 1 57BC3B9C
P 2150 2600
F 0 "#PWR011" H 2150 2450 50  0001 C CNN
F 1 "+5V" H 2150 2740 50  0000 C CNN
F 2 "" H 2150 2600 50  0000 C CNN
F 3 "" H 2150 2600 50  0000 C CNN
	1    2150 2600
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR012
U 1 1 57BC3BDE
P 6000 4600
F 0 "#PWR012" H 6000 4450 50  0001 C CNN
F 1 "+5V" H 6000 4740 50  0000 C CNN
F 2 "" H 6000 4600 50  0000 C CNN
F 3 "" H 6000 4600 50  0000 C CNN
	1    6000 4600
	1    0    0    -1  
$EndComp
Connection ~ 2300 2600
Wire Wire Line
	6000 4800 5800 4800
Wire Wire Line
	6000 4600 6000 5200
Wire Wire Line
	6000 5200 5800 5200
Connection ~ 6000 4800
$EndSCHEMATC
