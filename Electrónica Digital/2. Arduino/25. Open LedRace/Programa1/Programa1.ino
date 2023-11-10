#include <Adafruit_NeoPixel.h>     //Libreria de funciones que controlan la tira Led
#define MAXLED         20         //numero MAX LEDs activos en la tira

#define PIN_LED        8           // R 500 ohms to DI pin for WS2812 and WS2813, for WS2813 BI pin of first LED to GND 
#define PIN_P1         A0          // switch player 1 to PIN A0 and GND
#define PIN_P2         A1          // switch player 2 to PIN A1 and GND 
#define PIN_P3         A2          // switch player 3 to PIN A2 and GND
#define PIN_P4         A3          // switch player 4 to PIN A3 and GND 
#define PIN_AUDIO     10           // BUZZER
#define PIN_LED_R     13           // Led Red
#define PIN_LED_O     12           // Led Orange
#define PIN_LED_G     11           // Led Green
#define PIN_LED_B      6           // Led Blue

//VARIABLES

int NPIXELS=MAXLED;                                  // numero de leds de la pista

#define COLOR1    track.Color(255,0,0)               //colores de los coches
#define COLOR2    track.Color(0,255,0)
#define COLOR3    track.Color(255,0,255)
#define COLOR4    track.Color(255,255,0)
int win_music[] = {                                  //melodía de victoria
  2637, 2637, 0, 2637, 
  0, 2093, 2637, 0,
  3136    
};
      
byte  gravity_map[MAXLED];   //funcion de adafruit que mapea la pista                   

int TBEEP=3; 

float speed1=0;              //velocidad de los coches
float speed2=0;
float speed3=0;
float speed4=0;

float dist1=0;               //distancia de los coches
float dist2=0;
float dist3=0;
float dist4=0;

byte loop1=0;                //vueltas de los coches
byte loop2=0;
byte loop3=0;
byte loop4=0;

byte leader=0;               //lider
byte loop_max=5;             //total de vueltas


float ACEL=0.2;                //aceleración de los coches
float kf=0.015;                //constante de friccion. Frenado si dejamos de correr
float kg=0.003;                //constante de gravedad. Constante de la rampa

byte flag_sw1=0;               //banderas de los coches. Detectan el flanco
byte flag_sw2=0;
byte flag_sw3=0;
byte flag_sw4=0;
byte draworder=0;              //orden de dibujo
 
unsigned long timestamp=0;

Adafruit_NeoPixel track = Adafruit_NeoPixel(MAXLED, PIN_LED, NEO_GRB + NEO_KHZ800); //variable de la pista

int tdelay = 5;                                                              //tiempo de retardo

//FUNCIONES


void set_ramp(byte H,byte a,byte b,byte c)                                   //funcion que genera la rampa
{for(int i=0;i<(b-a);i++){gravity_map[a+i]=127-i*((float)H/(b-a));};
 gravity_map[b]=127; 
 for(int i=0;i<(c-b);i++){gravity_map[b+i+1]=127+H-i*((float)H/(c-b));};
}

void setup() {
  for(int i=0;i<NPIXELS;i++){gravity_map[i]=127;};
  track.begin(); 
  pinMode(PIN_P1,INPUT_PULLUP);                                               //Choose INPUT_PULLUP or INPUT. Using EchidnaShield: INPUT
  pinMode(PIN_P2,INPUT_PULLUP);
  pinMode(PIN_P3,INPUT_PULLUP);
  pinMode(PIN_P4,INPUT_PULLUP);
  pinMode(PIN_LED_R,OUTPUT);
  pinMode(PIN_LED_O,OUTPUT);      
  pinMode(PIN_LED_G,OUTPUT);
  pinMode(PIN_LED_B,OUTPUT);

  //if ((digitalRead(PIN_P1)==0))                                               //activa/desactiva la rampa y llama a la funcion que crea la rampa
  //{
    set_ramp(10,6,9,13);                                                  // ramp centrada en el LED 100 con 10 leds hacia adelante y 10 hacia atras 
    for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(0,0,(127-gravity_map[i])/8) );};
    digitalWrite (PIN_LED_B, HIGH);
    track.show();
  //};
  start_race();    
}

