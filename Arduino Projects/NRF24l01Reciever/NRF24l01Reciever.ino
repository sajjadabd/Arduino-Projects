//Reciever
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//int led = 13;
//String str;

RF24 radio(7,8);//CNS,CE
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  
  //pinMode(led, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop()
{ 
  if(radio.available() > 0)
  {
    char text[32] = "";
    radio.read(&text,sizeof(text));
    //str = text;
    /*
    if ( )
    {
      digitalWrite(led , HIGH);
    }
    else if ()
    {
      digitalWrite(led,LOW);
    }
    */
    Serial.println(text);
    //Serial.println("Nothing Found");
    //Serial.println(str);
  }
  //Serial.println("Nothing Found");
  //delay(100);
}
