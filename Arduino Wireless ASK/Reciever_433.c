#include <RH_ASK.h>
#include <SPI.h>

RH_ASK Radio(2000,2);

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
	uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
	uint8_t buflen = sizeof(buf);
	
	if(Radio.recv(buf,&buflen))
	{
		String text = "";
		
		for(int i=0;i<buflen;i++)
		{
			text.concat((char)buf[i]);
		}
		
		Serial.println(text);
	}
	
}