int gnd1 = 2;
int gnd2 = 10;

int g = 3;
int f = 4;
int a = 5;
int b = 6;
int d = 7;
int e = 8;
int c = 9;


int dot = 11;

int counter = 0;

int timer1_counter ;

void setup() {
  // put your setup code here, to run once:
  pinMode ( a , OUTPUT );
  pinMode ( b , OUTPUT );
  pinMode ( c , OUTPUT );
  pinMode ( d , OUTPUT );
  pinMode ( e , OUTPUT );
  pinMode ( f , OUTPUT );
  pinMode ( g , OUTPUT );

  pinMode ( gnd1 , OUTPUT );
  pinMode ( gnd2 , OUTPUT );

  pinMode ( dot , OUTPUT );

  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  //timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
  timer1_counter = 34286;
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
}

ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
  counter++;
  //digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
}

void allOFF()
{
  digitalWrite( a , LOW );
  digitalWrite( f , LOW );
  digitalWrite( g , LOW );
  digitalWrite( c , LOW );
  digitalWrite( d , LOW );
  digitalWrite( e , LOW );
  digitalWrite( b , LOW );
}


void one()
{
  digitalWrite( b , HIGH );
  digitalWrite( c , HIGH );
}

void two()
{
  digitalWrite( a , HIGH );
  digitalWrite( b , HIGH );
  digitalWrite( g , HIGH );
  digitalWrite( e , HIGH );
  digitalWrite( d , HIGH );
}

void three()
{
  digitalWrite( a , HIGH );
  digitalWrite( b , HIGH );
  digitalWrite( g , HIGH );
  digitalWrite( c , HIGH );
  digitalWrite( d , HIGH );
}

void four()
{
  digitalWrite( f , HIGH );
  digitalWrite( g , HIGH );
  digitalWrite( b , HIGH );
  digitalWrite( c , HIGH );
}

void five()
{
  digitalWrite( a , HIGH );
  digitalWrite( f , HIGH );
  digitalWrite( g , HIGH );
  digitalWrite( c , HIGH );
  digitalWrite( d , HIGH );
}

void six()
{
  digitalWrite( a , HIGH );
  digitalWrite( f , HIGH );
  digitalWrite( g , HIGH );
  digitalWrite( c , HIGH );
  digitalWrite( d , HIGH );
  digitalWrite( e , HIGH );
}

void seven ()
{
  digitalWrite( a , HIGH );
  digitalWrite( b , HIGH );
  digitalWrite( c , HIGH );
}

void eight()
{
  digitalWrite( a , HIGH );
  digitalWrite( f , HIGH );
  digitalWrite( g , HIGH );
  digitalWrite( c , HIGH );
  digitalWrite( d , HIGH );
  digitalWrite( e , HIGH );
  digitalWrite( b , HIGH );
}

void nine()
{
  digitalWrite( a , HIGH );
  digitalWrite( f , HIGH );
  digitalWrite( g , HIGH );
  digitalWrite( c , HIGH );
  digitalWrite( d , HIGH );
  digitalWrite( b , HIGH );
}

void zero()
{
  digitalWrite( a , HIGH );
  digitalWrite( f , HIGH );
  digitalWrite( e , HIGH );
  digitalWrite( c , HIGH );
  digitalWrite( d , HIGH );
  digitalWrite( b , HIGH );
}

void tools()
{
  delay(500);
  allOFF();
  digitalWrite(gnd1 , HIGH);
  digitalWrite(gnd2, HIGH);
}



void loop() {

  for(int i=0;i<100;i++)
  {
    allOFF();
  
    digitalWrite(gnd1 , LOW);
    digitalWrite(gnd2, HIGH);
    switch(counter/10)
    {
      case 0:
        zero();
        break;
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
      case 9:
        nine();
        break;
    }
    delay(1);
    
    allOFF();
  
    digitalWrite(gnd1 , HIGH);
    digitalWrite(gnd2, LOW);
    switch(counter%10)
    {
      case 0:
        zero();
        break;
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
      case 9:
        nine();
        break;
    }
    delay(1);
  }
  


  /*
  counter++;
  
  digitalWrite(gnd1 , HIGH);
  digitalWrite(gnd2, HIGH);
  delay(5);
  */

  if ( counter >= 100 )
  {
    counter = 0;
  }

  

}
