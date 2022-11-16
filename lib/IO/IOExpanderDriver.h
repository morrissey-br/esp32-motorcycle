#pragma once
#include <PCF8574.h>

enum Relay
{
  DayLightRelay = 0,
  LowBeenRelay,
  HighBeenRelay,
  LeftSignalRelay,
  RightSignalRelay,
  CutCurrentRelay,
  StartMotorRelay,
  Relay8,
};

enum Button
{
  LeftButton1 = 0,
  LeftButton2,
  LeftButton3,
  RightButton1,
  RightButton2,
  Cluch,
  FrontBreak,
  Button8,
};

class IOExpanderDriver
{
private:
  static IOExpanderDriver *instance;
  IOExpanderDriver(int buttonExpanderAddress, int relayExpanderAddress);
  PCF8574 *buttonExpander;
  PCF8574 *relayExpander;

public:
  static IOExpanderDriver *getInstance();
  void turnOnRelay(Relay relay);
  void turnOffRelay(Relay relay);
  bool isButtonPressed(Button button);
};