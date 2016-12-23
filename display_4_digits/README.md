#USED FOR DISPLAYING NUMBERS ON 4 DIGITS DISPLAY  
  
A digit can have 7 lines. Lines (A-G)  
  -       A  
 | |     F B  
  -       G  
 | |     E C  
  -       D  
  
For the 4 digit display:  
PIN LAYOUT:   
    12 11 10 9  8  7  
    1  2  3  4  5  6  
  
FUNCTIONALITY  | DISPLAY PIN | ARDUINO PIN  
------------------------------------------  
LINE A         | 11          | 13  
LINE B         | 7           | 12  
LINE C         | 4           | 11  
LINE D         | 2           | 10  
LINE E         | 1           | 9  
LINE F         | 10          | 8  
LINE G         | 5           | 7  
DOT            | 3           | NOT USED IN THIS EXAMPLE  
  
To choose the digit, we need have to wire the ground to one of the following pins:  
* DIGIT 1: DISPLAY PIN 12  
* DIGIT 2: DISPLAY PIN 9  
* DIGIT 3: DISPLAY PIN 8  
* DIGIT 4: DISPLAY PIN 6  
 *  
 * Now, to display multiple digits at once, you need to reliy on a trick: 
 * you display digit 1 for 1ms, digit 2 for 1 ms, and so on...
 * the human eye will be tricked and think that all the digits are active at once. 
 * 
 * To turn on/off the digits, we will use some NPN transistors: 
 * NPN COLLECTOR  | NPN BASE      | NPN EMITTER                     | DIGIT (LEFT TO RIGHT)
 * ----------------------------------------------------------------------------------------
 * ARDUINO GROUND | ARDUINO PIN 7 | DISPLAY PIN 12                  | 1
 * ARDUINO GROUND | ARDUINO PIN 6 | DISPLAY PIN 9                   | 2
 * ARDUINO GROUND | ARDUINO PIN 5 | DISPLAY PIN 8                   | 3
 * NOT USED IN THIS EXAMPLE: 
 * ARDUINO GROUND | ARDUINO PIN 4 | CAN BE PLUGGED ON DISPLAY PIN 6 | 4
 *  
 *  
 */