void start_race(){for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(0,0,0));};  //apaga la pista
                  digitalWrite(PIN_LED_O,LOW);
                  track.show();
                  delay(2000);
                  track.setPixelColor(12, track.Color(255,0,0));                           //enciende semaforo en rojo de la pista
                  track.setPixelColor(11, track.Color(255,0,0));                           
                  track.show();
                  digitalWrite(PIN_LED_R,HIGH);                                            //enciende led en el shield
                  tone(PIN_AUDIO,400);                                                     //enciende el zumbador
                  delay(1000);
                  digitalWrite(PIN_LED_R,LOW);                                             //apaga led rojo en el shield
                  delay(1000);
                  noTone(PIN_AUDIO);                                                       //apaga el zumbador                  
                  track.setPixelColor(12, track.Color(0,0,0));                             //enciende led ambar en la pista
                  track.setPixelColor(11, track.Color(0,0,0));
                  track.setPixelColor(10, track.Color(255,200,0));
                  track.setPixelColor(9, track.Color(255,200,0));
                  track.show();
                  digitalWrite(PIN_LED_O,HIGH);                                          //enciende led en el shield
                  tone(PIN_AUDIO,600);                                                   //zumbador
                  delay(1000);
                  digitalWrite(PIN_LED_O,LOW);                                           //apagamos led en el shield
                  delay(1200);
                  digitalWrite(PIN_LED_G,HIGH);                                        //enciende led en el shield
                  noTone(PIN_AUDIO);                                                   //apagamos zumbador
                  track.setPixelColor(9, track.Color(0,0,0));                          //enciende led en verde en la pista
                  track.setPixelColor(10, track.Color(0,0,0));
                  track.setPixelColor(8, track.Color(0,255,0));
                  track.setPixelColor(7, track.Color(0,255,0));
                  track.show();
                  tone(PIN_AUDIO,1200);                                             //Zumbador
                  delay(2000);
                  digitalWrite(PIN_LED_G,LOW);                                     //se apagan los leds de la pista y el shield
                  digitalWrite(PIN_LED_B,LOW);
                  analogWrite(PIN_LED_G,16);
                  noTone(PIN_AUDIO);                               
                  timestamp=0;              
                 };

void winner_fx() {                                                         //reproduce las notas guardadas en la melodía de victoria
               int msize = sizeof(win_music) / sizeof(int);
               for (int note = 0; note < msize; note++) {
               tone(PIN_AUDIO, win_music[note],200);
               delay(230);
               noTone(PIN_AUDIO);

}

                                               
              };



//Funciones encargadas de representar los coches en cada vuelta

void draw_car1(void){for(int i=0;i<=loop1;i++){track.setPixelColor(((word)dist1 % NPIXELS)+i, track.Color(0,255-i*20,0));};                   
  }

void draw_car2(void){for(int i=0;i<=loop2;i++){track.setPixelColor(((word)dist2 % NPIXELS)+i, track.Color(255-i*20,0,0));};            
 }

void draw_car3(void){for(int i=0;i<=loop3;i++){track.setPixelColor(((word)dist3 % NPIXELS)+i, track.Color(255-i*20,0,255-i*20));};                   
  }

void draw_car4(void){for(int i=0;i<=loop4;i++){track.setPixelColor(((word)dist4 % NPIXELS)+i, track.Color(255-i*20,255-i*20,0));};            
 }
  
