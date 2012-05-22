#ifndef ScratchSensors_h
#define ScratchSensors_h

// Sensor labels as defines
#define RESISTA 0
#define RESISTB 1
#define RESISTC 2
#define RESISTD 3
#define SLIDER  4
#define LIGHT   5
#define SOUND   6
#define BUTTON  7

class ScratchSensors {
 public:
  static int Values[];
  void init();
  void report(); // send the values to the scratch board
 private:
  void ScratchBoardSensorReport(int sensor, int value);
};
#endif
