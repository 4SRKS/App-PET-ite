<img src="Images/Logo.png" width="300" height="250"><br/>
## Social Media Profiles<br/>
[**Youtube**](https://www.youtube.com/channel/UCCG3uzNam2p5G15IFZl3F-A) 
[**Facebook**](https://www.facebook.com/Ap-PET-ite-2111281949162044/?view_public_for=2111281949162044)<br/>

## Project Overveiw<br/>
The basic layout of the project is given in the figure below<br/>
![](Images/Overveiw.png)<br/>

## Project Description<br/>
The schematic above provides an overview of the project concept. The central component of the project design is a Raspberry Pi. The Pi is connected to peripheral devices that are used to control the food for a given Pet. The concept is not Pet specific and can be used to make an Automatic feeder for popular pets like cats or dogs. The design includes two analog sensors to measure the weight and the water level. These sensors are connected to the Raspberry Pi through an ADC. SPI communication protocol is used to get analog values from the two sensors. A DC motor is controlled using a motor drive circuit that includes a transistor. The user can interact with the Automatic Pet feeder through a user interface.<br/> 


## Component List<br/>
For this DIY project, we are using the Raspberry pi 3 Model B+ along with the following [Component List](https://github.com/RabiyaF/App-PET-ite/wiki/Component-List).<br/> <br/>
**Mechcanical Components List**<br/>
**1)** 1 DC Motor [6 Volts-150 RPM]<br/>
**2)** 1 Pet Food Bowl<br/> 
**3)** Wooden Planks<br/><br/>
**Electrical Components List** <br/>
**1)** 1 Analog water sensor<br/>
**2)** 1 Analog-to-digital Converter [MCP3008] <br/>
**3)** 1 4x4 Matrix Keypad <br/>
**4)** 1 Analog Weight Sensor [HX711] with a maximum weight of 2 kgs <br/>
**5)** 5 1K Resistors <br/>
**6)** 1 TIP 122 <br/>
**7)** 1 LED <br/>
**8)** 1 Diode 1N4004 <br/>
**9)** Connector wires (F-F, M-F)<br/>
After the Mechanical and Electrical Components have been procured, The following steps need to be followed to assemble App-PET-ite<br/>

# The Assembly 
## Mechanical Design Assembly <br/>
<img src="Images/Full Assembly_Mk4.JPG" width="1000"> <br/>
<img src="Images/Mk4_Prototype.JPG" width="1000"> <br/>
Shown above are a screenshot of the 3D CAD model and a photo of the final mechanical assembly.  The frame is made simply out of wood, and the clamps for the food and water tanks are made out of rigid PVC pipe with slots made in one side.  Everything else non-electrical is easily sourced in most supermarkets.  

<img src="Images/Dispenser1.JPG" width="430" height="430"><img src="Images/Dispenser2.JPG" width="430" height="430"> <br/>
The only other part requiring significant manufacturing is the dispenser mechanism, which was 3D printed.  Shown above are screenshots of this part.  For the .stl file of this component and the SolidWorks files of all the components shown in the full assembly, see the [SolidWorks/Mark 4](https://github.com/RabiyaF/App-PET-ite/tree/master/Solidworks/Mark%204) repository.  

For a full walkthrough of how we assembled the feeder, see the [Step-by-Step Assembly](https://github.com/RabiyaF/App-PET-ite/wiki/Step-by-Step-Mechanical-Assembly) page. <br/>

## Electrical Design Assembly <br/>
The first step of the electrical assembly is the PCB Fabrication.
### PCB Design <br/>
![](Images/PCB_Mounted.png)<br/>
The figure above gives a preveiw of the PCB design. It is a double layered PCB Design. It includes the circuitry for Water Level Sensor, the ADC (MCP3008), the load cell (HX711), the key pad and the motordrive circuit. The PCB can be fabricated by printing the pdf files in the Double sided PCB folder and then using that layout to make a PCB step-by-step. A tutorial to make a PCB can be found at the following link. For a doubled layered PCB design the alignment of the two layers must be perfect. While aligning PCB use the text on the left bottom as a guide to align the top and bottom halves. For a double sided PCB the process discribed in the tutorial must be repeated twice.<br/>
```
https://maker.pro/pcb/tutorial/how-to-make-a-printed-circuit-board-pcb
```
### Schematic<br/>
The figure below gives the schematic on which the PCB design is based.<br/>
![](Images/Schematic_App-PET-ite.png)<br/>

### Electrical Connections<br/>
A summary of the electrical connection is given below. <br/> 
![](Images/Connections_Pi.png)<br/>

## Flowchart<br/>
The Flow chart below gives the overveiw of the code. First, the user initializes App-PET-ite with inputs for weight and time between two subsequent feeding times. The food is then dispensed based on user input. Then two threads run simulataneously. One counts down to the next time food is to be dispensed. The other thread periodically measures the Water level.  
![](Images/Final_FlowChart.png)<br/>

## Project Prerequisites
```
git 2.21.0
cmake-3.14.2.tar.gz
Qt 4.8.7
```
## To Run
```
git clone https://github.com/RabiyaF/App-PET-ite
cd Final_codes/build
cmake ..
make
./mypjex
```
## Team Members

* **Raghul** <br/> 
1.App-PET-ite logo <br/>
2.Load cell setup and configuration<br/>
3.UI interface, Multithreading, Github repository maintenance.<br/>
4.Integration testing, Unit testing<br/>
* **Stuart Shilliday** <br/>
*Initial Concept Contribution* - Concept pitch presentation <br/>
*Mechanical Contribution* - Design, manufacture, iteration and assembly.  Step-by-Step Mechanical Assembly Wiki <br/>
*Social Media Contribution* - YouTube and Facebook pages; photography, videography, video editing and uploading <br/>
* **Rabiya Farooq**<br/> 
*Initial Concept Contribution* - Slides for pitch presentation <br/>
*Programming Contribution-* The ADC (MCP3008), Keypad, Motordrive and threads <br/>
*Electronic Contribution-* PCB hardware design and testing <br/>

## Reporting a Bug
Use this link-[App-PET-ite Bug](https://github.com/RabiyaF/App-PET-ite/issues) to contact the team members to fix issues with software. <br/>
## Acknowledgements
The follwing libraries were used to build the code
```
https://github.com/berndporr/gpio-sysfs
https://github.com/halherta/RaspberryPi-mcp3008Spi
https://github.com/dangrie158/opencushion
https://git.drogon.net/?p=wiringPi;a=summary
```
## License
GNU General Public License V3<br/>
GNU LESSER GENERAL PUBLIC LICENSE V3

## Survey
PLease participate in this survey to give insight and feedback on Ap-PET-ite for future releases.<br/>
[Ap-PET-ite Survey](https://docs.google.com/forms/d/e/1FAIpQLSdCzQ5AlhaeOhvKFN2g8C_C-drHnjaCQEvHc7EBsoWmiBpvOg/viewform?usp=sf_link)

## Version
Ap-PET-ite 1.0
* Dispenses food of given mass at given intervals, and maintains water level.
