# App-PET-ite <br/>
![](Images/Logo.png)<br/>
## Project Description<br/>
The below schematic provides an outline for an automatic pet feeder. It dispenses food and liquid in a controlled manner, and montitors the amount of food/liquid. The pet is provided a RFID fob, which, in the vicinity of the the RFID reader, instructs the controller to dispense food with respect to an earlier programmed quantity. The water level and load are measured by sensors and provided to the Raspberry pi using SPI interface. The user is provided with a keypad and a LCD Panel to interact with the system.

## Social Media Profiles<br/>
**Youtube:**<br/>
**Twitter:**<br/>
**Instagram:**<br/>
**Facebook:**<br/>

## Project Overveiw<br/>
The basic layout of the project is given in the schematic below<br/>
![](Images/Project%20Overveiw.png)<br/>

## Project Prerequisites
For this DIY project, we are using the Raspberry pi 3 Model B+ along with the folowing componenets list. 

## Component List<br/>
1) **1 Analog water sensor**. Can be purchased at the following link: https://www.amazon.co.uk/HALJIA-Sensor-Detection-Surface-Arduino/dp/B06XQ496SW/ref=pd_day0_hl_107_3?_encoding=UTF8&pd_rd_i=B06XQ496SW&pd_rd_r=b7f2527c-2314-11e9-846f-6dde6419884f&pd_rd_w=CWTOB&pd_rd_wg=PMdJh&pf_rd_p=b082d07b-aaea-4f40-9ff3-d27463f747d7&pf_rd_r=WXCNWY6XG73C9BBJ3EXM&psc=1&refRID=WXCNWY6XG73C9BBJ3EXM <br/>
2) **1 Analog-to-digital Converter [MCP3008]**. Can be purchased at the following link: https://www.amazon.co.uk/Adafruit-MCP3008-856-Converter-Interface/dp/B00NAY3RB2/ref=olp_product_details?_encoding=UTF8&me= <br/>
3) **1 Matrix Keypad**. Can be purchased at the following link: https://www.amazon.co.uk/Preptec-switch-Membrane-Arduino-keyboard/dp/B01MECWAW5/ref=sr_1_15?ie=UTF8&qid=1548848567&sr=8-15&keywords=numeric+keypad+raspberry+pi <br/>
4) **1 Analog Weight Sensor [HX711]. with a maximum weight of 2 kgs**. Can be purchased at the following link: https://www.amazon.co.uk/Amplifier-Breakout-Portable-Weighing-Raspberry/dp/B07LD6X1W4/ref=sr_1_3?ie=UTF8&qid=1548693587&sr=8-3&keywords=weight+sensors+arduino <br/>
5) **1 DC Motor [6 Volts-150 RPM]**. Can be purchased at the following link: https://www.amazon.co.uk/dp/B01NCQTK3S/ref=cm_sw_r_wa_apa_i_wk3DCbPYCZ3V0 <br/>
6) **1 Pet Food Bowl**. Can be purchased at the following link: https://www.amazon.co.uk/miaosun-Double-Stainless-Non-spill-Design/dp/B073J8F2S8/ref=sr_1_7?crid=34COUBAHATHG5&keywords=pet+food+bowl&qid=1552319954&s=gateway&sprefix=pet+food+bo%2Caps%2C163&sr=8-7 <br/>

## Schematic<br/>


## Electrical Connections<br/>


## Flowchart<br/>


## PCB Design <br/>
<img src="Images/PCB.png" width="500"> <br/>
The figure above gives a preveiw of the PCB design. It includes the circuitry for Water Level Sensor, the ADC (MCP3008), the load cell (HX711), the key pad and the motordrive circuit. The PCB can be fabricated by printing the pdf file in the PCB folder and then using that layout to make a PCB step-by-step. A tutorial to make a PCB can be found at the following link
```
https://maker.pro/pcb/tutorial/how-to-make-a-printed-circuit-board-pcb
```


