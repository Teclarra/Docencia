int rele = 10;

void setup(){
 pinMode(rele, OUTPUT);

}

void loop(){
 digitalWrite(rele, HIGH);
 delay(500);
 digitalWrite(rele, LOW);
 delay(500);


}
