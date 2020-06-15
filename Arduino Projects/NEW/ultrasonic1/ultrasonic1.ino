//int x;
const int trig = 9;
const int echo = 10;

long duration;
int distance;

int led = 3;



void setup() {
  // put your setup code here, to run once:
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);

  pinMode(led,OUTPUT);
}


void check()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);
  duration = pulseIn(echo , HIGH);

  distance = duration * 0.043 / 2;
}

void loop() {
  // put your main code here, to run repeatedly:
  //x = analogRead(A0);
  

  check();

  //Serial.print("Distance : " );
  //Serial.println(distance);

  if(distance < 10)
  {
     for(int i=0;i<255&&distance < 10;i++)
     {
        analogWrite(led, i);
        delay(40);
        check();
     }
  }
  else
  {
    digitalWrite(led, LOW);
  }
  
  

  //Serial.println(x);
}
