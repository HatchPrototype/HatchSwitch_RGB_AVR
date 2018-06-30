void initColor()
{
  sw1cOFF[0] = 0xFF;
  sw1cOFF[1] = 0x00;
  sw1cOFF[2] = 0xFF;
  sw2cOFF[0] = 0xFF;
  sw2cOFF[1] = 0x00;
  sw2cOFF[2] = 0xFF;
  sw3cOFF[0] = 0xFF;
  sw3cOFF[1] = 0x00;
  sw3cOFF[2] = 0xFF;
  sw4cOFF[0] = 0xFF;
  sw4cOFF[1] = 0x00;
  sw4cOFF[2] = 0xFF;

  sw1cON[0] = 0xFF;
  sw1cON[1] = 0x00;
  sw1cON[2] = 0x00;
  sw2cON[0] = 0xFF;
  sw2cON[1] = 0x00;
  sw2cON[2] = 0x00;
  sw3cON[0] = 0xFF;
  sw3cON[1] = 0x00;
  sw3cON[2] = 0x00;
  sw4cON[0] = 0xFF;
  sw4cON[1] = 0x00;
  sw4cON[2] = 0x00;
}


void setONcolor(byte re,byte gr, byte bl)
{
  sw1cON[0] = re;
  sw1cON[1] = gr;
  sw1cON[2] = bl;
  sw2cON[0] = re;
  sw2cON[1] = gr;
  sw2cON[2] = bl;
  sw3cON[0] = re;
  sw3cON[1] = gr;
  sw3cON[2] = bl;
  sw4cON[0] = re;
  sw4cON[1] = gr;
  sw4cON[2] = bl;
  EEPROM.write(4,re);
  delay(2);
  EEPROM.write(5,gr);
  delay(2);
  EEPROM.write(6,bl);
  delay(2);
}


void setOFFcolor(byte re,byte gr, byte bl)
{
  sw1cOFF[0] = re;
  sw1cOFF[1] = gr;
  sw1cOFF[2] = bl;
  sw2cOFF[0] = re;
  sw2cOFF[1] = gr;
  sw2cOFF[2] = bl;
  sw3cOFF[0] = re;
  sw3cOFF[1] = gr;
  sw3cOFF[2] = bl;
  sw4cOFF[0] = re;
  sw4cOFF[1] = gr;
  sw4cOFF[2] = bl;
  EEPROM.write(7,re);
  delay(2);
  EEPROM.write(8,gr);
  delay(2);
  EEPROM.write(9,bl);
  delay(2);
}
