#include <Lights.h>

Lights *Lights::instance = nullptr;

Lights::Lights(IOExpanderDriver *ioExpanderDriver)
{
  this->ioExpanderDriver = ioExpanderDriver;
}

Lights *Lights::getInstance()
{
  if (instance == nullptr)
  {
    instance = new Lights(IOExpanderDriver::getInstance());
  }
  return instance;
}

void Lights::turnOnDayLight()
{
  ioExpanderDriver->turnOnRelay(DayLightRelay);
}

void Lights::turnOffDayLight()
{
  ioExpanderDriver->turnOffRelay(DayLightRelay);
}