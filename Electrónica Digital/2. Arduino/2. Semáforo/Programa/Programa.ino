// C++ code
//
int counter;

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(9, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(9, LOW);
  delay(500); // Wait for 500 millisecond(s)
  for (counter = 0; counter < 3; ++counter) {
    digitalWrite(10, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(10, LOW);
    delay(500); // Wait for 500 millisecond(s)
  }
  digitalWrite(11, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(500); // Wait for 500 millisecond(s)
}
