# Control Oberheim Matrix 6, 6R, 100 with Midi CC

I wanted to use my Arduino to remap Midi CC commands to Sysex for the Oberheim Matrix 6.
I used a control surface, the Beatstep Pro to control my Matrix 6!
This should also work with the Matrix 6R and 1000.

## Requirements & Prereq's
It requires a arduino (uno is what I used)
A midi shield and the Arduino midi library.
A midi cable to the Arduino
A midi cable to the Matrix 6

## Running
Compile and run it on the Arduino. 
CC to Sysex Parameter settings are documented in the code, I tried to mappings make sense.

## And...
My Matrix 6 is running 2.14/2.15 firmware for very speedy parameter changes. 
http://tauntek.com/Matrix6Firmware.htm (thank you TaunTek!!!)
YMMV with a different firmware version.

CC/Sysex commands don’t exist for the mod matrix :(

## BASED ON THIS GUY’S GREAT WORK
https://github.com/konsumer/junosex
