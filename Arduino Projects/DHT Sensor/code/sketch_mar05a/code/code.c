#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A0     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

float h;
float t;

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() {
    //Read data and store it to variables hum and temp
    h = dht.readHumidity();
    t = dht.readTemperature();
    //Print temp and humidity values to serial monitor

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %, Temp: ");
    Serial.print(t);
    Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.
}