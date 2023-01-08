#pragma once
#include <drivers/IOExpanderDriver.h>

class Lights
{
  IOExpanderDriver *ioExpanderDriver;

public:
  Lights();
  void turnOnDayLight();
  void turnOffDayLight();
  void turnOnLowBeen();
  void turnOffLowBeen();
  void turnOnHighBeen();
  void turnOffHighBeen();
  void turnOnLeftSignal();
  void turnOffLeftSignal();
  void turnOnRightSignal();
  void turnOffRightSignal();
  void turnOnNeutralLight();
  void turnOffNeutralLight();
};