/*  
 *  Controlling a RGB LED with a TV Remote
 *  
 *  Modified IRrecvDemo example from Ken Shirriff IRremote Library
 *  Ken Shirriff
 *  http://arcfn.com
 *  
 *  Modified by Dejan Nedelkovski,
 *  www.HowToMechatronics.com 
 *  
 */

#include <IRremote.h>

int led1 = 2;
int led2 = 3;
int led3 = 4;

boolean pos1 = false;
boolean pos2 = false;
boolean pos3 = false;
boolean pos4 = false;

int RECV_PIN = 8; // IR Receiver - Arduino Pin Number 8

IRrecv irrecv(RECV_PIN);

decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void setOff()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
 
void loop() {
  
  if (irrecv.decode(&results)) {   

    Serial.println(results.value);
    
    if(results.value == 551489775)//Turn On And Off
    {
      setOff();
    }
    else if( results.value == 551520375 )// Number 1
    {
      setOff();
      digitalWrite(led1,HIGH);

    }
    else if( results.value == 551504055 )// Number 2
    {
      setOff();
      digitalWrite(led2,HIGH);
    }
    else if( results.value == 551536695 )// Number 3
    {
      setOff();
      digitalWrite(led3,HIGH);
    }


    
    
    irrecv.resume(); // Receive the next value
  
  }
  else
  {
    

  }
  //delay(100);
}

