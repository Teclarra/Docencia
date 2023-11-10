#define pinLED 11

int v=0;
int pwm=0;

void setup() {

  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  v = analogRead(A0);
  
  pwm=map(v,1,310,255,0);
  
  analogWrite(pinLED, pwm);
  
  Serial.print("v=");
  Serial.print(v);
  Serial.print(" pwm=");
  Serial.println(pwm);
}
