#include <Lights.h>

Lights::Lights()
{
  ioExpanderDriver = IOExpanderDriver::getInstance();
}

void Lights::turnOnDayLight()
{
  ioExpanderDriver->turnOnRelay(DayLightRelay);
}

void Lights::turnOffDayLight()
{
  ioExpanderDriver->turnOffRelay(DayLightRelay);
}