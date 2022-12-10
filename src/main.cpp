#include <Arduino.h>
#include <Engine.h>
#include <Lights.h>

#define LED_PIN 12

IOExpanderDriver *ioExpanderDriver;

Engine *engine;
Lights *lights;

bool leftButton1OldState;
bool leftButton2OldState;
bool leftButton3OldState;
bool cluchOldState;
bool rightButton1OldState;
bool rightButton2OldState;
bool frontBreakOldState;

void setup()
{
  ioExpanderDriver = IOExpanderDriver::getInstance();

  engine = new Engine();
  lights = new Lights();

  pinMode(LED_PIN, OUTPUT);

  leftButton1OldState = ioExpanderDriver->isButtonPressed(LeftButton1);
  leftButton2OldState = ioExpanderDriver->isButtonPressed(LeftButton2);
  leftButton3OldState = ioExpanderDriver->isButtonPressed(LeftButton3);
  cluchOldState = ioExpanderDriver->isButtonPressed(Cluch);
  rightButton1OldState = ioExpanderDriver->isButtonPressed(RightButton1);
  rightButton2OldState = ioExpanderDriver->isButtonPressed(RightButton2);
  frontBreakOldState = ioExpanderDriver->isButtonPressed(FrontBreak);

  Serial.begin(9600);
}

void loop()
{
  bool leftButton1State = ioExpanderDriver->isButtonPressed(LeftButton1);
  bool leftButton2State = ioExpanderDriver->isButtonPressed(LeftButton2);
  bool leftButton3State = ioExpanderDriver->isButtonPressed(LeftButton3);
  bool cluchState = ioExpanderDriver->isButtonPressed(Cluch);
  bool rightButton1State = ioExpanderDriver->isButtonPressed(RightButton1);
  bool rightButton2State = ioExpanderDriver->isButtonPressed(RightButton2);
  bool frontBreakState = ioExpanderDriver->isButtonPressed(FrontBreak);

  if (leftButton1State != leftButton1OldState)
  {
    Serial.print("Left button 1 state changed to: ");
    Serial.println(leftButton1State);
  }

  if (leftButton2State != leftButton2OldState)
  {
    Serial.print("Left button 2 state changed to: ");
    Serial.println(leftButton2State);
  }

  if (leftButton3State != leftButton3OldState)
  {
    Serial.print("Left button 3 state changed to: ");
    Serial.println(leftButton3State);
  }

  if (cluchState != cluchOldState)
  {
    Serial.print("Cluch state changed to: ");
    Serial.println(cluchState);
  }

  if (rightButton1State != rightButton1OldState)
  {
    Serial.print("Right button 1 state changed to: ");
    Serial.println(rightButton1State);
    if (rightButton1State)
    {
      engine->cutCurrent();
    }
    else
    {
      engine->allowCurrent();
    }
  }

  if (rightButton2State != rightButton2OldState)
  {
    Serial.print("Right button 2 state changed to: ");
    Serial.println(rightButton2State);
    if (rightButton2State)
    {
      engine->runStartMotor();
    }
    else
    {
      engine->stopStartMotor();
    }
  }

  if (frontBreakState != frontBreakOldState)
  {
    Serial.print("Front break state changed to: ");
    Serial.println(frontBreakState);
  }

  leftButton1OldState = leftButton1State;
  leftButton2OldState = leftButton2State;
  leftButton3OldState = leftButton3State;
  cluchOldState = cluchState;
  rightButton1OldState = rightButton1State;
  rightButton2OldState = rightButton2State;
  frontBreakOldState = frontBreakState;

  delay(2);
};