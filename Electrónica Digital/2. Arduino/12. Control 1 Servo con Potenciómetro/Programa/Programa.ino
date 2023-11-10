#include <Servo.h> //Incluimos la librería Servo

Servo MiServo;  //Definimos el servo que vamos a utilizar

int PinPote= A0;  //Pin usado para conectar el potenciómetro
int ValorPote;    //Lectura de la posición del potenciómetro

void setup() {
MiServo.attach(3);  //Definimos el pin de señal del servo
}

void loop() {
  
ValorPote = analogRead(PinPote);
//leemos valor ANAlÓGICO del potenciometro
//(entre 0 y 1023)

ValorPote = map(ValorPote, 0, 1023, 0, 180);
//transformamos el valor leído a la escala del servomotor
//(entre 0 y 180)

MiServo.write(ValorPote);
//Escribimos el valor transformado del potenciómetro en el servo

delay(10);
//10ms de espera por educación
} 
