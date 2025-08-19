#include <stdio.h>

void mostrarBinario4bits(int numero) {
    for (int i = 3; i >= 0; i--) {
        printf("%d", (numero >> i) & 1);
    }
    printf("\n");
}

void tablaDeVerdad(int numero) {
    int bits = 16; // siempre 16 combinaciones para 4 entradas

    printf("Numero en decimal: %d\n", numero);
    printf("Numero en binario (4 bits): ");
    mostrarBinario4bits(numero);
    printf("\n");

    printf("Tabla de verdad (4 entradas, 16 combinaciones):\n");
    printf("A B C D | Q\n");
    printf("----------------\n");

    for (int i = 0; i < bits; i++) {
        // imprimir entradas (A=bit3, B=bit2, C=bit1, D=bit0)
        printf("%d %d %d %d | ",
               (i >> 3) & 1,
               (i >> 2) & 1,
               (i >> 1) & 1,
               (i >> 0) & 1);

        // salida según el bit correspondiente (MSB primero, de los 16 bits)
        int salida = (numero >> (bits - 1 - i)) & 1;
        printf("%d\n", salida);
    }
}

int main() {
    int numero = 13; // número declarado
    tablaDeVerdad(numero);
    return 0;
}
