int led = 7;
int buzzer = 3;
int touch;

int s;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  touch = analogRead(A0);
  Serial.println(touch);
  s = map(touch,0,1014,0,255);

  if(touch > 400 )
  {
    digitalWrite(led,HIGH);
    analogWrite(buzzer,150);
  }
  else
  {
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
  }

}
