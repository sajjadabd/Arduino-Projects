#include <Servo.h>
Servo myservo;

int output = 9;
int y;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  myservo.attach(output);
  pinMode(output,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0);
  //Serial.println(x);
  y = map(x , 0 , 672, 0 , 255);
  //Serial.println(y);

  myservo.write(y);
  /*
  for(int i=0;i<255;i++)
  {
    myservo.write(i);
    delay(10);
  }

  for(int i=255;i>0;i--)
  {
    myservo.write(i);
    delay(10);
  }
  */
  
  
}
