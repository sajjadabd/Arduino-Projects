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

int led1 = 13;
int led2 = 12;

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
}
 
void loop() {
  
  if (irrecv.decode(&results)) {   

    Serial.println(results.value);
    
    if(results.value == 551489775)//Turn On And Off
    {
      if(pos1 == false)
      {
        pos4 = false;
        digitalWrite(led2,LOW);
        digitalWrite(led1,LOW);
        //digitalWrite(led,HIGH);
        delay(100);
        pos1 = true;
      }
      else if(pos1 == true)
      {
        //digitalWrite(led,LOW);
        delay(100);
        pos1 = false;
      }
    }
    else if( results.value == 551520375 )// Number 1
    {
      if(pos2 == false)
      {
        digitalWrite(led1,HIGH);
        delay(100);
        pos2 = true;
      }
      else if(pos2 == true)
      {
        digitalWrite(led1,LOW);
        delay(100);
        pos2 = false;
      }
    }
    else if( results.value == 551504055 )// Number 2
    {
      if(pos3 == false)
      {
        digitalWrite(led2,HIGH);
        delay(100);
        pos3 = true;
      }
      else if(pos3 == true)
      {
        digitalWrite(led2,LOW);
        delay(100);
        pos3 = false;
      }
    }
    else if( results.value == 551536695 )// Number 3
    {
      if(pos4 == false)
      {
        //digitalWrite(led,HIGH);
        delay(100);
        pos4 = true;
      }
      else if(pos4 == true)
      {
        //digitalWrite(led,LOW);
        delay(100);
        pos4 = false;
      }
    }


    
    
    irrecv.resume(); // Receive the next value
  
  }
  else
  {
    if(pos4 == true)
    {
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      
      
      digitalWrite(led1 , HIGH);


      delay(500);

      digitalWrite(led2,HIGH);

      
      digitalWrite(led1,LOW);

      delay(500);

      digitalWrite(led2,LOW);

      delay(500);

    }
    //Serial.println("Nothing Found");
  }
  //delay(100);
}

