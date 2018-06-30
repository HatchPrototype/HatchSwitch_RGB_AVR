void getInput()
{
  int i1,i2,i3,i4;
  i1=analogRead(BU1);
  delay(delms);
  i2=analogRead(BU2);
  delay(delms);
  i3=analogRead(BU3);
  delay(delms);
  i4=analogRead(BU4);
  delay(delms);
/*
  Serial.print(i1);
   Serial.print(",");
   Serial.print(i2);
   Serial.print(",");
   Serial.print(i3);
   Serial.print(",");
   Serial.println(i4);*/
  
  //-----------------------------H1----------------------------------//
  if(i1>=900)
  {
    if((h1==LOW)&&(SW1 == LOW))
    {
      SW1 = HIGH;
      h1 = HIGH;
      stateChange(0x00,SW1);
    }
    else if((h1 == LOW)&&(SW1 == HIGH))
    {
      SW1 = LOW;
      h1 = HIGH;
      stateChange(0x00,SW1);
    }
    
  }
  else
  {
    h1 = LOW;
  }

  //-----------------------------H2----------------------------------//
  if(i2>=900)
  {
    if((h2==LOW)&&(SW2 == LOW))
    {
      SW2 = HIGH;
      h2 = HIGH;
      stateChange(0x01,SW2);
    }
    else if((h2 == LOW)&&(SW2 == HIGH))
    {
      SW2 = LOW;
      h2 = HIGH;
      stateChange(0x01,SW2);
    }
    
  }
  else
  {
    h2 = LOW;
  }

  
  //-----------------------------H3----------------------------------//

  if(i3>=900)
  {
    if((h3==LOW)&&(SW3 == LOW))
    {
      SW3 = HIGH;
      h3 = HIGH;
      stateChange(0x02,SW3);
    }
    else if((h3 == LOW)&&(SW3 == HIGH))
    {
      SW3 = LOW;
      h3 = HIGH;
      stateChange(0x02,SW3);
    }
    
  }
  else
  {
    h3 = LOW;
  }


  
  //-----------------------------H4----------------------------------//
  if(i4>=900)
  {
    current_time = millis();
    if(cst == false)
    {
      next_time = current_time + 15000;
      Serial.println("Next time set");
      cst = true;
    }

    if((current_time >= next_time)&&(cst == true))
    {
      Serial.println("Activating AP MODE");
      sendAP();
      next_time = 0;
      cst = false;
    }

    
    if((h4==LOW)&&(SW4 == LOW))
    {
      SW4 = HIGH;
      h4 = HIGH;
      stateChange(0x03,SW4);
    }
    else if((h4 == LOW)&&(SW4 == HIGH))
    {
      SW4 = LOW;
      h4 = HIGH;
      stateChange(0x03,SW4);
    }
    
  }
  else
  {
    h4 = LOW;
     next_time = 0;
      cst = false;
  }
/*
  Serial.print(i1);
  Serial.print(",");
   Serial.print(i2);
  Serial.print(",");
   Serial.print(i3);
  Serial.print(",");
  Serial.println(i4);*/
  
  
}



void processColor()
{
  if(SW1 == HIGH)
  {
    setColor(1, sw1cON[0],sw1cON[1],sw1cON[2]);
  }
  else
  {
   
    setColor(1, sw1cOFF[0],sw1cOFF[1],sw1cOFF[2]);
  
  }

  if(SW2 == HIGH)
  {
    setColor(2, sw2cON[0],sw2cON[1],sw2cON[2]);
  }
  else
  {
    
    setColor(2, sw2cOFF[0],sw2cOFF[1],sw2cOFF[2]);
 
  }

  if(SW3 == HIGH)
  {
    setColor(3, sw3cON[0],sw3cON[1],sw3cON[2]);
  }
  else
  {
    
    setColor(3, sw3cOFF[0],sw3cOFF[1],sw3cOFF[2]);
  
  }

  if(SW4 == HIGH)
  {
    setColor(4, sw4cON[0],sw4cON[1],sw4cON[2]);
  }
  else
  {
    
    
    setColor(4, sw4cOFF[0],sw4cOFF[1],sw4cOFF[2]);
    
   
  }

  updateColor();
  
}






