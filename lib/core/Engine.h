#pragma once
#include <IOExpanderDriver.h>

class Engine
{
private:
  static Engine *instance;
  IOExpanderDriver *ioExpanderDriver;
  Engine(IOExpanderDriver *ioExpanderDriver);

public:
  static Engine *getInstance();
  void runStartMotor();
  void stopStartMotor();
  void allowCurrent();
  void cutCurrent();
};