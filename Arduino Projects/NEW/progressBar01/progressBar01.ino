int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int h = 9;
int i = 10;
int j = 11;



int buzzer = 12;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  pinMode(i,OUTPUT);
  pinMode(j,OUTPUT);
  
  pinMode(buzzer,OUTPUT);
}

void setOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(h,LOW);
  digitalWrite(i,LOW);
  digitalWrite(j,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 if(counter == 0)
 {
  digitalWrite(a,HIGH);
 }
 else if(counter == 1)
 {
  digitalWrite(b,HIGH);
 }
 else if(counter == 2)
 {
  digitalWrite(c,HIGH);
 }
 else if(counter == 3)
 {
  digitalWrite(d,HIGH);
 }
 else if(counter == 4)
 {
  digitalWrite(e,HIGH);
 }
 else if(counter == 5)
 {
  digitalWrite(f,HIGH);
 }
 else if(counter == 6)
 {
  digitalWrite(g,HIGH);
   
 }
 else if(counter == 7)
 {
  digitalWrite(h,HIGH);
   
 }
 else if(counter == 8)
 {
  digitalWrite(i,HIGH);
   
 }
 else if(counter == 9)
 {
  digitalWrite(j,HIGH);
  counter = -1;
   digitalWrite(buzzer,HIGH);
   
 }
 
 delay(300);
 if(counter == -1)
 {
  setOff();
 }
 digitalWrite(buzzer,LOW);
 counter++;

 
 
}
