

//allocation
/*
 * 0 -- Sw1 state 
 * 1 -- Sw2 state 
 * 2 -- Sw3 state 
 * 3 -- Sw4 state 
 * 4 -- ON R
 * 5 -- ON G
 * 6 -- ON B
 * 7 -- OFF R
 * 8 -- OFF G
 * 9 -- OFF B


















//allocation
/*
 * 0 -- Sw1 state 
 * 1 -- Sw2 state 
 * 2 -- Sw3 state 
 * 3 -- Sw4 state 
 * 4 -- SW1 ON R
 * 5 -- SW1 ON G
 * 6 -- SW1 ON B
 * 7 -- SW2 ON R
 * 8 -- SW2 ON G
 * 9 -- SW2 ON B
 * 10 -- SW3 ON R
 * 11 -- SW3 ON G
 * 12 -- SW3 ON B
 * 13 -- SW4 ON R
 * 14 -- SW4 ON G
 * 15 -- SW4 ON B
 * 16 -- SW1 OFF R
 * 17 -- SW1 OFF G
 * 18 -- SW1 OFF B
 * 19 -- SW2 OFF R
 * 20 -- SW2 OFF G
 * 21 -- SW2 OFF B
 * 22 -- SW3 OFF R
 * 23 -- SW3 OFF G
 * 24 -- SW3 OFF B
 * 25 -- SW4 OFF R
 * 26 -- SW4 OFF G
 * 27 -- SW4 OFF B
 */


void initMEM()
{
  loadDefaults();
  byte memRead[10];
  byte SS1,SS2,SS3,SS4;
  SS1 = EEPROM.read(0);
  delay(5);
  SS2 = EEPROM.read(1);
  delay(5);
  SS3 = EEPROM.read(2);
  delay(5);
  SS4 = EEPROM.read(3);
  delay(5);
  
  if((SS1>0x01)||(SS2>0x01)||(SS3>0x01)||(SS4>0x01))
  {
    loadDefaults();
    Serial.println("Loading Defaults");
  }
  for(int i=0;i<=10;i++)
  {
    memRead[i]=EEPROM.read(i);
    delay(5);
  }
  if(memRead[0] == 0x00)
  {
    SW1 = false;
  }
  else
  {
    SW1 = true;
  }

  if(memRead[1] == 0x00)
  {
    SW2 = false;
  }
  else
  {
    SW2 = true;
  }

  if(memRead[2] == 0x00)
  {
    SW3 = false;
  }
  else
  {
    SW3 = true;
  }

  if(memRead[3] == 0x00)
  {
    SW4 = false;
  }
  else
  {
    SW4 = true;
  }

  setONcolor(memRead[4],memRead[5],memRead[6]);
  setOFFcolor(memRead[7],memRead[8],memRead[9]);

  
}




void loadDefaults()
{
  for(int i=0;i<=10;i++)
  {
    EEPROM.write(i,0x00);
    delay(5);
  }

  EEPROM.write(4,0xFF);
  EEPROM.write(5,0x00);
  EEPROM.write(6,0xFF);
  
  EEPROM.write(7,0x00);
  EEPROM.write(8,0x00);
  EEPROM.write(9,0xFF);

  
}




void stateChange(byte swim,bool statys)
{
  byte mat;
  if(statys == HIGH)
  {
    mat = 0x01;
  }
  else
  {
    mat = 0x00;
  }

  EEPROM.write(swim,mat);
  //EEPROM.commit();
  //Serial.print("Switch: ");
  //Serial.print(swim,HEX);
  //Serial.print(" ,State: ");
  //Serial.println(mat);
  
  //sendState();
}

