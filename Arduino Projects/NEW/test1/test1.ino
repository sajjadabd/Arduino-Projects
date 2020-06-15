int led1 = 5;
int led2 = 6;
int led3 = 3;
int input = 2;      
int button;
int button2;
int button3;

int input1 = 8;
int input2 = 9;

int bounce = 0;
int bounce1 = 0;
int bounce2 = 0;

int counter = 0;

int analog = 220;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(input,INPUT_PULLUP);
  pinMode(input1,INPUT_PULLUP);
  pinMode(input2,INPUT_PULLUP);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(led1,LOW);
  //digitalWrite(led2,LOW);
  //digitalWrite(led3,LOW);
  //Serial.println(digitalRead(input));

  button = digitalRead(input);
  button2 = digitalRead(input1);
  button3 = digitalRead(input2);
/*
  if(bounce1 >= 10)
    {
      analog+=30;

      bounce1 = 0;
    }

    if(bounce2 >= 10)
    {
      analog-=30;

      bounce2 = 0;
    }
    */

  if ( button2 == LOW)
  {
    analog = 220;
  }

  if(button3 == LOW)
  {
    analog = 10;
  }
  
  if( button == LOW  )
  {
    
    bounce++;

    if( bounce > 10 )
      bounce = 10;

    
  }
  else
  {
    
    
    if ( bounce >= 10 )
    {
      counter++;

      if(counter > 1)
      {
        counter = 0;
      }

      bounce = 0;
    }
    
    if ( counter == 0)
    {
      first();
    }
    else if (counter == 1)
    {
      second();
    }
    else if (counter == 2)
    {
      third();

      
    }
  }

  //delay(90);
}

void first()
{
  analogWrite(led1, analog);
  delay(100);
  digitalWrite(led1,LOW);
  delay(100);
}

void second()
{
  analogWrite(led2, analog);
  delay(100);
  digitalWrite(led2,LOW);
  //delay(100);
}

void third()
{
  digitalWrite(led3, OUTPUT);
  delay(100);
  digitalWrite(led3,LOW);
  delay(100);
}


