//Transfer
#include <VirtualWire.h>


void setup()
{
	Serial.begin(9600);
	vw_setup(2000);   // setup speed
	vw_set_tx_pin(7); // setup transmission pin
}

void loop()
{
	if(Serial.available())
	{
		char c = Serial.read();
		if ( c == '1' )
		{
			vw_send((uint8_t*)c,1);
			//(uint8_t*) --> 8 bit unsiged integer arrays 
			// the second parameter is the number of bytes send in array
			//i choose 1 so i send 1 byte of array
		}
		else if ( c == '0' )
		{
			vw_send((uint8_t*)c,1);
		}
	}
}