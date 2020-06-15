#include <RH_ASK.h>
#include <SPI.h>

RH_ASK Radio(2000,"",2);

int button1 = 11;
int button2 = 12;

int x;
int y;

void setup()
{
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  
  Serial.begin(9600);
  
  if(!Radio.init())
  {
    Serial.println("init failed");
  }
}

void loop()
{
  char* message1 = "ONN";
  char* message2 = "OFF";

  x = digitalRead(button1);

  if( x == 0 )
  {
    for(int i=0;i<2;i++)
    {
      Radio.send((uint8_t *)message1,strlen(message1));
      Radio.waitPacketSent();
    }
  }
  while(digitalRead(button1) == 0);

  y = digitalRead(button2);

  if( y == 0 )
  {
    for(int i=0;i<2;i++)
    {
      Radio.send((uint8_t *)message2,strlen(message2));
      Radio.waitPacketSent();
    }
  }
  while(digitalRead(button2) == 0);

  
  delay(50);

}