void readWifi()
{
  byte inbuff[32];
  byte crc = 0x00;
  if(wifi.available()==13)
  {
    Serial.println("Got Stuff");
    for(int i=0;i<=12;i++)
    {
      inbuff[i] = wifi.read();
      Serial.println(inbuff[i],HEX);
    }

     
    if((inbuff[0] == 0xCC)&&(inbuff[1] == 0x77)&&(inbuff[2] == 0xCC)&&(inbuff[3] == 0x77)&&(inbuff[4] == ID1)&&(inbuff[5] == ID2))
    {
      for(int j=0;j<=11;j++)
      {
        crc ^= inbuff[j];
      }

      //Serial.println(crc,HEX);
      //Serial.println(inbuff[12],HEX);

          if((inbuff[6] == 0x06)&&(inbuff[7] == 0xAC)&&(inbuff[12] == crc))
      {
         //Serial.println("OK");
        //----------------------------SW1-------------------------//
        if(inbuff[8]== 0x01)
        {
          SW1 = HIGH;
          EEPROM.write(0,inbuff[8]);
        }
        else if(inbuff[8] == 0x00)
        {
          SW1 = LOW;
          EEPROM.write(0,inbuff[8]);
        }
        else
        {
          
        }
        //----------------------------SW2-------------------------//
        if(inbuff[9]== 0x01)
        {
          SW2 = HIGH;
          EEPROM.write(1,inbuff[9]);
        }
        else if(inbuff[9] == 0x00)
        {
          SW2 = LOW;
          EEPROM.write(1,inbuff[9]);
        }
        else
        {
          
        }

        //----------------------------SW3-------------------------//
        if(inbuff[10]== 0x01)
        {
          SW3 = HIGH;
          EEPROM.write(2,inbuff[10]);
        }
        else if(inbuff[10] == 0x00)
        {
          SW3 = LOW;
          EEPROM.write(2,inbuff[10]);
        }
        else
        {
          
        }

        //----------------------------SW4-------------------------//
        if(inbuff[11]== 0x01)
        {
          SW4 = HIGH;
          EEPROM.write(3,inbuff[11]);
        }
        else if(inbuff[11] == 0x00)
        {
          SW4 = LOW;
          EEPROM.write(3,inbuff[11]);
        }
        else
        {
          
        }

       // sendState();

      // ACK();
    
      }

      else if((inbuff[6]==0x06)&&(inbuff[7] == 0xC0)&&(inbuff[12]==crc))
      {
        if(inbuff[8]==0x00)
        {
          setOFFcolor(inbuff[9],inbuff[10],inbuff[11]);
          //sendOFFrgb();
        }
        else if(inbuff[8]==0x01)
        {
          setONcolor(inbuff[9],inbuff[10],inbuff[11]);
         // sendONrgb();
        }
      }
      //NAK();
    }
    
  }
}







void setColor(byte swi, byte Rc,byte Gc,byte Bc)
{
  int r,g,b;
  r = map(Rc,0,255,0,4095);
  g = map(Gc,0,255,0,4095);
  b = map(Bc,0,255,0,4095);
  if(swi == 1)
  {
    sw1cCC[0] = r; 
    sw1cCC[1] = g;
    sw1cCC[2] = b;
  }
  else if(swi == 2)
  {
    sw2cCC[0] = r; 
    sw2cCC[1] = g;
    sw2cCC[2] = b;
  }
  else if(swi == 3)
  {
    sw3cCC[0] = r; 
    sw3cCC[1] = g;
    sw3cCC[2] = b;
  }
  else if(swi == 4)
  {
    sw4cCC[0] = r; 
    sw4cCC[1] = g;
    sw4cCC[2] = b;
  }
}


void updateColor()
{
  
  
    Tlc.set(3, sw1cCC[0]);
    Tlc.set(4, sw1cCC[1]);
    Tlc.set(5, sw1cCC[2]);
    Tlc.set(6, sw2cCC[0]);
    Tlc.set(7, sw2cCC[1]);
    Tlc.set(8, sw2cCC[2]);
    Tlc.set(9, sw3cCC[0]);
    Tlc.set(10, sw3cCC[1]);
    Tlc.set(11, sw3cCC[2]);
    Tlc.set(12, sw4cCC[0]);
    Tlc.set(13, sw4cCC[1]);
    Tlc.set(14, sw4cCC[2]);
    Tlc.update(); 
  
  
  
}


void writeOutput()
{
  digitalWrite(L1,SW1);
  digitalWrite(L2,SW2);
  digitalWrite(L3,SW3);
  digitalWrite(L4,SW4);
}


void sendONrgb()
{
  byte buffx[10];
  buffx[0] = 0xCC;
  buffx[1] = 0x77;
  buffx[2] = 0xCC;
  buffx[3] = 0x77;
  buffx[4] = 0x02;
  buffx[5] = 0x01;
  buffx[6] = sw1cON[0];
  buffx[7] = sw1cON[1];
  buffx[8] = sw1cON[2];
  buffx[9] = 0xCC;

  wifi.write(buffx,10);
  
}


void sendOFFrgb()
{
  byte buffx[10];
  buffx[0] = 0xCC;
  buffx[1] = 0x77;
  buffx[2] = 0xCC;
  buffx[3] = 0x77;
  buffx[4] = 0x02;
  buffx[5] = 0x00;
  buffx[6] = sw1cOFF[0];
  buffx[7] = sw1cOFF[1];
  buffx[8] = sw1cOFF[2];
  buffx[9] = 0xCC;

  wifi.write(buffx,10);
  
}



void sendAP()
{
  byte buffx[10];
  buffx[0] = 0xCC;
  buffx[1] = 0x77;
  buffx[2] = 0xCC;
  buffx[3] = 0x77;
  buffx[4] = 0xAA;
  buffx[5] = 0x25;
  buffx[6] = 0x01;
  buffx[7] = 0x01;
  buffx[8] = 0x01;
  buffx[9] = 0xCC;

  wifi.write(buffx,10);
  
}



void sendState()
{
  byte buffx[10];
  buffx[0] = 0xCC;
  buffx[1] = 0x77;
  buffx[2] = 0xCC;
  buffx[3] = 0x77;
  buffx[4] = 0x01;

  if(SW1 == true)
  {
   buffx[5] = 0x01; 
  }
  else
  {
   buffx[5] = 0x00; 
  }

  if(SW2 == true)
  {
   buffx[6] = 0x01; 
  }
  else
  {
   buffx[6] = 0x00; 
  }


  if(SW3 == true)
  {
   buffx[7] = 0x01; 
  }
  else
  {
   buffx[7] = 0x00; 
  }

  if(SW4 == true)
  {
   buffx[8] = 0x01; 
  }
  else
  {
   buffx[8] = 0x00; 
  }
  
  buffx[9] = 0xCC;

  //wifi.write(buffx,10);
  
}
