#include <dht.h>
#define dataPin A0 // Defines pin number to which the sensor is connected

dht DHT; // Creats a DHT object

void setup() {
  Serial.begin(9600);
}

void loop() {
  //int readData = DHT.read11(dataPin); // Reads the data from the sensor
  DHT.read11(dataPin); // Reads the data from the sensor
  float t = DHT.temperature; // Gets the values of the temperature
  float h = DHT.humidity; // Gets the values of the humidity
  
  // Printing the results on the serial monitor
  //Serial.print("read Data : ");
  //Serial.println(readData);
  
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.print("%");
  Serial.print("       Temperature = ");
  Serial.print(t);
  Serial.println(" *C");
  
  
  delay(2000); // Delays 2 secods, as the DHT22 sampling rate is 0.5Hz
}