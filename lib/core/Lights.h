#pragma once
#include <IOExpanderDriver.h>

class Lights
{
private:
  static Lights *instance;
  IOExpanderDriver *ioExpanderDriver;
  Lights(IOExpanderDriver *ioExpanderDriver);

public:
  static Lights *getInstance();
  void turnOnDayLight();
  void turnOffDayLight();
};