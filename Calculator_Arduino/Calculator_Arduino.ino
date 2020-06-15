/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'=','0','C','/'}
};
byte rowPins[ROWS] = {A5, A4, A3, A2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A1, A0, 6, 7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


int firstNumber = 0;
int secondNumber = 0;

int result = 0;

char operation = ' ';

bool firstOrSecond = true;

int number = 0;

bool end = false;

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}

int checkNumber(char x)
{
    int pressNumber ;
    lcd.print(x);
    switch(x)
    {
      case '1':
        pressNumber = 1;
        break;
      case '2':
        pressNumber = 2;
        break;
      case '3':
        pressNumber = 3;
        break;
      case '4':
        pressNumber = 4;
        break;
      case '5':
        pressNumber = 5;
        break;
      case '6':
        pressNumber = 6;
        break;
      case '7':
        pressNumber = 7;
        break;
      case '8':
        pressNumber = 8;
        break;
      case '9':
        pressNumber = 9;
        break;
      case '0':
        pressNumber = 0;
        break; 
    }  

  return pressNumber;
}

void reset()
{
  end = false;
  firstOrSecond = true;
  firstNumber = 0;
  secondNumber = 0;
  result = 0;
  operation = ' ' ;
  lcd.clear();
}

int calc(int firstNumber , int secondNumber,char operation)
{
  int result = 0;
  switch(operation)
  {
    case '+':
      result = firstNumber + secondNumber;
      break;
    case '-':
      result = firstNumber - secondNumber;
      break;
    case '*':
      result = firstNumber * secondNumber;
      break;
    case '/':
      result = firstNumber / secondNumber;
      break;
  }

  return result ;
}

void loop() {

  char key = keypad.getKey();
  
  if (key){

    //pressNumber = String(key).toInt();

    if( key == '=' )
    {
      end = true;
      firstOrSecond = true;
      lcd.print("=");
      switch(operation)
      {
        case '+':
          result = firstNumber + secondNumber;
          break;
        case '-':
          result = firstNumber - secondNumber;
          break;
        case '*':
          result = firstNumber * secondNumber;
          break;
        case '/':
          result = firstNumber / secondNumber;
          break;
      }
      lcd.print(result);
    }
    else if( key == 'C' )
    {
      reset();
    }
    else if( key == '+' || key == '-' || key == '*' || key == '/')
    {
      if( end == true )
      {
        lcd.clear();
        end = false;
        firstNumber = result ;
        lcd.print(firstNumber);
        secondNumber = 0;
        firstOrSecond = false;
        switch(key)
        {
          case '+':
          operation = '+';
          lcd.print(operation);
          break;
          case '-':
          operation = '-';
          lcd.print(operation);
          break;
          case '*':
          operation = '*';
          lcd.print(operation);
          break;
          case '/':
          operation = '/';
          lcd.print(operation);
          break;
        }
      }
      else if( operation == ' ' )
      {
        firstOrSecond = false;
        switch(key)
        {
          case '+':
          operation = '+';
          lcd.print(operation);
          break;
          case '-':
          operation = '-';
          lcd.print(operation);
          break;
          case '*':
          operation = '*';
          lcd.print(operation);
          break;
          case '/':
          operation = '/';
          lcd.print(operation);
          break;
        }
      }
      else
      {
        if ( firstNumber != 0 && secondNumber != 0 )
        {
          lcd.clear();
          int res = calc(firstNumber,secondNumber,operation);
          lcd.print(res);
          firstNumber = res;
          secondNumber = 0;
          firstOrSecond = false;
          switch(key)
          {
            case '+':
            operation = '+';
            lcd.print(operation);
            break;
            case '-':
            operation = '-';
            lcd.print(operation);
            break;
            case '*':
            operation = '*';
            lcd.print(operation);
            break;
            case '/':
            operation = '/';
            lcd.print(operation);
            break;
          }
        }
      }
      
    }
    else
    {
      if( end == true )
      {
        reset();
      }
      
      number = checkNumber(key);
      
      if( firstOrSecond == true )
      {
        firstNumber = ( firstNumber * 10 ) + number;
      }
      else if( firstOrSecond == false )
      {
        secondNumber = ( secondNumber * 10 ) + number;
      }
    }



    Serial.print("pressNumber : ");
    Serial.println(number);
    Serial.print("operation : ");
    Serial.println(operation);
    Serial.print("firstNumber : ");
    Serial.println(firstNumber);
    Serial.print("secondNumber : ");
    Serial.println(secondNumber);
    Serial.print("result : ");
    Serial.println(result);
    Serial.println("----------------------------");




    
  }

}

