int led1 = 3;//Blue
int led2 = 5;//Green
int led3 = 6;//Red
int counter = 0;

int Time = 10;

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

void Color(int a,int b ,int c)
{
   analogWrite(led1,a);
   analogWrite(led2,b);
   analogWrite(led3,c);
}

void loop() {
  // put your main code here, to run repeatedly:
    counter++;
    
    
    //
    for(int i=0;i<255;i++)
    {
      Color(i,0,0);
      delay(Time);
    }
       
   
    makeOFF();

    
    for(int i=0;i<255;i++)
    {
      Color(0,i,0);
      delay(Time);
    }

    makeOFF();
    
    for(int i=0;i<255;i++)
    {
      Color(0,0,i);
      delay(Time);
    }
    
    if(counter > 255)
       counter = 0;
  
  

  

}
