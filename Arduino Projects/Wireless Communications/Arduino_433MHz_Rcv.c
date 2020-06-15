//Receiver Code
#include <VirtualWire.h>
int led = 13;
void setup()
{
	pinMode(led,OUTPUT);
	//digitalWrite(13,LOW);
	vw_setup(2000);//2000 bit per second
	vw_set_rx_pin(7);// set the receiving pin
	vw_rx_start();//start listening to pin7 for data to come
}

void loop()
{
	uint8_t bufferLength = VW_MAX_MESSAGE_LEN;
	uint8_t buffer[bufferLength];
	
	if(vw_get_message(buffer,&bufferLength))
	{
		for(int i=0;i<bufferLength;i++)
		{
			if(buffer[i] == '1')
			{
				digitalWrite(13,HIGH);
			}
			else if (buffer[i] == '0')
			{
				digitalWrite(13,LOW);
			}
		}
	}
}