/**************************************************************************/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include <LiquidCrystal.h>// includes the LiquidCrystal Library 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

// If using the breakout with SPI, define the pins for SPI communication.
#define PN532_SCK  (2)
#define PN532_MOSI (3)
#define PN532_SS   (4)
#define PN532_MISO (5)

const int BIT2 = 10;
const int BIT1 = 9;
const int BIT0 = 8;

// If using the breakout or shield with I2C, define just the pins connected
// to the IRQ and reset lines.  Use the values below (2, 3) for the shield!
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield


// Use this line for a breakout with a software SPI connection (recommended):
Adafruit_PN532 nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS);


void setup(void) {
  pinMode(BIT2, OUTPUT);
  pinMode(BIT1, OUTPUT);
  pinMode(BIT0, OUTPUT);
  Serial.begin(9600);
  while (!Serial) delay(10); // for Leonardo/Micro/Zero

  Serial.println("Hello!");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
  Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
  
  Serial.println("Waiting for an ISO14443A Card ...");
}


void loop(void) {
 
  
  uint8_t uidHammer[] = {198, 64, 31, 89};//hammer array
  uint8_t uidWrench[] = {22, 97, 27, 89};//Wrench array
  uint8_t uidScrew[] = {86, 16, 27, 89};//screwdriver array

  
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0};  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)


   \

  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  
  if (success) {
    //turn LEDS off to begin
    digitalWrite(BIT2,LOW);
    digitalWrite(BIT1, LOW);
    digitalWrite(BIT0, LOW);
     //convert the byte array into string
    
    String uidS;
    for(int i=0;i<4;i++){
      uidS+=uid[i];
    }
    
    String hammerUids;
    for(int x=0;x<4;x++){
      hammerUids+=uidHammer[x];
    }
    
    String screwUids;
    for(int y=0;y<4;y++){
      screwUids+=uidScrew[y];
    }

    String wrenchUids;
    for(int z=0;z<4;z++){
      wrenchUids+=uidWrench[z];
    }
   



    
    // Display some basic information about the card
    Serial.println("Found an ISO14443A card");
    Serial.print("  UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("  UID Value: ");
    nfc.PrintHex(uid, uidLength);
    Serial.println("");
    

    
Serial.println(uidS);
if(uidS == hammerUids){
  
Serial.println("Hammer");
digitalWrite(BIT2, LOW);
digitalWrite(BIT1, LOW);
digitalWrite(BIT0, HIGH);
delay(1000);
}
else if(uidS == wrenchUids){
  
Serial.println("Wrench");
digitalWrite(BIT2, LOW);
digitalWrite(BIT1, HIGH);
digitalWrite(BIT0, LOW);
delay(1000);
}
else if(uidS == screwUids){
  
Serial.println("ScrewDriver");
digitalWrite(BIT2, HIGH);
digitalWrite(BIT1, LOW);
digitalWrite(BIT0, LOW);
delay(1000);
}
else{
  digitalWrite(BIT2, LOW);
  digitalWrite(BIT1, LOW);
  digitalWrite(BIT0, LOW);
}




      
    
  }
}
