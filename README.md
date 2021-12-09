# CS 530 - Team 5 - Directonal Temperature Sensor #
The goal of this project is to create a device that reads the current temperature of the room and saves it if a button is pressed. If the room temperature rises or falls by one degree, the device will output "Hotter" or "Colder," respectively. 

# Setting Up
First, make sure you have the required hardware components and have software dependencies downloaded.
Method 1: Arduino IDE
  - Download and install the Arduino IDE from here https://www.arduino.cc/en/software
  - Clone this repository
  - Open 530proj.ino in Arduino IDE
  - Include the DHT library
    - If already downloaded, go to Include Library > Add .ZIP Libary and select DHTlib.zip
    - Alternatively, go to Include Library > Libary Manager and search for DHTLib (WARNING: not recommended
  - Plug in Arduino and confirm that it communicates with the Serial
  - Verify and Upload

# Software Dependencies
- DHT Library (for temperature sensor)
   - https://www.circuitbasics.com/wp-content/uploads/2015/10/DHTLib.zip

# Hardware Requirements
- Arduino (battery or usb powered)
- Breadboard
- Wires
- 220 Ohm Resistor
- Button
- 16x2 LCD Screen
- DHT-11 Temperature/Humidity Sensor
- (optional, for lcd) Potentiometer

# Schematic
![schematic](https://user-images.githubusercontent.com/8890306/145482942-5ac339f4-1b13-4538-8322-1284ea9a93c6.png)

# 👨 Team Members
- Chase Knowland (Leader)
- Zi Wang
- Renan Hiramatsu
