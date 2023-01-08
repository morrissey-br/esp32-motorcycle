#pragma once
#include <drivers/IOExpanderDriver.h>

class Commands
{
  IOExpanderDriver *ioExpanderDriver;

public:
  Commands();
  bool isRightButton1Pressed();
  bool isRightButton2Pressed();
};