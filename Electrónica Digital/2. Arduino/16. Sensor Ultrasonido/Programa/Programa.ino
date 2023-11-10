int trigPin = 9;
int echoPin = 8;
int duration; //tiempo de ida/vuelta
int cm = 0; //Para almacenar el valor obtenido en cm valor=0

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop()
{
//ponemos al trigger a low para activarlo después
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
  
//Activar el módulo con un pulso de 10microsec.
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  
//Esperamos la llegada de un pulso HIGH
duration = pulseIn(echoPin, HIGH); // valor del pulso alto en microsegundos

//tiempo de ida y vuelta, dividimos por 2
duration=duration/2;
  
//Transformamos el tiempo en distancia:
//La velocidad del sonido es de 340 m/s
//El pin echo entrega un pulso alto 
//de una duración de 29 microsegundos 
//por cada centímetro de distancia
//a la que esté el objeto.
cm = duration/ 29;

//se saca el valor por el puerto serie  
Serial.print("Distancia:");
Serial.println(cm);
delay(100); // Nos aseguramos de que el siguiente trigger
// y el echo actual no se mezclen (se recomienda más de 50 ms). 
}
