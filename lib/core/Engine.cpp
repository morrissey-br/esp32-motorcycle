#include <Engine.h>

Engine *Engine::instance = nullptr;

Engine::Engine(IOExpanderDriver *ioExpanderDriver)
{
  this->ioExpanderDriver = ioExpanderDriver;
}

Engine *Engine::getInstance()
{
  if (instance == nullptr)
  {
    instance = new Engine(IOExpanderDriver::getInstance());
  }
  return instance;
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
