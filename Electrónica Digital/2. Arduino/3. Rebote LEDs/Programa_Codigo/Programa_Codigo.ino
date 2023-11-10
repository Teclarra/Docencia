int i = 0;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop()
{
   for (i=2; i<12; ++i){
    digitalWrite(i, HIGH);
    delay(50);
  digitalWrite(i, LOW);
    delay(50);
   }
   for (i=11; i>1; --i){
    digitalWrite(i, HIGH);
    delay(50);
  digitalWrite(i, LOW);
    delay(50);}
}
