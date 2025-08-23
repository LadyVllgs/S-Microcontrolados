#include <Arduino.h>

int ultimo = 0;
int mayor = -1;
int menor = 101;
int suma = 0;
int contador = 0;

void procesarMensaje(String mensaje) {
  // Validar formato básico
  if (mensaje.startsWith("{'caudal': ") && mensaje.endsWith("}")) {
    // Extraer los dos dígitos
    String valorStr = mensaje.substring(11, 13);
    int valor = valorStr.toInt();

    // Validar rango 0–99
    if (valor >= 0 && valor <= 99) {
      // Actualizar estadísticas
      ultimo = valor;
      if (valor > mayor) mayor = valor;
      if (valor < menor) menor = valor;
      suma += valor;
      contador++;

      float promedio = (float)suma / contador;

      // Imprimir en el formato solicitado
      Serial.printf("{'último': %d, 'mayor': %d, 'menor': %d, 'promedio': %.2f}\n",
                    ultimo, mayor, menor, promedio);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 listo para recibir datos del caudalímetro...");
}

void loop() {
  // Leer línea completa desde el puerto serial
  if (Serial.available()) {
    String mensaje = Serial.readStringUntil('\n');
    mensaje.trim(); // eliminar espacios/saltos de línea
    procesarMensaje(mensaje);
  }
}