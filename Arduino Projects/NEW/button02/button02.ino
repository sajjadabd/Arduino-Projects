int led = 7;
int button = 4;

int x ;

bool t = false;

int counter = 0;

int Time1 = 50;

int Time2 = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  //Serial.println(x);
   
  if( digitalRead(button) == 0)
  {
    if( t == true )
        t = false;
    else if ( t == false ) 
        t = true;

    while( digitalRead(button) == 0)
    {
      
    }
  }

  
  delay(10);

  if( t == true)
  {
    digitalWrite(led,HIGH);

  }
  else
  {
    digitalWrite(led,LOW);

  }
  
}
