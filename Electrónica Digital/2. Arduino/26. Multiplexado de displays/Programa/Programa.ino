/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int DP = 9;
int E1=10;
int E2=11;
int E3=12;
int E4=13;
int t=10;



// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);
  pinMode(DP, OUTPUT);   
  pinMode(E1, OUTPUT);  
  pinMode(E2, OUTPUT);  
  pinMode(E3, OUTPUT);  
  pinMode(E4, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(E1, HIGH);
  digitalWrite(E2, LOW);
  digitalWrite(E3, LOW);
  digitalWrite(E4, LOW); 
  //0
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW); 
  digitalWrite(DP, HIGH);
  delay(t);               // wait for t miliseconds
  
  digitalWrite(E1, LOW);
  digitalWrite(E2, HIGH);
  digitalWrite(E3, LOW);
  digitalWrite(E4, LOW); 
  //1
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
  digitalWrite(DP, HIGH);
  delay(t);               // wait for t miliseconds
  
  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(E3, HIGH);
  digitalWrite(E4, LOW); 
  //2
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
  digitalWrite(DP, HIGH);
  delay(t);               // wait for t miliseconds

  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(E3, LOW);
  digitalWrite(E4, HIGH); 
  //3
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
  digitalWrite(DP, HIGH);
  delay(t);               // wait for t miliseconds
}
