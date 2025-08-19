//1. RAIZ DE UN NUMERO POSITIVO USANDO EL METODO DE NEWTON
#include <stdio.h>
    
    double raiznewton (double numero)
    {
      //Declaramos las variables NUMERO y RaizAprox
      double raiz, raizaprox;
      
      raiz = numero / 2.0;
      do {
        raizaprox = raiz;
        raiz= (raizaprox + (numero / raizaprox)) / 2.0;
        printf("APROXIMACION: %lf\t Raiz: %lf\n", raizaprox, raiz);
      } while(raiz != raizaprox);
      
      return raiz;
    }
    
    
    
    
    int main()
    {
      double numero =9.0;
      double raiz = raiznewton(numero);
      printf("La raiz cuadrada de %lf es %lf\n", numero, raiz);
      return 0;
    }
   
     
    