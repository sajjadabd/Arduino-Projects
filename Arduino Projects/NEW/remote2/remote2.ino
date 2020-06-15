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
#include <Servo.h>

Servo myservo;

int led1 = 7;
int led2 = 12;
int led3 = 9;

int led4 = 10;
int led5 = 8;

int servo = 3;

boolean pos1 = false;
boolean pos2 = false;
boolean pos3 = false;
boolean pos4 = false;

int RECV_PIN = 11; // IR Receiver - Arduino Pin Number 8

IRrecv irrecv(RECV_PIN);

decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(servo,OUTPUT);

  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);

  
  myservo.attach(servo);

  digitalWrite(led1,HIGH);
  delay(1000);
  digitalWrite(led1,LOW);
}
 
void loop() {
  //Serial.println("Hello");

  
  
  if (irrecv.decode(&results)) {   

    Serial.println(results.value);
    
    if(results.value == 551489775)//Turn On And Off
    {
      if(pos1 == false)
      {
        
      }
      else if(pos1 == true)
      {
        
      }
    }
    else if( results.value == 551520375 )// Number 1
    {
      
    }
    else if( results.value == 551504055 )// Number 2
    {
      
    }
    else if( results.value == 551536695 )// Number 3
    {
      
    }


    
    
    irrecv.resume(); // Receive the next value
  
  }
  else
  {
    

    
    //Serial.println("Nothing Found");
  }
  //delay(100);
}

