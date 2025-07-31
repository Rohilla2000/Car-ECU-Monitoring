#include "Arduino.h"
#include "Comms.h"

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200);
}

void loop()
{
  static uint32_t lastUpdate = millis();
  if (millis() - lastUpdate > 10)
  {
    requestData(50);
    lastUpdate = millis();
  }
  // Assign values to variables
  uint16_t engineSpeed = getWord(14);
  uint16_t mapKpa = getWord(4);
  int16_t coolantTemp = (int16_t)getByte(7) - 40;
  uint8_t battery = getByte(9);
  uint16_t speed = getWord(100);
  uint8_t oilPressure = getByte(104);
  uint8_t afr = getByte(10);
  int8_t advDeg = (int8_t)getByte(23);
  uint16_t tps = getWord(24);
  uint16_t iat = getByte(6);
  uint8_t dwellMs = (int8_t)getByte(3);

  // Print values to the serial monitor
  Serial.println("Engine Speed (RPM): " + String(engineSpeed));
  Serial.println("MAP (kPa): " + String(mapKpa));
  Serial.println("Coolant Temp (\367C): " + String(coolantTemp));
  Serial.println("Battery (V): " + String(battery));
  Serial.println("Speed (kph): " + String(speed));
  Serial.println("Oil Pressure (psi): " + String(oilPressure));
  Serial.println("AFR: " + String(afr));
  Serial.println("Adv (deg): " + String(advDeg));
  Serial.println("throtlle position: " + String(tps));
  Serial.println("Air Intake Temperature: " + String(iat));
  Serial.println("Dwell (ms): " + String(dwellMs));
}
