#pragma once
#include <PCF8574.h>

enum Relay
{
  StartMotorRelay = 0,
  CutCurrentRelay,
  DayLightRelay,
  LowBeenRelay,
  HighBeenRelay,
  LeftSignalRelay,
  RightSignalRelay,
  Relay8,
};

enum Button
{
  LeftButton1 = 0,
  LeftButton2,
  LeftButton3,
  Cluch,
  RightButton1,
  RightButton2,
  FrontBreak,
  Button8,
};

class IOExpanderDriver
{

  static IOExpanderDriver *instance;
  PCF8574 *buttonExpander = nullptr;
  PCF8574 *relayExpander = nullptr;
  IOExpanderDriver();

public:
  static IOExpanderDriver *getInstance();
  void turnOnRelay(Relay relay);
  void turnOffRelay(Relay relay);
  bool isButtonPressed(Button button);
};