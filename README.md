ScratchSensors
==============
Written by and Copyright Kevin Osborn 2012
Distributed under BSD license. See license.txt for more information
All text above must be included in any redistribution.

More info at http://baldwisdom.com


Arduino Library for Scratch Sensor Board (picoboard) emulation

Unzip the contents of this repository into a directory called ScratchSensors
in the Arduino libraries directory (or in Sketchbook/libraries)

In your sketch:
#include <ScratchSensors.h>

and then:
ScratchSensors Scratchboard;

In Setup:
Scratchboard.init();

Sensor values are stored in an array internally to the ScratchSensors class
called Values[];

The picoboard/Scratch sensor board that is emulated has specific sensor labels
that are reported:
#define RESISTA 0
#define RESISTB 1
#define RESISTC 2
#define RESISTD 3
#define SLIDER  4
#define LIGHT   5
#define SOUND   6
#define BUTTON  7

Values should be between 0 and 1023. These are scaled by scratch to be 
between 0 and 100.

BUTTON is handled in a special way: 0 is depressed and 1023 is not pressed.

Let's say you have an analog sensor like an accelerometer connected to Arduino
pins A0, A1, and A2.

Then during loop():
Values[RESISTA] = analogRead(A0);
Values[RESISTB] = analogRead(A1);
Values[RESISTC] = analogRead(A2);

then, write the packets out to the serial/usb port:
Scratchboard.report();

There's an example in the examples directory based on the Sparkfun midi shield.
It has two pots and three buttons. Of course only one of the buttons can be 
used with the Scratch buttonpressed semantics, but the others can be tested
for specific values.