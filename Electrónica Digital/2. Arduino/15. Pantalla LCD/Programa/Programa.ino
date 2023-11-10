//incluimos la libreria:
#include <LiquidCrystal.h>

//inicializamos la libreria con los numeros de los pines de la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //establecemos numero de filas y columnas
  lcd.begin(16, 2);
  //escribimos el mensaje
  lcd.print("Hola, Mundo!");
}

void loop() {
  //movemos el cursor a la columna 0 linea 1
  //(nota: la linea 1 es la segunda. La primera linea es la 0)
  lcd.setCursor(0, 1);
  //escribimos el numero de segundos que han pasado
  lcd.print(millis() / 1000);
}
 
