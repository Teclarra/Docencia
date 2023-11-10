#include <Servo.h> //Incluimos la librería Servo

Servo MiServo;  //Definimos el servo que vamos a utilizar

int PinPote= A0;  //Pin usado para conectar el potenciómetro
int ValorPote;    //Lectura de la posición del potenciómetro

Servo MiServo2;  //Definimos el servo que vamos a utilizar

int PinPote2= A1;  //Pin usado para conectar el potenciómetro
int ValorPote2; 

void setup() {
MiServo.attach(3);  //Definimos el pin de señal del servo
MiServo2.attach(5);  //Definimos el pin de señal del servo
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
  
  
  ValorPote2 = analogRead(PinPote2);
//leemos valor ANAlÓGICO del potenciometro
//(entre 0 y 1023)

ValorPote2 = map(ValorPote2, 0, 1023, 0, 180);
//transformamos el valor leído a la escala del servomotor
//(entre 0 y 180)

MiServo2.write(ValorPote2);
//Escribimos el valor transformado del potenciómetro en el servo

delay(10);
//10ms de espera por educación
} 
