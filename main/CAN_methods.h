#ifndef CANBUS
#define CANBUS

#include <Arduino.h>
#include <SPI.h>
#include <DFRobot_MCP2515.h>

void initialiseCAN(DFRobot_MCP2515& CAN);
void catchCANdata(DFRobot_MCP2515& CAN);

#endif
