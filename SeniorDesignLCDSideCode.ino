#include <LiquidCrystal.h>// includes the LiquidCrystal Library 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
int pirState = LOW;             // we start, assuming no motion detected
int pirPin = 2;
int dSeven = 0;
int BIT2 = A2;
int BIT1 = A3;
int BIT0 = A4;
const int BUTTON1 = A0;
const int BUTTON2 = 3;
const int BUTTON3 = 4;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 13;
int BUTTONstate1 = 0;
int BUTTONstate2 = 0;
int BUTTONstate3 = 0;
int HammerStatus=0;
int WrenchStatus=0;
int ScrewDriverStatus=0;


void setup() {
  
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BIT1, INPUT);
  pinMode(BIT0, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display }
pinMode(pirPin, INPUT);
Serial.begin(9600);
}




void loop() 
{

lcd.print("Waiting... ");
 
lcd.clear();

dSeven = digitalRead(pirPin);
while(dSeven==LOW){//if motion was detected, pin will be inputting 5V
  lcd.print("Waiting...");
  delay(500);
  lcd.clear();
dSeven = digitalRead(pirPin);

}
lcd.clear();
lcd.print("Motion Detected");
delay(1000);
lcd.setCursor(2,1);
lcd.print("Welcome");
delay(1000);

int input = menuFunction();
BUTTONFunction();
  
lcd.clear();
}

int menuFunction(){
int selection;
lcd.clear();
lcd.print("Available"); // Prints "Tools List" on the LCD 
 lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("Tools In Box"); 
 delay(2000);
 lcd.clear(); // Clears the display 
 lcd.print ("1.Hammer");
 delay(1000); 
 lcd.print("2.Wrench");
 delay(1000);
 lcd.setCursor(1,1);
 lcd.print("3.Screwdrivers");
 delay(2000);
 lcd.clear(); // Clears the display 
lcd.print("Choose a type of");
 lcd.setCursor(1,1);
lcd.print("tool");
delay(2000);
lcd.clear();
lcd.print("Hold Button for");
 lcd.setCursor(1,1);
lcd.print("Tool Choice");
delay(4000);
lcd.clear();
}




int BUTTONFunction(){

  
  BUTTONstate1 = digitalRead(BUTTON1);
  if (BUTTONstate1 == HIGH)
  {
    digitalWrite(LED1, HIGH);
     lcd.print ("Hammer Row");
     lcd.setCursor(2,1);
     lcd.print("Illuminated");
     delay(4000); 
     lcd.clear();
     lcd.print("Scan Tool");
     lcd.setCursor(2,1);
     lcd.print("Over Pn532");
     delay(5000);
     lcd.clear();
     digitalWrite(LED1, LOW);
     
     if((digitalRead(A2)==0) && (digitalRead(A3)==0) && (digitalRead(A4)==1)){
     lcd.print ("Hammer");
     lcd.setCursor(2,1);
     lcd.print("Selected");
     delay(3000); 
     lcd.clear();
    
     if (HammerStatus==0){
      lcd.print("Hammer");
      lcd.setCursor(2,1);
      lcd.print("Scanned Out");
      delay(3000); 
      lcd.clear();
      HammerStatus=1;
    }
    else if (HammerStatus==1){
     lcd.print("Hammer");
     lcd.setCursor(2,1);
     lcd.print("Scanned In");
     delay(3000); 
     lcd.clear();
     
      HammerStatus=0;
    }
     }
  
else   {
  lcd.print("Wrong Tool");
  delay(3000); 
   lcd.clear();
  }

  }
  
else{
    digitalWrite(LED1, LOW);
  }


  
  BUTTONstate2 = digitalRead(BUTTON2);
  if (BUTTONstate2 == HIGH)
  {
    digitalWrite(LED2, HIGH);
     lcd.print ("Wrench Row");
      lcd.setCursor(2,1);
     lcd.print("Illuminated");
     delay(4000); 
     lcd.clear();
     lcd.print("Scan tool");
     lcd.setCursor(2,1);
     lcd.print("Over Pn532");
     delay(5000);
     lcd.clear();
     digitalWrite(LED2, LOW);

     if((digitalRead(A2)==0) && (digitalRead(A3)==1) && (digitalRead(A4)==0)){
      lcd.print ("Wrench");
      lcd.setCursor(2,1);
     lcd.print("Selected");
     delay(3000);
     lcd.clear();
     
     if (WrenchStatus==0){
      lcd.print("Wrench");
      lcd.setCursor(2,1);
      lcd.print("Scanned Out");
      delay(3000);
      lcd.clear();
      WrenchStatus=1;
    }
    else if (WrenchStatus==1){
      lcd.print("Wrench");
      lcd.setCursor(2,1);
      lcd.print("Scanned In");
      delay(3000);
      lcd.clear();
      WrenchStatus=0;
    }
     }
     
else {
  lcd.print("Wrong Tool");
  delay(3000); 
   lcd.clear();
}
  }
  else{
    digitalWrite(LED2, LOW);
  }


  
 BUTTONstate3 = digitalRead(BUTTON3);
  if (BUTTONstate3 == HIGH)
  {
    digitalWrite(LED3, HIGH);
     lcd.print ("ScrewDriver Row");
      lcd.setCursor(2,1);
     lcd.print("Illuminated");
     delay(4000); 
     lcd.clear();
     lcd.print("Scan tool");
     lcd.setCursor(2,1);
     lcd.print("Over Pn532");
     delay(5000);
     lcd.clear();
     digitalWrite(LED3, LOW);

     if((digitalRead(A2)==1) && (digitalRead(A3)==0) && (digitalRead(A4)==0)){
      lcd.print ("ScrewDriver");
      lcd.setCursor(2,1);
     lcd.print("Selected");
     delay(3000);
     lcd.clear();
     
     if (ScrewDriverStatus==0){
      lcd.print("ScrewDriver");
      lcd.setCursor(2,1);
      lcd.print("Scanned Out");
      delay(3000);
      lcd.clear();
      ScrewDriverStatus=1;
    }
    else if (ScrewDriverStatus==1){
      lcd.print("ScrewDriver");
      lcd.setCursor(2,1);
      lcd.print("Scanned In");
      delay(3000);
      lcd.clear();
      ScrewDriverStatus=0;
    }
     }
     
else {
  lcd.print("Wrong Tool");
  delay(3000); 
   lcd.clear();
}
  }
  else{
    digitalWrite(LED3, LOW);
  }
}





  
