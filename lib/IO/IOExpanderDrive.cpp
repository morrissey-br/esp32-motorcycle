#include <IOExpanderDriver.h>
#include <PCF8574.h>

IOExpanderDriver::IOExpanderDriver(int buttonAddress, int relayAddress)
{
  buttonExpander = new PCF8574(buttonAddress);
  relayExpander = new PCF8574(relayAddress);
  // Iniciar e configurar todos os pinos do expansor de botões como entradas
  buttonExpander->pinMode(Button1, INPUT);
  buttonExpander->pinMode(Button2, INPUT);
  buttonExpander->pinMode(Button3, INPUT);
  buttonExpander->pinMode(Button4, INPUT);
  buttonExpander->pinMode(Button5, INPUT);
  buttonExpander->pinMode(Button6, INPUT);
  buttonExpander->pinMode(Button7, INPUT);
  buttonExpander->pinMode(Button8, INPUT);
  buttonExpander->begin();
  buttonExpander->digitalReadAll();

  // Iniciar e configurar todos os pinos do expansor de relés como saídas
  relayExpander->pinMode(Relay1, OUTPUT);
  relayExpander->pinMode(Relay2, OUTPUT);
  relayExpander->pinMode(Relay3, OUTPUT);
  relayExpander->pinMode(Relay4, OUTPUT);
  relayExpander->pinMode(Relay5, OUTPUT);
  relayExpander->pinMode(Relay6, OUTPUT);
  relayExpander->pinMode(Relay7, OUTPUT);
  relayExpander->pinMode(Relay8, OUTPUT);
  relayExpander->begin();
  relayExpander->digitalWriteAll({HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}); // Necessário somente no módulo de relé sem inversor
}

void IOExpanderDriver::turnOnRelay(RelayNumber relayNumber)
{
  relayExpander->digitalWrite(relayNumber, LOW);
}

void IOExpanderDriver::turnOffRelay(RelayNumber relayNumber)
{
  relayExpander->digitalWrite(relayNumber, HIGH);
}

bool IOExpanderDriver::isButtonPressed(ButtonNumber buttonNumber)
{
  return buttonExpander->digitalRead(buttonNumber) == LOW;
}
