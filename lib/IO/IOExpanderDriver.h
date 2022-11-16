#include <PCF8574.h>

enum Relay
{
  DayLightRelay = 0,
  LowBeenRelay,
  HighBeenRelay,
  LeftSignalRelay,
  RightSignalRelay,
  CutCurrentRelay,
  StartMotorRelay,
  Relay8,
};

enum Button
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
  static IOExpanderDriver *instance;
  PCF8574 *buttonExpander;
  PCF8574 *relayExpander;

public:
  static IOExpanderDriver *getInstance();
  void turnOnRelay(Relay relayNumber);
  void turnOffRelay(Relay relayNumber);
  bool isButtonPressed(Relay buttonNumber);
};