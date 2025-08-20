#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero_integrantes, cantidad_exponentes;
    int *orden_exponentes = NULL;
    
    // Inicializar semilla para números aleatorios
    srand(time(NULL));  // Corrección aquí
    
    printf("Seleccionar un número: ");
    scanf("%d", &numero_integrantes);
    
    // Validar que el número de integrantes sea positivo
    if (numero_integrantes <= 0) {
        printf("Error: El número de integrantes debe ser positivo.\n");  // Comillas corregidas
        return 1;
    }
    
    // Determinar la cantidad de exponentes (1 a numero_integrantes)
    cantidad_exponentes = (numero_integrantes == 1) ? 1 : (rand() % numero_integrantes) + 1;  // ! cambiado por 1
    
    // Asignar memoria para el arreglo de orden
    orden_exponentes = (int *)malloc(cantidad_exponentes * sizeof(int));
    if (orden_exponentes == NULL) {
        printf("Error: No se pudo asignar memoria.\n");  // Comillas corregidas
        return 1;
    }
    
    // Generar el orden de exponentes (números únicos del 1 al numero_integrantes)
    for (int i = 0; i < cantidad_exponentes; i++) {
        int num;
        do {
            num = (rand() % numero_integrantes) + 1;
            // Verificar que no se repita
            int repetido = 0;
            for (int j = 0; j < i; j++) {  // Variable j en lugar de i
                if (orden_exponentes[j] == num) {
                    repetido = 1;
                    break;  // Agregado break
                }
            }
            if (!repetido) {
                orden_exponentes[i] = num;
                break;
            }
        } while (1);
    }
    
    // Mostrar resultados
    printf("{\"Número de integrantes en el grupo\": %d, 'Cantidad de exponentes': %d, 'Orden de exponentes': [", 
           numero_integrantes, cantidad_exponentes);
    
    for (int i = 0; i < cantidad_exponentes; i++) {
        printf("%d", orden_exponentes[i]);
        if (i < cantidad_exponentes - 1) {
            printf(", ");
        }
    }
    printf("]}\n");
    
    // Liberar memoria
    free(orden_exponentes);
    
    return 0;
}