#include <RH_ASK.h>
#include <SPI.h>

RH_ASK Radio(2000,2);

int led = 12;

bool on = false;

String text = "";

void setup()
{
  pinMode(led,OUTPUT);
  
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
    text = "";
    
    for(int i=0;i<buflen;i++)
    {
      text.concat((char)buf[i]);
    }
    
    Serial.println(text);
    /*
    if(text.equals("ONN"))
    {
      on = true;
    }
    else if(text.equals("OFF"))
    {
      on = false;
    }

    if(on == true)
    {
      digitalWrite(led,HIGH);
    }
    else if(on == false)
    {
      digitalWrite(led,LOW);
    }
    delay(15);
    */
  }
  
}
