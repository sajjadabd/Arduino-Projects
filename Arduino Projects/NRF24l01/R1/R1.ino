/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//String str;
int led = 2;
boolean pos = false;

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  pinMode(led,OUTPUT);
  radio.setChannel(128);
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    //Serial.println(text);
    if(pos == false)
    {
      pos = true;
      digitalWrite(led,HIGH);
    }
    else if (pos == true)
    {
      pos = false;
      digitalWrite(led,LOW);
    }
  }
  else
  {
    //Serial.println("Radio Not Available");
    //delay(1000);
  }
  
}
