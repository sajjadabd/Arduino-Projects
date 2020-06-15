#include <RH_ASK.h>
#include <SPI.h>

RH_ASK Radio(2000,"",2);

void setup()
{
	Serial.begin(9600);
	
	if(!Radio.init())
	{
		Serial.println("init failed");
	}
}

void loop()
{
	char* message = "Hello";
	
	Radio.send((uint8_t *)message,strlen(message));
	Radio.waitPacketSent();
	
}