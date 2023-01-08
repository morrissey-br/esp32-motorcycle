#include <Commands.h>

Commands::Commands()
{
  ioExpanderDriver = IOExpanderDriver::getInstance();
}

bool Commands::isRightButton1Pressed()
{
  return ioExpanderDriver->isButtonPressed(RightButton1);
}

bool Commands::isRightButton2Pressed()
{
  return ioExpanderDriver->isButtonPressed(RightButton2);
}