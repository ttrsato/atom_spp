/*
*******************************************************************************
* Copyright (c) 2023 by Tatsuro Sato
*
* describe：ATOM SPP module
* date：2023/9/6
*******************************************************************************
*/
#include "M5Atom.h"
#include "BluetoothSerial.h"

#define RX_PORT 19
#define TX_PORT 22
#define AZ_GTI_SERIAL_SPEED 9600

BluetoothSerial SerialBT;

void setup() {
  M5.begin(true, false, true);
  Serial2.begin(AZ_GTI_SERIAL_SPEED, SERIAL_8N1, RX_PORT, TX_PORT);
  SerialBT.begin("ATOM-SPP");
  M5.dis.drawpix(0, 0x000099);
}

void loop() {
  if (SerialBT.available()) {
    Serial2.write(SerialBT.read());
    delayMicroseconds(52);
  }
  if (Serial2.available()) {
    SerialBT.write(Serial2.read());  
  }
  delayMicroseconds(52);
}
