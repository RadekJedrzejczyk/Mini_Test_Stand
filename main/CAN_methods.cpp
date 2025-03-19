
#include "CAN_methods.h"


void initialiseCAN(DFRobot_MCP2515& CAN){
   while( CAN.begin(CAN_500KBPS) ){   // init can bus : baudrate = 500k
        Serial.println("DFROBOT's CAN BUS Shield init fail");
        Serial.println("Please Init CAN BUS Shield again");
        delay(3000);
    }
    Serial.println("DFROBOT's CAN BUS Shield init ok!\n");
}


void catchCANdata(DFRobot_MCP2515& CAN){
  unsigned char len = 0;
  unsigned char buf[8];
  if(CAN_MSGAVAIL == CAN.checkReceive())   // check if data coming
    {
        CAN.readMsgBuf(&len, buf);   // read data,  len: data length, buf: data buf

        for(int i = 0; i<len; i++)   // print the data
        {
            Serial.write(buf[i]);
            Serial.print("\t");
        }
        Serial.println();
    }
}
