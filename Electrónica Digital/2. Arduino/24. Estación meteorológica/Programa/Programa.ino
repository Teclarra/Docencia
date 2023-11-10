//librería sensor de temperatura/humedad
#include<DHT.h>

//Pines
#define pluviometroPower 7
#define pluviometroPin A0
#define encoder A1
#define dhtPin 3

//tipo de sensor de temperatura/humedad
#define dhtType DHT11

//Constantes
#define pi 3.141592

//Variables pluviometro
int valor = 0;
int val=0;

//Variables encoder
int actualEncoder;
int pasadoEncoder;
int umbralLDR;
int velocidadAngular;
int radio;
int velocidadLineal;
volatile int pulsosEncoder=0; //mide revoluciones por segundo

//Variables sensor de temperatura/humedad
DHT dht(dhtPin,dhtType);
float h; //humedad relativa
float t; //temperatura centigrados
float f; //temperatura fahrenheit

//Variables consultas periodicas  
unsigned long tiempo_pluviometro=0;
unsigned long tiempo_encoder=0;
unsigned long tiempo_humTemp=0;
unsigned long tiempo_serial=0;


void setup() {
    pinMode(encoder, INPUT_PULLUP); 
  pinMode(sensorPower, OUTPUT);
  
    pasadoEncoder=(analogRead(encoder)>umbralEncoder)
  digitalWrite(sensorPower, LOW);  
  
  Serial.begin(9600);
    dht.begin();
}

void loop() {
  
  actualEncoder=(analogRead(encoder)>umbralEncoder)
    
  if(actualEncoder==1 && actualEncoder!=pasadoEncoder){
    pulsosEncoder++;
    pasadoEncoder=actualEncoder;}
  
  
  if((millis()-tiempo_humTemp>2000){
      // Leemos la humedad relativa
    float h = dht.readHumidity();
      // Leemos la temperatura en grados centígrados (por defecto)
    float t = dht.readTemperature();
      // Leemos la temperatura en grados Fahrenheit
    float f = dht.readTemperature(true);
 
      // Comprobamos si ha habido algún error en la lectura
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Error obteniendo los datos del sensor DHT11");
    return;}
    
        // Calcular el índice de calor en Fahrenheit
   float hif = dht.computeHeatIndex(f, h);
      // Calcular el índice de calor en grados centígrados
     float hic = dht.computeHeatIndex(t, h, false);  
    
     tiempo_humTemp = millis();
  }
     
  if ((millis()-tiempo_encoder) > 1000){
    velocidadAngular = pulsosEncoder*2*pi;    //rad/s
    velocidadLineal = velocidadAngular*radio; //m/s
    pulsosEncoder = 0;
    tiempo_encoder = millis();   
  }

  if((millis()-tiempo_pluviometro)>5000)[
  int valor = leerPluviometro();
  
  if (valor<=480 && valor>530)
    altura=((valor-480)/(530-480))*5;
  else if (valor<=530 && valor>615)
    altura=((valor-530)/(615-530))*5;
  else if (valor<=615 && valor>660)
    altura=((valor-615)/(615-660))*5;
  else if (valor<=660 && valor>680)
    altura=((valor-660)/(680-660))*5;
  else if (valor<=680 && valor>690)
    altura=((valor-680)/(690-680))*5;
  else if (valor<=690 && valor>700)
    altura=((valor-690)/(700-690))*5;
  else if (valor<=700 && valor>705)
    altura=((valor-700)/(705-700))*5;
  else if (valor<=705 && valor>710)
    altura=((valor-705)/(710-705))*5;
    
    tiempo_pluviometro = millis();
    }
    
    
    if(millis()-tiempo_serial)>1000){
      
      Serial.println("Velocidad del viento: ");
      Serial.print(velocidadLineal);
      Serial.print("m/s");
      
    Serial.println(" Altura de agua: ");
      Serial.print(altura);
      Serial.print("mm");
      
    Serial.println("Humedad: ");
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.print(" *C ");
      Serial.print(f);
      Serial.print(" *F\t");
      Serial.print("Índice de calor: ");
      Serial.print(hic);
      Serial.print(" *C ");
      Serial.print(hif);
      Serial.println(" *F");
      
        tiempo_serial = millis();
    }
    

}

    //FUNCION PARA LEER PLUVIOMETRO 
int leerPluviometro() {
  digitalWrite(pluviometroPower, HIGH);   
  delay(10);              
  val = analogRead(pluviometroPin);   
  digitalWrite(pluviometroPower, LOW);    
  return val;             
}   
