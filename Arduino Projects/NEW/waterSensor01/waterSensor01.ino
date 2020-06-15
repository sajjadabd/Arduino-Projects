int led = 3;

int water = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  water = analogRead(A0);
  //Serial.println(water);
  water = map(water,0,660,0,100);
  if(water > 90 )
  {
    analogWrite(led,water);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  
  Serial.println(water);
  
}
