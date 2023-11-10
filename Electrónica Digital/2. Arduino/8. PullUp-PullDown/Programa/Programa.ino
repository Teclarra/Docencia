void setup()
{
  pinMode(2, INPUT); //INPUT_PULLDOWN no existe
  pinMode(3, INPUT); //INPUT_PULLUP
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
 if(digitalRead(2)==HIGH)    //si la lectura del botón es alta
  digitalWrite(4, HIGH);    //enciendo el LED
  else if (digitalRead(2)==LOW) //si es baja
  digitalWrite(4, LOW);   //apago el LED
//LED pull down normalmente APAGADO
    
//if(digitalRead(2)==HIGH)  
//  digitalWrite(4, LOW); 
//else if (digitalRead(2)==LOW)
//  digitalWrite(4, HIGH);
//LED pull down normalmente ENCENDIDO
  
    
// if(digitalRead(3)==HIGH)   //si la lectura del botón es alta
//    digitalWrite(5, HIGH);    //enciendo el LED
//  else if (digitalRead(3)==LOW) //si es baja
//  digitalWrite(5, LOW);   //apago el LED
//LED pull up normalmente ENCENDIDO

      
 if(digitalRead(3)==HIGH)     
  digitalWrite(5, LOW);   
 else if (digitalRead(3)==LOW)  
  digitalWrite(5, HIGH);  
//LED pull up normalmente APAGADO
}
