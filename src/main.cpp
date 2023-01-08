#include <Arduino.h>
#include <Engine.h>
#include <Lights.h>
#include <Commands.h>

#define LED_PIN 12

IOExpanderDriver *ioExpanderDriver;

Engine *engine;
Lights *lights;
Commands *commands;

void setup()
{
  ioExpanderDriver = IOExpanderDriver::getInstance();

  engine = new Engine();
  lights = new Lights();
  commands = new Commands();

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);

  lights->turnOnDayLight();
}

void loop()
{
  if (commands->isRightButton1Pressed())
  {
    engine->runStartMotor();
  }
  else
  {
    engine->stopStartMotor();
  }

  if (commands->isRightButton2Pressed())
  {
    engine->cutCurrent();
  }
  else
  {
    engine->allowCurrent();
  }

  delay(10);
};