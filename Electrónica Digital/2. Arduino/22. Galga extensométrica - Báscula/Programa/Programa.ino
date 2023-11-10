int valor;
int peso;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
valor=analogRead(A0);
peso=map(valor, 0, 1023, 0, 150);
Serial.print("Valor medido:");
Serial.print(valor);
Serial.print(" Peso:");
Serial.print(peso);
Serial.println(" Kg");
               }
