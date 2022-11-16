#include <Arduino.h>
#include <IOExpanderDriver.h>

#define LED_PIN 12

IOExpanderDriver *ioExpanderDriver;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  ioExpanderDriver = IOExpanderDriver::getInstance();

  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  Serial.println("Button 8 value: " + String(ioExpanderDriver->isButtonPressed(Button8)));
  Serial.println("Button 7 value: " + String(ioExpanderDriver->isButtonPressed(Button7)));
  delay(10);
};