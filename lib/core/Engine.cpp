#include <Engine.h>

Engine::Engine()
{
  ioExpanderDriver = IOExpanderDriver::getInstance();
}

void Engine::runStartMotor()
{
  ioExpanderDriver->turnOnRelay(StartMotorRelay);
}

void Engine::stopStartMotor()
{
  ioExpanderDriver->turnOffRelay(StartMotorRelay);
}

void Engine::allowCurrent()
{
  ioExpanderDriver->turnOffRelay(CutCurrentRelay);
}

void Engine::cutCurrent()
{
  ioExpanderDriver->turnOnRelay(CutCurrentRelay);
}
