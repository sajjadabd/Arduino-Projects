//Reciever
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int led = 13;

RF24 radio(7,8);//CNS,CE
const byte address[6] = "00001";

void setup()
{
	//Serial.begin(9600);
	
	pinMode(led, OUTPUT);
	
	radio.begin();
	radio.openReadingPipe(0,address);
	radio.setPALevel(RF24_PA_MIN);
	radio.setDataRate(RF24_250KBPS);
	radio.startListening();
}

void loop()
{	
	if(radio.available())
	{
		char text[32] = "";
		radio.read(&text,sizeof(text));
		if ( text.equals("ON"))
		{
			digitalWrite(led , HIGH);
		}
		else if (text.equals("OFF"))
		{
			digitalWrite(led,LOW);
		}
		//Serial.println(text);
	}
}