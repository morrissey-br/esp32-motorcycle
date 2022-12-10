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
  // Pelo oq entendi, a definição de INPUT ou INPUT_PULLUP não faz diferença, pois o módulo do expansor já tem um resistor de pull-up interno de 6.5K
  // Essa definição é pra informar a biblioteca se você colocou ou não esse pullup, e não pra ativar o interno como o arduino faz
  buttonExpander->pinMode(LeftButton1, INPUT_PULLUP);
  buttonExpander->pinMode(LeftButton2, INPUT_PULLUP);
  buttonExpander->pinMode(LeftButton3, INPUT_PULLUP);
  buttonExpander->pinMode(Cluch, INPUT_PULLUP);
  buttonExpander->pinMode(RightButton1, INPUT_PULLUP);
  buttonExpander->pinMode(RightButton2, INPUT_PULLUP);
  buttonExpander->pinMode(FrontBreak, INPUT_PULLUP);
  buttonExpander->pinMode(Button8, INPUT_PULLUP);
  buttonExpander->begin();
  buttonExpander->digitalReadAll();

  // Iniciar e configurar todos os pinos do expansor de relés como saídas
  relayExpander->pinMode(StartMotorRelay, OUTPUT);
  relayExpander->pinMode(CutCurrentRelay, OUTPUT);
  relayExpander->pinMode(DayLightRelay, OUTPUT);
  relayExpander->pinMode(LowBeenRelay, OUTPUT);
  relayExpander->pinMode(HighBeenRelay, OUTPUT);
  relayExpander->pinMode(LeftSignalRelay, OUTPUT);
  relayExpander->pinMode(RightSignalRelay, OUTPUT);
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
