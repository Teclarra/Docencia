/*ÁNODO COMÚN*/
const int DIGITOS[10][7] = {
/*0*/ {0,0,0,0,0,0,1},
/*1*/ {1,0,0,1,1,1,1},
/*2*/ {0,0,1,0,0,1,0},
/*3*/ {0,0,0,0,1,1,0},
/*4*/ {1,0,0,1,1,0,0},
/*5*/ {0,1,0,0,1,0,0},
/*6*/ {0,1,0,0,0,0,0},
/*7*/ {0,0,0,1,1,1,1},
/*8*/ {0,0,0,0,0,0,0},
/*9*/ {0,0,0,0,1,0,0}
};
const int OFF = HIGH;

const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

const int N = 7;
const int SEGMENTOS[N] = {A,B,C,D,E,F,G};

void setup()
{
  for (int i=0; i<N; i++){
    pinMode(SEGMENTOS[i], OUTPUT);
    digitalWrite(SEGMENTOS[i], OFF);//apagar
  }
}
void print(int d){
  for (int i=0; i<N; i++){
    digitalWrite(SEGMENTOS[i], DIGITOS[d][i]);
  }
}

void loop()
{
  for(int i=0; i<10; i++){
      print(i);
      delay(1000);// esperar 1000 milisegundos
  }
}
