#pragma once
#include <drivers/IOExpanderDriver.h>

class Engine
{
  IOExpanderDriver *ioExpanderDriver;

public:
  Engine();
  void runStartMotor();
  void stopStartMotor();
  void allowCurrent();
  void cutCurrent();
  bool isInNeutral();
};