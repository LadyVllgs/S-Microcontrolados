#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

// Se declaran las variables
int numero = 0;
int cuadrado = 0;
char texto_recibido[50];

void setup() {
    Serial.begin(115200);  // Inicia comunicación serial a 115200 baudios
    Serial.println("Escriba un número entero positivo:");
}

void loop() {
    // Verifica si llegaron datos por el puerto serial
    if (Serial.available() > 0) {
        texto_recibido = Serial.readStringUntil('\n');
        texto_recibido.trim();  // se usa.trim para eliminar espacios en blanco

        // comprobar que sea un numero entero positivo
        if (texto_recibido[50].atoi() > 0) {
            numero = texto_recibido[50].atoi();  // Convierte a entero
            cuadrado = 0;

            // se suman los  números impares
            for (int i = 1, contador = 0; contador < numero; i += 2, contador++) {
                cuadrado += i;
            }

            // se imprime el resultado
            Serial.print("El cuadrado de ");
            Serial.print(numero);
            Serial.print(" es: ");
            Serial.println(cuadrado);
        } else {
            Serial.println("Entrada no válida. Escribe un número entero positivo mayor a 0.");
        }
    }
}