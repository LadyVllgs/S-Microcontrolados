//SUMA DE NUMEROS PARES EN UN RANGO DE NUMEROS
#include <stdio.h>

int main ()
{
  //definimos las variables incio, fin y suma
  int inicio = 1;
  int fin = 10;
  int suma = 0;
  
  if (inicio > 0 && fin > inicio) {
     
    for (int i = inicio; i <= fin; i++) {
      if (i % 2 == 0) { 
        suma += i;
      }
    }
    
    printf("INICIO: %d FIN: %d SUMATORIA %d\n", inicio, fin, suma);
  }
}

