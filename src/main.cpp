#include <Arduino.h>
#include <Engine.h>
#include <Lights.h>

#define LED_PIN 12

IOExpanderDriver *ioExpanderDriver;

Engine *engine;
Lights *lights;

bool rightButton1OldState;
bool rightButton2OldState;

void setup()
{
  ioExpanderDriver = IOExpanderDriver::getInstance();

  engine = new Engine();
  lights = new Lights();

  pinMode(LED_PIN, OUTPUT);

  bool rightButton1OldState = ioExpanderDriver->isButtonPressed(RightButton1);
  bool rightButton2OldState = ioExpanderDriver->isButtonPressed(RightButton2);
}

void loop()
{
  bool rightButton1State = ioExpanderDriver->isButtonPressed(RightButton1);
  bool rightButton2State = ioExpanderDriver->isButtonPressed(RightButton2);
  if (rightButton1State == true && rightButton1OldState == false)
  {
    engine->cutCurrent();
  }
  else if (rightButton1State == false && rightButton1OldState == true)
  {
    engine->allowCurrent();
  }

  if (rightButton2State == true && rightButton2OldState == false)
  {
    engine->runStartMotor();
  }
  else if (rightButton2State == false && rightButton2OldState == true)
  {
    engine->stopStartMotor();
  }

  rightButton1OldState = rightButton1State;
  rightButton2OldState = rightButton2State;
};