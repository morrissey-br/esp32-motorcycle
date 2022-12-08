#pragma once
#include <drivers/IOExpanderDriver.h>

class Lights
{
  IOExpanderDriver *ioExpanderDriver;

public:
  Lights();
  void turnOnDayLight();
  void turnOffDayLight();
};