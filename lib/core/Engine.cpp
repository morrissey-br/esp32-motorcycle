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
  ioExpanderDriver->turnOnRelay(Relay1);
}

void Engine::stopStartMotor()
{
  ioExpanderDriver->turnOffRelay(Relay1);
}

void Engine::allowCurrent()
{
  ioExpanderDriver->turnOnRelay(Relay2);
}

void Engine::cutCurrent()
{
  ioExpanderDriver->turnOffRelay(Relay2);
}
