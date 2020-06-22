#### This repository is not maintained!

# 2020-Spinning-Text-Gadget
This repository is for a gadget which includes a spining 2020 text and an LCD display.

## Construction
The inside of the enclosure contained the following components:
- Arduino Nano or custom ATmega based driver board
- 16*2 LCD
- (Optional) Buck converter to be used with a 9V power source if not using a Nano
- SG90 servo motor

The LCD is wired to the Arduino as defined in the Arduino program for the data pins (see Arduino's LCD tutorial for more detains in terms of wiring). The servo is connect to pin A0 of the Arduino (as well as the power pins).

## Note:
- This was a one-time project of mine, so this repository	will probably not be maintained. Feel free to look around though :)
- This gadget was designed as a gadget for graduating seniors during the year 2020 (which is when Covid-19 was an ongoing pandamic, in case you're seeing this in the future)
- The top "congratulations" text is currently extremely difficult to print with a 3D printer, as the letters are tiny and supports are difficult to remove. I might go back and redesign it so that the text and the top base are 2 different parts to ease 3D printing it. 
