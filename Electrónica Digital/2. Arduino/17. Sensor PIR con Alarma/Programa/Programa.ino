#define BUZZ 11 
#define PIR 3
boolean val;

void setup (){
  pinMode (BUZZ, OUTPUT);
  pinMode (PIR, INPUT);
  Serial.begin(9600);
}
void loop (){
val = digitalRead(PIR);
  if (val == HIGH){ 
  
  tone (BUZZ, 1174.66);
  delay(500);
  
  tone (BUZZ, 783.99);
  delay(500);
    
  tone (BUZZ, 987.767); //Que nota es (tabla 987=Si5)
  delay(1000);          //Duracion 1 segundo

    
    noTone(BUZZ);}
else noTone(BUZZ);
Serial.println(val);
}
