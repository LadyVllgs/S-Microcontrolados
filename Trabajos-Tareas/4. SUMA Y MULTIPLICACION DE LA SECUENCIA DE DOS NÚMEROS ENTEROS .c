//Crear un programa que calcule la sumatoria y productoria de los números enteros en el rango dado por
//INICIO y FIN. Se debe verificar que FIN sea mayor que INICIO, en caso que no se cumpla esa condición,
//no se debe mostrar nada en pantalla. Resultado esperado en pantalla:
//{'Número de inicio' : INICIO, 'Número de fin' : FIN, 'Sumatoria' : SUMATORIA, 'Productoria' : PRODUCTORIA}

//Integrantes: Leidy Villegas y Daniel Caballero




#include <stdio.h>
int main()
{
  // Declaramos variable
  int INICIO, FIN;
  int SUMATORIA = 0;
  int PRODUCTORIA = 1;
 

  // Damos valores a las variables
  INICIO = 5;
  FIN = 12;
    // Indicamos el condicional para los rangos
  if (INICIO <0 ||FIN < INICIO) {
  
  // no se ejecuta
    return 0; 
   }
   
     if (FIN > INICIO) {
       
        for (int i = INICIO; i <= FIN; i++) {
            // Aquí se calcula el término i-ésimo de la secuencia,
            // usando la expresión "expresion i" que puede involucrar a 'i'
            // Por ejemplo, si "i" fuera "i*2", se sumaría 2*i
            SUMATORIA += i; 
            // Aquí se calcula el término i-ésimo de la secuencia,
            // usando la expresión "expresion i" que puede involucrar a 'i'
            // Por ejemplo, si "expresion i" fuera "i+1", se multiplicaría (i+1)
            PRODUCTORIA *= i;
        }

        // Mostrar resultados 
        printf("{ 'Número de inicio' : %d, 'Número de fin' : %d, 'Sumatoria' : %lld, 'Productoria' : %lld }\n",
               INICIO, FIN, SUMATORIA, PRODUCTORIA);
    }

    return 0; 
   
}
