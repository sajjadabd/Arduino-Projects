int led1 = 3;
int led2 = 5;
int led3 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void makeOFF()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1,HIGH);
  delay(1000);
  makeOFF();
  
  digitalWrite(led2,HIGH);
  delay(1000);
  makeOFF();
  
  digitalWrite(led3,HIGH);
  delay(1000);
  makeOFF();

  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(1000);
  makeOFF();


  digitalWrite(led1,HIGH);
  digitalWrite(led3,HIGH);
  delay(1000);
  makeOFF();

  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  delay(1000);
  makeOFF();
  
  

}
