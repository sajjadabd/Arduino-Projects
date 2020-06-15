int R1 = 2;
int C4 = 3;
int C6 = 4;
int R4 = 5;
int C1 = 6;
int R2 = 7;
int C7 = 8;
int C8 = 9;

int R3 = 12;//12
int R6 = 11;//11
int C5 = A0;//A0
int R8 = A1;//A1
int C3 = A2;//A2
int C2 = A3;//A3
int R7 = A4;//A4
int R5 = A5;//A5

int ROW[] = {R1,R2,R3,R4,R5,R6,R7,R8};
int COL[] = {C1,C2,C3,C4,C5,C6,C7,C8};

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(R1 , OUTPUT);
  pinMode(R2 , OUTPUT);
  pinMode(R3 , OUTPUT);
  pinMode(R4 , OUTPUT);
  pinMode(R5 , OUTPUT);
  pinMode(R6 , OUTPUT);
  pinMode(R7 , OUTPUT);
  pinMode(R8 , OUTPUT);

  pinMode(C1 , OUTPUT);
  pinMode(C2 , OUTPUT);
  pinMode(C3 , OUTPUT);
  pinMode(C4 , OUTPUT);
  pinMode(C5 , OUTPUT);
  pinMode(C6 , OUTPUT);
  pinMode(C7 , OUTPUT);
  pinMode(C8 , OUTPUT);

  COL_LOW();
}

void COL_LOW()
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(COL[i],LOW);
  }
}

void COL_HIGH()
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(COL[i],HIGH);
  }
}

void ROW_LOW()
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(ROW[i],LOW);
  }
}

void first()
{
  COL_LOW();
  for(int i=0;i<8;i++)
  {
    digitalWrite(ROW[i], HIGH);
    //digitalWrite(COL[7-i], HIGH);
    delay(200);
  }

  for(int i=0;i<8;i++)
  {
    digitalWrite(ROW[i], LOW);
    //digitalWrite(COL[i], LOW);
    delay(200);
  }


  COL_HIGH();
}

void second()
{
  COL_HIGH();
  for(int i=0;i<8;i++)
  {
    if( i %2 == 0)
    {
      for(int j=0;j<8;j++)
      {
        digitalWrite(ROW[j],HIGH);
        digitalWrite(COL[i],LOW);
  
        delay(100);
  
        
      }
    }
    else
    {
      for(int j=0;j<8;j++)
      {
        digitalWrite(ROW[7-j],HIGH);
        digitalWrite(COL[i],LOW);
  
        delay(100);
  
        
      }
    }
    
    COL_HIGH();
    ROW_LOW();
  }
}

void printIJ(int i,int j)
{
  Serial.print("i : ");
  Serial.print(i);
  Serial.print("   j : ");
  Serial.println(j);
}

void third()
{
  COL_HIGH();
  
  for(int i=0;i<8;i++)
  {
    if( i%2 == 0 )
    {
      for(int j=0;j<8;j++)
      {
        digitalWrite(ROW[j],HIGH);
        digitalWrite(COL[i],LOW);

        //printIJ(i,j);
  
        delay(100);
  
        COL_HIGH();
        ROW_LOW();
      }
    }
    else
    {
      for(int j=0;j<8;j++)
      {
        digitalWrite(ROW[7-j],HIGH);
        digitalWrite(COL[i],LOW);

        //printIJ(i,j);
        
        delay(100);
  
        COL_HIGH();
        ROW_LOW();
      }
    }    
  }
}

void fourth()
{
  COL_HIGH();
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      digitalWrite(ROW[j],HIGH);
      digitalWrite(COL[7-i],LOW);

      delay(100);

      COL_HIGH();
      ROW_LOW();
    }
  }
}

void fifth()
{
  COL_HIGH();

  for(int j=0;j<8;j++)
  {
    digitalWrite(ROW[j],HIGH);
    digitalWrite(COL[7-j],LOW);

    delay(100);

    COL_HIGH();
    ROW_LOW();
  }

  for(int j=0;j<8;j++)
  {
    digitalWrite(ROW[7-j],HIGH);
    digitalWrite(COL[7-j],LOW);

    delay(100);

    COL_HIGH();
    ROW_LOW();
  }
  
}


void sixth()
{
  COL_HIGH();

  for(int j=0;j<8;j++)
  {
    digitalWrite(ROW[j],HIGH);
    digitalWrite(COL[7],LOW);

    delay(100);

    COL_HIGH();
    ROW_LOW();
  }

  for(int j=0;j<8;j++)
  {
    digitalWrite(ROW[7],HIGH);
    digitalWrite(COL[7-j],LOW);

    delay(100);

    COL_HIGH();
    ROW_LOW();
  }

  for(int j=0;j<8;j++)
  {
    digitalWrite(ROW[7-j],HIGH);
    digitalWrite(COL[0],LOW);

    delay(100);

    COL_HIGH();
    ROW_LOW();
  }



  for(int j=0;j<8;j++)
  {
    digitalWrite(ROW[0],HIGH);
    digitalWrite(COL[j],LOW);

    delay(100);

    COL_HIGH();
    ROW_LOW();
  }


}




void loop() {

  first();

  second();

  third();

  fourth();

  fifth();

  sixth();


}
