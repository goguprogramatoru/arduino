/**
 * USED FOR DISPLAYING NUMBERS ON 4 DIGITS DISPLAY
 * 
 * A digit can have 7 lines. Lines (A-G)
 *  -       A
 * | |     F B
 *  -       G
 * | |     E C
 *  -       D
 * 
 * For the 4 digit display: 
 * PIN LAYOUT: 
 *    12 11 10 9  8  7 
 *    1  2  3  4  5  6
 * 
 * FUNCTIONALITY  | DISPLAY PIN | ARDUINO PIN
 * ------------------------------------------
 * LINE A         | 11          | 13
 * LINE B         | 7           | 12
 * LINE C         | 4           | 11
 * LINE D         | 2           | 10 
 * LINE E         | 1           | 9
 * LINE F         | 10          | 8
 * LINE G         | 5           | 7
 * DOT            | 3           | NOT USED IN THIS EXAMPLE
 * 
 * To choose the digit, we need have to wire the ground to one of the following pins: 
 *  DIGIT 1: DISPLAY PIN 12
 *  DIGIT 2: DISPLAY PIN 9
 *  DIGIT 3: DISPLAY PIN 8 
 *  DIGIT 4: DISPLAY PIN 6
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


const int PART_A = 13;
const int PART_B = 12; 
const int PART_C = 11; 
const int PART_D = 10; 
const int PART_E = 9; 
const int PART_F = 8;
const int PART_G = 7;
const int DIGIT_1 = 6; 
const int DIGIT_2 = 5; 
const int DIGIT_3 = 4; 
const int ALL_PINS[] = {PART_A, PART_B, PART_C, PART_D, PART_E, PART_F, PART_G, DIGIT_1, DIGIT_2, DIGIT_3}; 

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<7; i++){
    pinMode(ALL_PINS[i], OUTPUT); 
  }
}

void loop() {
  for(int i=999; i>=0; i--){
    draw3DigitNumber(i,1000);
  }
}

void draw3DigitNumber(int number, int delayTime){
  int correctedDelayTime = delayTime / 3; 
  int hundreds = number/100;
  number = number-hundreds*100;
  int tens = number/10;
  int ones = number-tens*10;
  
  draw3DigitNumber(hundreds, tens, ones, correctedDelayTime);
  
}

void draw3DigitNumber(int digit1, int digit2, int digit3, int times){
  for(int i=0; i<times; i++){
    drawDigit(DIGIT_1, digit1);
    delay(1);
    drawDigit(DIGIT_2, digit2);
    delay(1);
    drawDigit(DIGIT_3, digit3);
    delay(1);
  }
    
  
}

void drawDigit(int digit, int nb){

  switch(digit){
    case DIGIT_1: 
      digitalWrite(DIGIT_1,HIGH); 
      digitalWrite(DIGIT_2,LOW); 
      digitalWrite(DIGIT_3,LOW); 
      break; 
    case DIGIT_2: 
      digitalWrite(DIGIT_1,LOW); 
      digitalWrite(DIGIT_2,HIGH); 
      digitalWrite(DIGIT_3,LOW); 
      break; 
    case DIGIT_3: 
      digitalWrite(DIGIT_1,LOW); 
      digitalWrite(DIGIT_2,LOW); 
      digitalWrite(DIGIT_3,HIGH); 
      break; 
  }
  
  switch(nb){
    case 0: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, HIGH);
      digitalWrite(PART_E, HIGH);
      digitalWrite(PART_F, HIGH);
      digitalWrite(PART_G, LOW);
      break;
    case 1: 
      digitalWrite(PART_A, LOW);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, LOW);
      digitalWrite(PART_E, LOW);
      digitalWrite(PART_F, LOW);
      digitalWrite(PART_G, LOW);
      break;
    case 2: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, LOW);
      digitalWrite(PART_D, HIGH);
      digitalWrite(PART_E, HIGH);
      digitalWrite(PART_F, LOW);  
      digitalWrite(PART_G, HIGH);
      break;
    case 3: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, HIGH);
      digitalWrite(PART_E, LOW);
      digitalWrite(PART_F, LOW);  
      digitalWrite(PART_G, HIGH);
      break;
    case 4: 
      digitalWrite(PART_A, LOW);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, LOW);
      digitalWrite(PART_E, LOW);
      digitalWrite(PART_F, HIGH);
      digitalWrite(PART_G, HIGH);    
      break;
    case 5: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, LOW);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, HIGH);
      digitalWrite(PART_E, LOW);
      digitalWrite(PART_F, HIGH);
      digitalWrite(PART_G, HIGH);    
      break;
    case 6: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, LOW);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, HIGH);
      digitalWrite(PART_E, HIGH);
      digitalWrite(PART_F, HIGH);
      digitalWrite(PART_G, HIGH);    
      break;
    case 7: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, LOW);
      digitalWrite(PART_E, LOW);
      digitalWrite(PART_F, LOW);
      digitalWrite(PART_G, LOW);    
      break;  
    case 8: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, HIGH);
      digitalWrite(PART_E, HIGH);
      digitalWrite(PART_F, HIGH);
      digitalWrite(PART_G, HIGH);    
      break;
    case 9: 
      digitalWrite(PART_A, HIGH);
      digitalWrite(PART_B, HIGH);
      digitalWrite(PART_C, HIGH);
      digitalWrite(PART_D, LOW);
      digitalWrite(PART_E, LOW);
      digitalWrite(PART_F, HIGH);
      digitalWrite(PART_G, HIGH);    
      break;  
  }
  
}
