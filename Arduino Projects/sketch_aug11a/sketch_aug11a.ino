int counter  = 4;
int x ;
int y ;
void setup() {
  pinMode ( 4 , OUTPUT );
  pinMode ( 5 , OUTPUT );
  pinMode ( 6 , OUTPUT );
  pinMode ( 7 , OUTPUT );
  pinMode ( 8 , OUTPUT );
  pinMode ( 9 , OUTPUT );
  pinMode ( 10 , OUTPUT );
  pinMode ( 11 , OUTPUT );
  pinMode ( 12 , OUTPUT );
  pinMode ( 13 , OUTPUT );

  digitalWrite( counter , HIGH );
}

void loop() {
  x = analogRead(A1);

  if ( x > 1000 )
  {
     counter++;
     delay(100);
  }
  else if ( x < 30 )
  {
     counter--;
     delay(100);
  }

  if ( counter > 13 )
  {
    counter = 13;
  }

  if ( counter < 4 )
  {
    counter = 4;
  }

  digitalWrite( counter - 1 , LOW );
  digitalWrite( counter , HIGH);
  digitalWrite( counter + 1 , LOW );
}
