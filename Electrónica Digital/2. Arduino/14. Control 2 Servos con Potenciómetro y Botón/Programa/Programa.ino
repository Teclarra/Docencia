#include <Servo.h> //Incluimos la librería Servo (tiene las funciones para
           //               controlar servomotores)

Servo Giro;     //Variable tipo servo para el servomotor giro
Servo Disparo;  //Variable tipo servo para el servomotor disparo

int PinPote= A0;  //Pin usado para conectar el potenciómetro
int ValorPote;    //Lectura de la posición del potenciómetro

void setup() {     //Función de configuración
Giro.attach(3);    //Definimos dónde conectamos el servo  giro
Disparo.attach(5); //Definimos dónde conectamos el servo disparo
pinMode(4, INPUT); //indicamos que el pin 4 se comporta como entrada

Disparo.write(0);  //Damos un valor inicial (0) al servo disparo
}

void loop() {      //Función que se repite en bucle
 
//CONTROL DE GIRO (potenciómetro)  
ValorPote = analogRead(PinPote);
//leemos valor ANAlÓGICO del potenciometro
//(entre 0 y 1023)

ValorPote = map(ValorPote, 0, 1023, 0, 180);
//transformamos el valor leído a la escala del servomotor
//(entre 0 y 180)

Giro.write(ValorPote);
//Escribimos el valor transformado del potenciómetro en el servo

delay(10);
//10ms de espera por educación
 
//CONTROL DE DISPARO (botón pull-up) 
if(digitalRead(4)==LOW){ //si la lectura digital es baja tensión
Disparo.write(60);     //movemos el servo disparo 60 grados
delay(500);        //esperamos medio segundo
Disparo.write(0);    //volvemos a mover el servo disparo a 0 grados
delay(10);}        //esperamos 10ms
} 