void loop() {
    //for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(0,0,0));};
    for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(0,0,(127-gravity_map[i])/8) );};

    //algoritmo encargado de detectar el flanco en lugar de si está o no pulsado
    if ( (flag_sw1==1) && (digitalRead(PIN_P1)==1) ) {flag_sw1=0;speed1+=ACEL;}; //0
    if ( (flag_sw1==0) && (digitalRead(PIN_P1)==0) ) {flag_sw1=1;}; //1

    //algoritmo que detecta si el coche está en la rampa y acelera o frena al coches
    if ((gravity_map[(word)dist1 % NPIXELS])<127) speed1-=kg*(127-(gravity_map[(word)dist1 % NPIXELS]));
    if ((gravity_map[(word)dist1 % NPIXELS])>127) speed1+=kg*((gravity_map[(word)dist1 % NPIXELS])-127);
    
    //la velocidad de los coches va disminuyendo
    speed1-=speed1*kf; 
    
    if ( (flag_sw2==1) && (digitalRead(PIN_P2)==1) ) {flag_sw2=0;speed2+=ACEL;};
    if ( (flag_sw2==0) && (digitalRead(PIN_P2)==0) ) {flag_sw2=1;};

    if ((gravity_map[(word)dist2 % NPIXELS])<127) speed2-=kg*(127-(gravity_map[(word)dist2 % NPIXELS]));
    if ((gravity_map[(word)dist2 % NPIXELS])>127) speed2+=kg*((gravity_map[(word)dist2 % NPIXELS])-127);
        
    speed2-=speed2*kf; 

    if ( (flag_sw3==1) && (digitalRead(PIN_P3)==1) ) {flag_sw3=0;speed3+=ACEL;};
    if ( (flag_sw3==0) && (digitalRead(PIN_P3)==0) ) {flag_sw3=1;};

    if ((gravity_map[(word)dist3 % NPIXELS])<127) speed3-=kg*(127-(gravity_map[(word)dist3 % NPIXELS]));
    if ((gravity_map[(word)dist3 % NPIXELS])>127) speed3+=kg*((gravity_map[(word)dist3 % NPIXELS])-127);
        
    speed3-=speed3*kf; 

    if ( (flag_sw4==1) && (digitalRead(PIN_P4)==1) ) {flag_sw4=0;speed4+=ACEL;};
    if ( (flag_sw4==0) && (digitalRead(PIN_P4)==0) ) {flag_sw4=1;};

    if ((gravity_map[(word)dist4 % NPIXELS])<127) speed4-=kg*(127-(gravity_map[(word)dist4 % NPIXELS]));
    if ((gravity_map[(word)dist4 % NPIXELS])>127) speed4+=kg*((gravity_map[(word)dist4 % NPIXELS])-127);
        
    speed4-=speed4*kf; 

        //algoritmo encargado de saber qué coche ha recorrido más distancia
    dist1+=speed1;
    dist2+=speed2;
    dist3+=speed3;
    dist4+=speed4;

        //algoritmo encargado de saber, en función de la distancia recorrida, qué coche va primero
    if (dist1>dist2 and dist1>dist3 and dist1>dist4) {leader=1;} 
    if (dist2>dist1 and dist2>dist3 and dist2>dist4) {leader=2;}
    if (dist3>dist1 and dist3>dist2 and dist3>dist4) {leader=3;}
    if (dist4>dist1 and dist4>dist2 and dist4>dist3) {leader=4;} ;

      //algoritmo encargado de saber en qué vuelta está cada coche. Zumbador con cada vuelta
    if (dist1>NPIXELS*loop1) {loop1++;tone(PIN_AUDIO,600);TBEEP=2;};
    if (dist2>NPIXELS*loop2) {loop2++;tone(PIN_AUDIO,700);TBEEP=2;};
    if (dist3>NPIXELS*loop3) {loop3++;tone(PIN_AUDIO,600);TBEEP=2;};
    if (dist4>NPIXELS*loop4) {loop4++;tone(PIN_AUDIO,700);TBEEP=2;};

      //algoritmo encargado de saber quién ha ganado, reproduce melodia, reinicia parámetros y reinicia la carrera
    if (loop1>loop_max) {for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(0,16,0));}; track.show();
                                                    winner_fx();loop1=0;loop2=0;loop3=0;loop4=0;dist1=0;dist2=0;dist3=0;dist4=0;speed1=0;speed2=0;speed3=0;speed4=0;timestamp=0;
                                                     digitalWrite(PIN_LED_G,LOW);
                                                    start_race();
                                                   }
    if (loop2>loop_max) {for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(16,0,0));}; track.show(); //255 -> 128
                                                    winner_fx();loop1=0;loop2=0;loop3=0;loop4=0;dist1=0;dist2=0;dist3=0;dist4=0;speed1=0;speed2=0;speed3=0;speed4=0;timestamp=0;
                                                     digitalWrite(PIN_LED_G,LOW);
                                                    start_race();
                                                   }

    if (loop3>loop_max) {for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(16,0,16));}; track.show();
                                                    winner_fx();loop1=0;loop2=0;loop3=0;loop4=0;dist1=0;dist2=0;dist3=0;dist4=0;speed1=0;speed2=0;speed3=0;speed4=0;timestamp=0;
                                                     digitalWrite(PIN_LED_G,LOW);
                                                    start_race();
                                                   }
    if (loop4>loop_max) {for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(16,16,0));}; track.show(); //255 -> 128
                                                   winner_fx();loop1=0;loop2=0;loop3=0;loop4=0;dist1=0;dist2=0;dist3=0;dist4=0;speed1=0;speed2=0;speed3=0;speed4=0;timestamp=0;
                                                     digitalWrite(PIN_LED_G,LOW);
                                                    start_race();
                                                   }
        //algoritmo que elige en qué orden dibujar los coches                                          
    if ((millis() & 512)==(512*draworder)) {if (draworder==0) {draworder=1;}
                          else {draworder=0;}   
                         }; 
        //algoritmo que dibuja los coches
    if (draworder==0) {draw_car1();draw_car2();draw_car3();draw_car4();}
        else {draw_car4();draw_car3();draw_car2();draw_car1();}   
                 
    track.show(); 
    delay(tdelay);
    
    if (TBEEP>0) {TBEEP-=1; 
                  if (TBEEP==0) {noTone(PIN_AUDIO);}; // lib conflict !!!! interruption off by neopixel
                 };  
}
