// simple scratch sensorboard emulation library for arduino
#include "Arduino.h"
#include "ScratchSensors.h"

int ScratchSensors::Values[8]; //buffer to hold sensor values

void ScratchSensors::init(){
  Serial.begin(38400);
  for (int i = 0 ;i <7; i++)
    Values[i] = 0;
  Values[7]=1023; //the button not pressed value
}

void ScratchSensors::report(){
  if (Serial.available()){
    if(Serial.read() == 0x01){
      for (int i=0; i < 8; i++)
	ScratchBoardSensorReport(i, Values[i]);
    }
  }
  delay(30); //not sure this is necessary.
}





void ScratchSensors::ScratchBoardSensorReport(int sensor, int value)
{
  Serial.write( B10000000
                 | ((sensor & B1111)<<3)
                 | ((value>>7) & B111));
  delayMicroseconds(400);
  Serial.write( value & B1111111);
}
