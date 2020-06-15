//Transfer
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <printf.h>


//String ON = "ON";
//String OFF= "OFF":
//int led = 10;
//int button = 9;
//int buttonValue = 0;
//char text[] = "";

RF24 radio(7,8);//CNS , CE
const byte address[6] = "00001";

void setup()
{
  //pinMode(button, INPUT);
  //pinMode(led,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  //printf_begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  
}

void loop()
{
  //const char text1[]= "ON";
  //const char text1[]= "OFF";
  //char text[] = "";
  
  /*
  if( digitalRead(button) == HIGH)
  {
    char text[] = "ON";
    digitalWrite(led,HIGH);
  }
  else if(digitalRead(button) == LOW)
  {
    char text[] = "OFF";
    digitalWrite(led,LOW);
  }
  */
  const char text[] = "Hello World";
  
  radio.write(&text,sizeof(text));
  //Serial.println(text);
  delay(100);
}
