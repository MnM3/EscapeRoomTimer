# About this Project

This project was created for an escaperoom that had climate change as an overall topic.

This project holds the components for the timer, used for the escape room. Instead of normal minutes the timer wents up to the year 2100 and a corresponding average yearly temparature of 5 degress Celsius, all over the course of 70 minutes. 

## Description of the System

The way the system works is the following:

- Before a group enters the room: On a computer the python script inside of "USBButtonScript" and the node Server inside of "Server" gets started and the "Doom(1).html" is opened and shown at full screen in a browser.
- after the group has entered, the start button on the timer is pressed an the timer starts running. Now the group has 70 minutes till the timer stops at 2100 and 5 degress Celsius.
- Inside of the room there is a bluetooth button, that needs to be found and unlocked.
- After pressing the button, the Computer receives a signal by the buttons slave module, that is connected to the computer via usb. The script in "USBButtonScript" listens for the signal and places a post request to the server, which changes the corresponding state variable to 1, the script also plays the message sound with further instructions for the group
- the timer/"Doom(1).html" reads the value from the server and sets itself to stage two, resetting the timer and running for another 20 minutes, up to the mark of 2 degrees

## The Bluetooth Buttons

The Button found by the group contains an HC-05 module connected to an arduino nano, run by a 9-Volt battery. The HC-05 module is configured into Master mode and coupled to the adress of the Slave module, which also is a HC-05 connected to an Arduino, which is connected to a computer via USB. On pressing the Button the slave module forwards a message to the computer that can be read.