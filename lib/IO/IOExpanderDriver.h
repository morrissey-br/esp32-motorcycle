#include <PCF8574.h>

enum RelayNumber
{
  Relay1 = 0,
  Relay2,
  Relay3,
  Relay4,
  Relay5,
  Relay6,
  Relay7,
  Relay8,
};

enum ButtonNumber
{
  Button1 = 0,
  Button2,
  Button3,
  Button4,
  Button5,
  Button6,
  Button7,
  Button8,
};

class IOExpanderDriver
{
private:
  PCF8574 *buttonExpander;
  PCF8574 *relayExpander;

public:
  IOExpanderDriver(int buttonAddress, int relayAddress);
  void turnOnRelay(RelayNumber relayNumber);
  void turnOffRelay(RelayNumber relayNumber);
  bool isButtonPressed(ButtonNumber buttonNumber);
};