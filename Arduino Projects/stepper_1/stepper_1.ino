int stepPin = 3;
int dirPin = 4;

int t = 5;

int counter = 0;

int x;
int y;

bool rotate = false;
bool off = true;

void setup() {
  pinMode ( stepPin , OUTPUT );
  pinMode ( dirPin , OUTPUT );
  Serial.begin(9600);
}

void loop() {
  x = analogRead(A0);
  Serial.println(x);

  counter++;
  
  if ( x < 100 )
  {
    rotate = true;
    off = false;
  }
  else if ( x > 1000 )
  {
    rotate = false;
    off = false;
  }
  else
  {
    off = true;
  }

  if ( off == false && rotate == true )
  {
    if ( counter % 2 == 0 )
    {
      digitalWrite ( dirPin , HIGH );
    }
    else
    {
      digitalWrite ( dirPin , LOW );
    }
    

    for ( int i = 0 ; i < 20 ; i ++ )
    {
      digitalWrite ( stepPin , HIGH );
      delayMicroseconds ( t );
      digitalWrite ( stepPin , LOW );
      delayMicroseconds ( t );
    }
  }
  else if ( off == false && rotate == false )
  {
    if ( counter % 2 == 0 )
    {
      digitalWrite ( dirPin , HIGH );
    }
    else
    {
      digitalWrite ( dirPin , LOW );
    }
    

    for ( int i = 0 ; i < 20 ; i ++ )
    {
      digitalWrite ( stepPin , LOW );
      delayMicroseconds ( t );
      digitalWrite ( stepPin , HIGH );
      delayMicroseconds ( t );
    }
  }
  else if ( off == true )
  {
    
  }
  
  
  

  delay ( 10 );

}
