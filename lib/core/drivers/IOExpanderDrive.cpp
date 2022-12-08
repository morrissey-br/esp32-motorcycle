#include <PCF8574.h>
#include <drivers/IOExpanderDriver.h>

#define BUTTON_EXPANDER_ADDRESS 0x20
#define RELAY_EXPANDER_ADDRESS 0x21

IOExpanderDriver *IOExpanderDriver::instance = nullptr;

IOExpanderDriver::IOExpanderDriver()
{
  buttonExpander = new PCF8574(BUTTON_EXPANDER_ADDRESS);
  relayExpander = new PCF8574(RELAY_EXPANDER_ADDRESS);
  // Iniciar e configurar todos os pinos do expansor de botões como entradas
  buttonExpander->pinMode(LeftButton1, INPUT);
  buttonExpander->pinMode(LeftButton2, INPUT);
  buttonExpander->pinMode(LeftButton3, INPUT);
  buttonExpander->pinMode(RightButton1, INPUT);
  buttonExpander->pinMode(RightButton2, INPUT);
  buttonExpander->pinMode(Cluch, INPUT);
  buttonExpander->pinMode(FrontBreak, INPUT);
  buttonExpander->pinMode(Button8, INPUT);
  buttonExpander->begin();
  buttonExpander->digitalReadAll();

  // Iniciar e configurar todos os pinos do expansor de relés como saídas
  relayExpander->pinMode(DayLightRelay, OUTPUT);
  relayExpander->pinMode(LowBeenRelay, OUTPUT);
  relayExpander->pinMode(HighBeenRelay, OUTPUT);
  relayExpander->pinMode(LeftSignalRelay, OUTPUT);
  relayExpander->pinMode(RightSignalRelay, OUTPUT);
  relayExpander->pinMode(CutCurrentRelay, OUTPUT);
  relayExpander->pinMode(StartMotorRelay, OUTPUT);
  relayExpander->pinMode(Relay8, OUTPUT);
  relayExpander->begin();
  relayExpander->digitalWriteAll({HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}); // Necessário somente no módulo de relé sem inversor
}

IOExpanderDriver *IOExpanderDriver::getInstance()
{
  if (instance == nullptr)
  {
    instance = new IOExpanderDriver();
  }
  return instance;
}

void IOExpanderDriver::turnOnRelay(Relay relay)
{
  relayExpander->digitalWrite(relay, LOW);
}

void IOExpanderDriver::turnOffRelay(Relay relay)
{
  relayExpander->digitalWrite(relay, HIGH);
}

bool IOExpanderDriver::isButtonPressed(Button button)
{
  return buttonExpander->digitalRead(button) == LOW;
}
