#include <Arduino.h>
#include <IOExpanderDriver.h>

#define LED_PIN 12

IOExpanderDriver *ioExpanderDriver;

void setup()
{
  ioExpanderDriver = new IOExpanderDriver(0x20, 0x21);
  pinMode(LED_PIN, OUTPUT);
  delay(1000);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}