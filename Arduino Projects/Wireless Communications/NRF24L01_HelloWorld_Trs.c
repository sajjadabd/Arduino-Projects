//Transfer
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int button = 13;
int buttonValue = 0;
const char text[] = "";

RF24 radio(7,8);//CNS , CE
const byte address[6] = "00001";

void setup()
{
	pinMode(button, INPUT);
	
	radio.begin();
	radio.openWritingPipe(address);
	radio.setPALevel(RF24_PA_MIN);
	radio.setDataRate(RF24_250KBPS);
	radio.stopListening();
}

void loop()
{
	buttonvalue = digitalRead(button);
	
	if( buttonValue == HIGH)
	{
		text[] = "ON";
	}
	else if(buttonValue == LOW)
	{
		text[] = "OFF";
	}
	
	//const char text[] = "Hello World";
	radio.write(&text,sizeof(text));
	delay(1000);
}