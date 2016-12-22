/*
 * Playing with DHT11 temperature & humidity sensors (3 & 4 pin versions)
 * 
 * Looking from the front (grill part) of the sensor, from left to right:
 *  For the 3 pins:
 *    data, vcc 5v, ground
 *  For the 4 pins:
 *    vcc 5v, data, nothing, ground
 *  No resistance was used.    
 * 
 *  In this example I use both types of sensors (with 3 and 4 pins)
 *  The first one (4 pins) it's connected to pin 7 on arduino
 *  The second one (3 pins) it's connected to pin 8
 *  
 */

#include <dht.h>

dht DHT1;
dht DHT2;

#define DHT1_PIN 7
#define DHT2_PIN 8

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk1 = DHT1.read11(DHT1_PIN);
  int chk2 = DHT2.read11(DHT2_PIN);

  Serial.print("Temperature 1 = ");
  Serial.println(DHT1.temperature);
  Serial.print("Humidity 1 = ");
  Serial.println(DHT1.humidity);
  Serial.print("Temperature 2 = ");
  Serial.println(DHT2.temperature);
  Serial.print("Humidity 2 = ");
  Serial.println(DHT2.humidity);
  Serial.println("-------------------");
  
  delay(1000);
}
