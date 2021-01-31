// Adam WC Smith - quick DS18B20 Homie sensor using Lübbe's homie-node-collection.  Based on demo-sensor-node.cpp
// 

#define FW_NAME "ESPTempSensor"
#define FW_VERSION "0.3.6"

/* Magic sequence for Autodetectable Binary Upload */
const char *__FLAGGED_FW_NAME = "\xbf\x84\xe4\x13\x54" FW_NAME "\x93\x44\x6b\xa7\x75";
const char *__FLAGGED_FW_VERSION = "\x6a\x3f\x3e\x0e\xe1" FW_VERSION "\xb0\x30\x48\xd4\x1a";
/* End of magic sequence for Autodetectable Binary Upload */

#define SERIAL_SPEED 74880

#include <Homie.h>

#define DS18B20_USECELSIUS false
#define DS18B20_MULTISENSOR true
#include "DS18B20Node.hpp"

// pin the DS18B20 is on - 
const int PIN_DS18 = 2; // ESP-01 GPIO2 / pin 2

// create the node (id, name, pin, interval).  Function also depends on DS18B20_USECELSIUS AND DS18B20_MULTISENSOR, if #defined
DS18B20Node ds18b20Node("multitemp", "multiple temperatures", PIN_DS18, 60);

void setup() {
  Homie_setFirmware(FW_NAME, FW_VERSION);

  Serial.begin(SERIAL_SPEED);
  Serial << endl
         << endl;

  Homie.disableLedFeedback();
  Homie.disableResetTrigger();

  Homie.setup();

}

void loop() {
  Homie.loop();
}