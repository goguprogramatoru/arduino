#Playing with DHT11 temperature & humidity sensors (3 & 4 pin versions)  
Looking from the front (grill part) of the sensor, from left to right:  
* For the 3 pins:  
 * data, vcc 5v, ground  
* For the 4 pins:  
 * vcc 5v, data, nothing, ground  

No resistance was used.  
In this example I use both types of sensors (with 3 and 4 pins)  
The first one (4 pins) it's connected to pin 7 on arduino  
The second one (3 pins) it's connected to pin 8  

Libs used: DHTLib https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib

![alt tag](https://github.com/goguprogramatoru/arduino/blob/master/DHT11_humidity_temperature/pics/schema.jpg)

![alt tag](https://github.com/goguprogramatoru/arduino/blob/master/DHT11_humidity_temperature/pics/sensors.jpg)

##Other notes:  
The sensors show the same temperature, but the humidity values are different (big diff).  
I'm gonna order some DHT22 and see how they compare.
