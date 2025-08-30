#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
 
#define UART_PORT       UART_NUM_0
#define BAUD_RATE       115200
#define BUF_SIZE        1024
 
static char lineBuf[32];
static size_t lineLen = 0;
 
static void resetBuffer() {
    lineLen = 0;
    lineBuf[0] = '\0';
}
 
static void processLine() {
    // Quitar espacios y saltos al final
    while (lineLen > 0 && (lineBuf[lineLen - 1] == '\r' || lineBuf[lineLen - 1] == '\n' ||
                           lineBuf[lineLen - 1] == ' '  || lineBuf[lineLen - 1] == '\t')) {
        lineLen--;
    }
    lineBuf[lineLen] = '\0';
 
    if (lineLen == 0) { resetBuffer(); return; }
 
    // Validar que sean solo dígitos
    for (size_t i = 0; i < lineLen; i++) {
        if (lineBuf[i] < '0' || lineBuf[i] > '9') {
            printf("Entrada inválida\n");
            resetBuffer();
            return;
        }
    }
 
    // Convertir a número
    unsigned long n = strtoul(lineBuf, NULL, 10);
 
    if (n == 0 || n > 46340UL) {
        printf("Número fuera de rango\n");
        resetBuffer();
        return;
    }
 
    // Calcular suma de impares = n^2
    unsigned long long suma = 0;
    for (unsigned long i = 0; i < n; i++) {
        suma += (2ULL * i + 1ULL);
    }
 
    printf("Resultado: %lu\n", (unsigned long)suma);
 
    resetBuffer();
}
 
static void uart_task(void *arg) {
    uint8_t data[BUF_SIZE];
 
    printf("Listo. Ingresa un número entero positivo (>0) y presiona Enter:\n");
 
    while (1) {
        int len = uart_read_bytes(UART_PORT, data, BUF_SIZE - 1, 20 / portTICK_PERIOD_MS);
        if (len > 0) {
            data[len] = '\0';
 
            for (int i = 0; i < len; i++) {
                char c = (char)data[i];
                if (c == '\r' || c == '\n') {
                    processLine();
                } else {
                    if (lineLen < sizeof(lineBuf) - 1) {
                        lineBuf[lineLen++] = c;
                        lineBuf[lineLen] = '\0';
                    } else {
                        printf("Overflow del buffer, reiniciando...\n");
                        resetBuffer();
                    }
                }
            }
        }
    }
}
 
void app_main(void) {
    // Configuración de UART
    const uart_config_t uart_config = {
        .baud_rate = BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };
 
    uart_param_config(UART_PORT, &uart_config);
    uart_driver_install(UART_PORT, BUF_SIZE, 0, 0, NULL, 0);
 
    // Crear tarea que maneja la UART
    xTaskCreate(uart_task, "uart_task", 4096, NULL, 10, NULL);
}