/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

int button = 2;
int led = 3;

const byte address[6] = "00001";

void setup() {
  radio.begin();
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  radio.setChannel(128);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  if(digitalRead(button) == HIGH)
  {
    radio.write(&text, sizeof(text));
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  
  
}
