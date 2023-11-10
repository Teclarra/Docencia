// C++ code
//
void setup()
{
  pinMode(8, INPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
}

void loop()
{
  if (digitalRead(8) == 1) {
    tone(11, 262, 200); // play tone 48 (C4 = 262 Hz)
  }
  if (digitalRead(7) == 1) {
    tone(11, 294, 200); // play tone 50 (D4 = 294 Hz)
  }
  if (digitalRead(6) == 1) {
    tone(11, 330, 200); // play tone 52 (E4 = 330 Hz)
  }
  if (digitalRead(5) == 1) {
    tone(11, 349, 200); // play tone 53 (F4 = 349 Hz)
  }
  if (digitalRead(4) == 1) {
    tone(11, 392, 200); // play tone 55 (G4 = 392 Hz)
  }
  if (digitalRead(3) == 1) {
    tone(11, 440, 200); // play tone 57 (A4 = 440 Hz)
  }
  if (digitalRead(2) == 1) {
    tone(11, 494, 200); // play tone 59 (B4 = 494 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}
