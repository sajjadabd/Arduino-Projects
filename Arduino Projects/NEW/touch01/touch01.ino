#include<Servo.h>

Servo myServo;

int led = 7;
int servo = 3;
int touch;

int s;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(servo,OUTPUT);

  myServo.attach(servo);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  touch = analogRead(A0);
  Serial.println(touch);
  s = map(touch,0,1014,0,255);

  if(touch > 500 )
  {
    digitalWrite(led,HIGH);
    
  }
  else
  {
    digitalWrite(led,LOW);
    
  }

  myServo.write(s);
}
