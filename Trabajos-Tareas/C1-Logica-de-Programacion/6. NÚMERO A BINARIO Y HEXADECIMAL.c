//En una variable llamada NUMERO está en binario el valor del número hexadecimal CAFE. Realizar un
//desplazamiento de bits a la izquierda e imprimir en pantalla el valor tanto en binario como en hexadecimal.

//Integrantes: Leidy Villegas y Daniel Caballero

#include <stdio.h>

// Función para imprimir un número en binario
void printBinary(unsigned int num) {
    // Asumimos 16 bits para este ejercicio
    for(int i = 13; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if(i % 4 == 0) printf(" "); // Espacio cada 4 bits para mejor lectura
    }
}

int main() {
    // Paso 1: Almacenar CAFE en binario (se almacena como 0xCAFE)
    unsigned int NUMERO = 0xCAFE;
    
    printf("Valor inicial (0xCAFE):\n");
    printf("Binario: ");
    printBinary(NUMERO);
    printf("\nHexadecimal: 0x%X\n", NUMERO);
    
    // Paso 2: Desplazamiento a la izquierda
    NUMERO = NUMERO << 1;
    
    printf("\nDespués del desplazamiento:\n");
    printf("Binario: ");
    printBinary(NUMERO);
    printf("\nHexadecimal: 0x%X\n", NUMERO); 
    
    return 0;
}