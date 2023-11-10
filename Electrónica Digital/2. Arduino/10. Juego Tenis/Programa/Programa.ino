int i = 0;
int bandera=0;
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
    
  for (i=3; i<=11; ++i){
    digitalWrite(i, HIGH);
    delay(50);
  digitalWrite(i, LOW);
    delay(50);}
}
void loop()
{
  if(!digitalRead(1)&& bandera==0){
    bandera=1;
    for (i=10; i>=2; --i){
    digitalWrite(i, HIGH);
    delay(50);
  digitalWrite(i, LOW);
    delay(50);}}
  
  if(!digitalRead(12) && bandera==1){
    bandera=0;
    for (i=3; i<=11; ++i){
    digitalWrite(i, HIGH);
    delay(50);
  digitalWrite(i, LOW);
    delay(50);}}
}
