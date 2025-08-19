//De un número entero positivo que está guardado en una variable llamada NUMERO, mostrar en pantalla su raíz
//cuadrada usada el método de Newton. Para este ejercicio debe realizarse una función que acepte el valor la
//variable NUMERO y retorne el resultado usando el método de Newton, sin usar una librería que contenga esa función. 
//Resultado esperado en pantalla:
//{'Número' : NUMERO, 'Raíz cuadrada usando Newton' : RESULTADO}

//Inregrantes: Leidy Villegas y Daniel Caballero

#include <stdio.h>
int main()
{
  // Declaramos variable
  int NUMERO;
  
  NUMERO = 2645;
  
  // Indicamos el condicional para los rangos
  if (NUMERO <=1000 ||NUMERO >= 9999) {
  
  // no se ejecuta
    return 0; 
  
  }
    // separa las unidades del numero
   int UNIDAD_DE_MIL = NUMERO / 1000;
    int CENTENA = (NUMERO / 100) % 10;
    int DECENA = (NUMERO / 10) % 10;
    int UNIDAD = NUMERO % 10;
    
    printf("{ 'Número' : %d, 'Unidad' : %d, 'Decena' : %d, 'Centena' : %d, 'Unidad de mil' : %d }\n",
           NUMERO, UNIDAD, DECENA, CENTENA, UNIDAD_DE_MIL);
    return 0;
   
  }