#include <Arduino.h>
#include <stdlib.h>

#define BAUD 115200

// Buffer para acumular lo escrito por el usuario hasta Enter
static char lineBuf[32];     // admite hasta 31 caracteres + '\0' (sobra para valores de N realistas)
static size_t lineLen = 0;
static bool lastWasCR = false; // para no procesar dos veces cuando llega CRLF

static void resetBuffer() {
  lineLen = 0;
  lineBuf[0] = '\0';
}

// Procesa una línea terminada (sin '\n' ni '\r' dentro)
static void processLine() {
  // Trim final por si queda espacio/CR/LF
  while (lineLen > 0 && (lineBuf[lineLen - 1] == '\r' || lineBuf[lineLen - 1] == '\n' || lineBuf[lineLen - 1] == ' ' || lineBuf[lineLen - 1] == '\t')) {
    lineLen--;
  }
  lineBuf[lineLen] = '\0';

  if (lineLen == 0) { resetBuffer(); return; }

  // Validar: solo dígitos (sin signos, ni puntos)
  for (size_t i = 0; i < lineLen; ++i) {
    if (lineBuf[i] < '0' || lineBuf[i] > '9') {
      // Contenido inválido → ignorar
      resetBuffer();
      return;
    }
  }

  // Convertir a número (base 10)
  unsigned long n = strtoul(lineBuf, nullptr, 10);

  // Reglas: > 0 y <= 46340 (para evitar overflow de 32 bits en n^2)
  if (n == 0 || n > 46340UL) { resetBuffer(); return; }

  // Calcular por suma de impares: 1 + 3 + 5 + ... + (2n-1)
  // Guardamos en 64 bits por seguridad, pero para n<=46340 cabe en 32 bits.
  unsigned long long suma = 0;
  for (unsigned long i = 0; i < n; ++i) {
    suma += (2ULL * i + 1ULL);
  }

  // Imprimir solo el resultado (como pide el enunciado)
  // Para n<=46340, esto cabe en 32 bits; imprimimos como unsigned long.
  Serial.println((unsigned long)suma);

  resetBuffer();
}

void setup() {
  Serial.begin(BAUD);
  // Mensaje de cortesía (no es obligatorio)
  Serial.println("Listo. Envia un entero positivo (>0) y presiona Enter.");
  resetBuffer();
}

void loop() {
  while (Serial.available() > 0) {
    char c = (char)Serial.read();

    if (c == '\r') {           // Enter tipo CR
      lastWasCR = true;
      processLine();
    } else if (c == '\n') {    // Enter tipo LF o parte de CRLF
      if (!lastWasCR) {
        processLine();
      }
      lastWasCR = false;
    } else {
      lastWasCR = false;
      if (lineLen < sizeof(lineBuf) - 1) {
        lineBuf[lineLen++] = c;
        lineBuf[lineLen] = '\0';
      } else {
        // Overflow del buffer → descartamos y esperamos una nueva línea
        resetBuffer();
      }
    }
  }
}