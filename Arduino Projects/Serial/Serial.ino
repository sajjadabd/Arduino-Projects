String str;
//String pass = "1";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}
/*
boolean equals1(String text1,String text2)
{
  if(text1.length() != text2.length())
    return false;

  for(int i=0;i<text1.length();i++)
  {
    if(text1.charAt(i) != text2.charAt(i))
    {
        return false;
    }
  }
  return true;
}
*/

void loop() {
  char text[] = "Hello";
  // put your main code here, to run repeatedly:
 
  str = text;
  delay(1000);
  Serial.println(text);
  Serial.println(str);
    

  
}
