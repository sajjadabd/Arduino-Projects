#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A0     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int h;
int t;

void setup() {
  //Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  //lcd.print("hello, world!");
}

void loop() {
    //Read data and store it to variables hum and temp
    h = dht.readHumidity();
    t = dht.readTemperature();
    //Print temp and humidity values to serial monitor


    //lcd.print("Humidity : ");
    lcd.print("Humid : ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0,1);
    lcd.print("Temp  : ");
    lcd.print(t);
    lcd.print(" *C");
    //lcd.print(" Celsius");

    
    //Serial.print("Humidity: ");
    //Serial.print(h);
    //Serial.print(" %, Temp: ");
    //Serial.print(t);
    //Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.
    lcd.clear();
}
