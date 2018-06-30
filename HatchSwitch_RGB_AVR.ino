#include "SparkFun_Tlc5940.h"
#include <EEPROM.h>
#include <SoftwareSerial.h>

#define BU1 A1
#define BU2 A0
#define BU3 A2
#define BU4 A3
#define L1 2
#define L2 A5
#define L3 A4
#define L4 4
#define delms 4
#define ID1 0xDC
#define ID2 0x01 

SoftwareSerial wifi(8,12);

bool SW1,SW2,SW3,SW4;

bool h1,h2,h3,h4;
bool cst = false;

unsigned long current_time,next_time;
byte sw1cOFF[3],sw2cOFF[3],sw3cOFF[3],sw4cOFF[3];
byte sw1cON[3],sw2cON[3],sw3cON[3],sw4cON[3];
int sw1cCC[3],sw2cCC[3],sw3cCC[3],sw4cCC[3];



void setup() {
  Serial.begin(9600);
  
  //Serial.println("Started");
  
  setONcolor(0xFF,0x00,0xFF);
  setOFFcolor(0x00,0x00,0xFF);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  Tlc.init();
  pinMode(12,OUTPUT);
  h1 = LOW;
  h2 = LOW;
  h3 = LOW;
  h4 = LOW;
  SW1 = LOW;
  SW2 = LOW;
  SW3 = LOW;
  SW4 = LOW;
  wifi.begin(9600);
  
  //initMEM();
  
  
  

}

void loop() {
  //wifi.write("jaja");
  sendState();
  getInput();
  processColor();
  readWifi();
  writeOutput();

}




