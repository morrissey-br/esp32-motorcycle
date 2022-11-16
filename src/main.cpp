#include <Arduino.h>
#include <Engine.h>
#include <Lights.h>

#define LED_PIN 12

Engine *engine;
Lights *lights;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  engine = Engine::getInstance();
  lights = Lights::getInstance();

  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  engine->runStartMotor();
  delay(1000);
  engine->stopStartMotor();
  delay(1000);
};