// ==============================================================================
// PROYECTO: Control de Carroza - PRUEBA CON ESP32 (Bluetooth Integrado)
// ==============================================================================
// IMPORTANTE: El ESP32 ya tiene Bluetooth clásico integrado, así que NO hace 
// falta conectar el módulo HC-05. Simplemente vinculá el celular al 
// dispositivo llamado "Carroza_ESP32" y la app va a funcionar igual.
// ==============================================================================

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error El Bluetooth no está habilitado. Por favor, selecciona una placa ESP32 compatible.
#endif

// Objeto para manejar el Bluetooth del ESP32
BluetoothSerial SerialBT;

// Array con pines seguros para usar como salida en el ESP32
// (Evitamos pines de booteo como el 0, 2, 5, 12 y 15 para evitar problemas al encender)
int pinesRelevadores[] = {13, 14, 25, 26, 27, 32, 33, 16, 17, 18, 19, 21};

void setup() {
  // Iniciamos el puerto Serial normal para ver mensajes en la compu (monitor serie)
  Serial.begin(115200);

  // Configuramos todos los pines de los relés como SALIDA y los apagamos
  for (int i = 0; i < 12; i++) {
    pinMode(pinesRelevadores[i], OUTPUT);
    digitalWrite(pinesRelevadores[i], HIGH); // Suponiendo lógica inversa
  }

  // Iniciamos el Bluetooth con el nombre que va a aparecer en el celular
  SerialBT.begin("Carroza_ESP32"); 
  Serial.println("¡El Bluetooth del ESP32 está listo! Vinculalo desde el celular.");
}

void loop() {
  // Comprobamos si nos llega algún comando desde la App por el Bluetooth
  if (SerialBT.available() > 0) {
    char comando = SerialBT.read();
    
    // Imprimimos la letra recibida en la PC para que veas que está llegando bien
    Serial.print("Recibido: ");
    Serial.println(comando);

    // =============== MOVIMIENTO (Botones Momentáneos) ===============
    // Adelante
    if (comando == 'A') { rele1_ON(); }
    else if (comando == 'a') { rele1_OFF(); }
    // Atrás
    else if (comando == 'B') { rele2_ON(); }
    else if (comando == 'b') { rele2_OFF(); }
    // Izquierda
    else if (comando == 'C') { rele3_ON(); }
    else if (comando == 'c') { rele3_OFF(); }
    // Derecha
    else if (comando == 'D') { rele4_ON(); }
    else if (comando == 'd') { rele4_OFF(); }

    // =============== ACCESORIOS / LUCES (Botones Toggle) ===============
    // Mas
    else if (comando == 'E') { rele5_ON(); }
    else if (comando == 'e') { rele5_OFF(); }
    // Menos
    else if (comando == 'F') { rele6_ON(); }
    else if (comando == 'f') { rele6_OFF(); }
    // SW1
    else if (comando == 'G') { rele7_ON(); }
    else if (comando == 'g') { rele7_OFF(); }
    // SW2
    else if (comando == 'H') { rele8_ON(); }
    else if (comando == 'h') { rele8_OFF(); }
    // SW3
    else if (comando == 'I') { rele9_ON(); }
    else if (comando == 'i') { rele9_OFF(); }
    // SW4
    else if (comando == 'J') { rele10_ON(); }
    else if (comando == 'j') { rele10_OFF(); }
    // SW5
    else if (comando == 'K') { rele11_ON(); }
    else if (comando == 'k') { rele11_OFF(); }
    // SW6
    else if (comando == 'L') { rele12_ON(); }
    else if (comando == 'l') { rele12_OFF(); }

    // =============== EMERGENCIA ===============
    else if (comando == 'X') {
      apagarTodo();
    }
  }
}

// ==============================================================================
// FUNCIÓN BASE: Controla un relé específico
// ==============================================================================
void controlarRele(int id, bool estado) {
  int indice = id - 1; 
  if (indice >= 0 && indice < 12) {
    digitalWrite(pinesRelevadores[indice], estado ? LOW : HIGH);
  }
}

// Función de EMERGENCIA
void apagarTodo() {
  for (int i = 1; i <= 12; i++) {
    controlarRele(i, false);
  }
  Serial.println("EMERGENCIA: Todo apagado");
}

// ==============================================================================
// FUNCIONES INDIVIDUALES 
// ==============================================================================
void rele1_ON() { controlarRele(1, true); }
void rele1_OFF() { controlarRele(1, false); }
void rele2_ON() { controlarRele(2, true); }
void rele2_OFF() { controlarRele(2, false); }
void rele3_ON() { controlarRele(3, true); }
void rele3_OFF() { controlarRele(3, false); }
void rele4_ON() { controlarRele(4, true); }
void rele4_OFF() { controlarRele(4, false); }
void rele5_ON() { controlarRele(5, true); }
void rele5_OFF() { controlarRele(5, false); }
void rele6_ON() { controlarRele(6, true); }
void rele6_OFF() { controlarRele(6, false); }
void rele7_ON() { controlarRele(7, true); }
void rele7_OFF() { controlarRele(7, false); }
void rele8_ON() { controlarRele(8, true); }
void rele8_OFF() { controlarRele(8, false); }
void rele9_ON() { controlarRele(9, true); }
void rele9_OFF() { controlarRele(9, false); }
void rele10_ON() { controlarRele(10, true); }
void rele10_OFF() { controlarRele(10, false); }
void rele11_ON() { controlarRele(11, true); }
void rele11_OFF() { controlarRele(11, false); }
void rele12_ON() { controlarRele(12, true); }
void rele12_OFF() { controlarRele(12, false); }
