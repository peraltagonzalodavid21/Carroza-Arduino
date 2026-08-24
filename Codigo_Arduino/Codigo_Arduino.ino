// ==============================================================================
// PROYECTO: Control de Carroza - Semana de la Estudiantina
// AUTOR: David y el equipo técnico
// HARDWARE: Arduino Nano, HC-05 (Bluetooth), ULN2003, Módulo de 12 Relés
// ==============================================================================

// Array con los pines digitales usados para los 12 relés (D2 a D13)
// IMPORTANTE: El índice del array empieza en 0.
// pinesRelevadores[0] corresponde al Relé 1 (Pin 2).
int pinesRelevadores[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  // Iniciamos la comunicación serial para el Bluetooth a 9600 baudios
  Serial.begin(9600);

  // Configuramos todos los pines de los relés como SALIDA y los apagamos
  for (int i = 0; i < 12; i++) {
    pinMode(pinesRelevadores[i], OUTPUT);

    // Suponiendo lógica inversa para los módulos de relés comunes (HIGH =
    // apagado). Cambiar a LOW si el módulo de relés usa lógica directa.
    digitalWrite(pinesRelevadores[i], HIGH);
  }
}

void loop() {
  // Comprobamos si nos llega algún comando desde la App (Bluetooth)
  if (Serial.available() > 0) {
    char comando = Serial.read();

    // =============== MOVIMIENTO (Botones Momentáneos) ===============
    // Adelante
    if (comando == 'A') {
      rele1_ON();
    } else if (comando == 'a') {
      rele1_OFF();
    }
    // Atrás
    else if (comando == 'B') {
      rele2_ON();
    } else if (comando == 'b') {
      rele2_OFF();
    }
    // Izquierda
    else if (comando == 'C') {
      rele3_ON();
    } else if (comando == 'c') {
      rele3_OFF();
    }
    // Derecha
    else if (comando == 'D') {
      rele4_ON();
    } else if (comando == 'd') {
      rele4_OFF();
    }

    // =============== ACCESORIOS / LUCES (Botones Toggle) ===============
    // Mas
    else if (comando == 'E') {
      rele5_ON();
    } else if (comando == 'e') {
      rele5_OFF();
    }
    // Menos
    else if (comando == 'F') {
      rele6_ON();
    } else if (comando == 'f') {
      rele6_OFF();
    }
    // SW1
    else if (comando == 'G') {
      rele7_ON();
    } else if (comando == 'g') {
      rele7_OFF();
    }
    // SW2
    else if (comando == 'H') {
      rele8_ON();
    } else if (comando == 'h') {
      rele8_OFF();
    }
    // SW3
    else if (comando == 'I') {
      rele9_ON();
    } else if (comando == 'i') {
      rele9_OFF();
    }
    // SW4
    else if (comando == 'J') {
      rele10_ON();
    } else if (comando == 'j') {
      rele10_OFF();
    }
    // SW5
    else if (comando == 'K') {
      rele11_ON();
    } else if (comando == 'k') {
      rele11_OFF();
    }
    // SW6
    else if (comando == 'L') {
      rele12_ON();
    } else if (comando == 'l') {
      rele12_OFF();
    }

    // =============== EMERGENCIA ===============
    else if (comando == 'X') {
      apagarTodo();
    }
  }
}

// ==============================================================================
// FUNCIÓN BASE: Controla un relé específico
// id: Número del relé (1 a 12)
// estado: true (ON), false (OFF)
// ==============================================================================
void controlarRele(int id, bool estado) {
  int indice = id - 1; // Ajustamos al índice del array (Relé 1 -> Índice 0)
  if (indice >= 0 && indice < 12) {
    // Si el módulo de relés se activa con LOW, usamos lógica inversa (estado ?
    // LOW : HIGH) Si se activa con HIGH, cambia esto a:
    // digitalWrite(pinesRelevadores[indice], estado ? HIGH : LOW);
    digitalWrite(pinesRelevadores[indice], estado ? LOW : HIGH);
  }
}

// Función de EMERGENCIA: ¡Apaga todo de un solo golpe!
void apagarTodo() {
  for (int i = 1; i <= 12; i++) {
    controlarRele(i, false);
  }
  Serial.println("EMERGENCIA: Todo apagado");
}

// ==============================================================================
// FUNCIONES INDIVIDUALES (Para que los pibes solo copien y peguen)
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

// ==============================================================================
// SI QUIERES AGREGAR EL RELÉ 13, COPIA UNA FUNCIÓN DE ARRIBA,
// PÉGALA AQUÍ ABAJO Y CAMBIA EL NÚMERO (Ejemplo: rele13_ON, controlarRele(13,
// true)). ¡No te olvides de agregar el nuevo pin en el array 'pinesRelevadores'
// al principio y su correspondiente 'else if' en el loop()!
// ==============================================================================
