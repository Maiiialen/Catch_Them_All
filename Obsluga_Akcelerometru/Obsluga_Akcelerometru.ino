#include <Wire.h>

#define   I2C_ADDRESS 0x4C
#define   X_OUT       0x00
#define   Y_OUT       0x01
#define   Z_OUT       0x02
#define   INTSU       0x06
#define   MODE        0x07
#define   SR          0x08

#define POLYMONIAL_9 0x0161

//-----------------------------SETUP--------------------------------

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Ustawianie protokolu I2C..");
  SLAVE_I2C_INIT();
}

//-----------------------------LOOP--------------------------------

void loop()
{
  SLAVE_I2C_READ();
}

//-----------------------------I2C INIT-----------------------------

void SLAVE_I2C_INIT()
{
  SLAVE_I2C_SEND(MODE , 0x00); // Setting up MODE to Stand by to set SR
  delay(2);

  SLAVE_I2C_SEND(INTSU, 0x10);
  delay(2);

  SLAVE_I2C_SEND(SR   , 0x00); // Setting up SR register to 120 samples active and auto sleep mode
  delay(2);

  SLAVE_I2C_SEND(MODE , 0x01); //Setting up MODE Active to START measures
}

//--------------------------------I2C SEND--------------------------

void SLAVE_I2C_SEND(unsigned char REG_ADDRESS, unsigned  char DATA)  //SEND data to MMA7660
{
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(REG_ADDRESS);
  Wire.write(DATA);
  Wire.endTransmission();
}

//-----------------------------I2C READ-----------------------------

void SLAVE_I2C_READ() //READ MMA7660 data
{
  //unsigned char REG_ADDRESS[2];
  int REG_ADDRESS[3];
  int i = 0;
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(0x00);  // register to read
  Wire.endTransmission();
  Wire.requestFrom(I2C_ADDRESS, 3); // read a byte

  for (i = 0; i < 3; i++) {
    if (Wire.available()) {
      REG_ADDRESS[i] = Wire.read();
    }  
  }
 
  unsigned char dane[1] = {REG_ADDRESS[1]};
  byte CRC;
  CRC = CRC8_DataArray(dane);
  
  String CRC8 = String(CRC, HEX);
  String x = String(REG_ADDRESS[1]);
  String SPACE = " ";
  String ramkaDanych = String("X" + SPACE + x + SPACE + CRC8);

  Serial.println(ramkaDanych);
  delay(50);
}

//-----------------------------CRC8---------------------------------

byte CRC8_DataArray(byte *pData) {
  unsigned int Data2 = pData[0] << 8;

  for(unsigned int idx=0; idx<1; ++idx) {
    Data2 |= pData[idx];
    Data2 = CRC8_SingleByte(Data2);
  }
  Data2 = CRC8_SingleByte(Data2);

  return (byte)(Data2 >> 8);
}

unsigned int CRC8_SingleByte(unsigned int Data2) {
  unsigned int Poly = (POLYMONIAL_9 << 7);

  for(byte idx=0; idx<8; ++idx) {
    if((Data2 & 0x8000) != 0) {
      Data2 ^= Poly;
    }
    Data2 <<= 1;
  }
  return Data2;
}
