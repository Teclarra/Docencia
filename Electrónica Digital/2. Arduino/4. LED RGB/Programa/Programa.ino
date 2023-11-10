// C++ code
//
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  analogWrite(9, 255);
  analogWrite(10, 255);
  analogWrite(11, 255);
  delay(10); // Delay a little bit to improve simulation performance
}
