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

int RECV_PIN = 8; // IR Receiver - Arduino Pin Number 8

IRrecv irrecv(RECV_PIN);

decode_results results;

int cols[] = { 2 , 3 , 4 , 5 };
int rows[] = { A5 , A4 , A3 , A2 };

int size = 4;

int x = 0;
int y = 0;

bool on = true;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  for(int i=0;i<size;i++)
  {
    pinMode( rows[i] , OUTPUT );
    pinMode( cols[i] , OUTPUT );
  }

  for(int i=0;i<size;i++)
  {
    digitalWrite( cols[i] , HIGH );
  }

  putPixel(x,y);
}

void putPixel(int x, int y)
{
  digitalWrite(rows[x] , HIGH );
  digitalWrite(cols[y] , LOW);
}

void offPixel(int x, int y)
{
  digitalWrite(rows[x] , LOW );
  digitalWrite(cols[y] , HIGH);
}
 
void loop() {

  
  
  if (irrecv.decode(&results)) {   

    offPixel(x,y);

    Serial.println(results.value);
    
    //551486205  up
    //551518845 down
    //551510175 right
    //551542815 left

    if(results.value == 551486205)//up
    {
      if(x > 0)
        x--;
    }
    else if( results.value == 551518845 )//  down
    {
      if(x < 3)
        x++;
    }
    else if( results.value == 551510175 )// right
    {
      if(y < 3)
        y++;
    }
    else if( results.value == 551542815 )// left
    {
      if(y > 0)
        y--;
    }
    else if(results.value == 551489775)//Turn Off And On
    {
      on = !on;
    }

    if( on == true )
      putPixel(x,y);
    
    
    irrecv.resume(); // Receive the next value
  
  }
  else
  {

    //Serial.println("Nothing Found");
  }
  //delay(100);
}

