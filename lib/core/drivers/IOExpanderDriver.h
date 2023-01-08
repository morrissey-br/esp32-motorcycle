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
  NeutralLightRelay,
};

enum Button
{
  LeftButton1 = 0,
  LeftButton2,
  RightButton1,
  RightButton2,
  Cluch,
  LeftButton3,
  FrontBreak,
  Neutral,
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