# Carroza-Estudiantina-Bluetooth 🚜🔧

¡Bienvenidos al repositorio oficial del sistema de control para la carroza de la Estudiantina!
Este proyecto fue diseñado para que sea súper fácil de usar, mantener y expandir. ¡A prueba de balas y de errores!

## 👥 Créditos
- **Creador Principal**: David
- **Equipo Técnico**: [Nombres del equipo técnico]

---

## 🛠️ Hardware Utilizado
- **Microcontrolador**: Arduino Nano (16MHz)
- **Comunicación**: Módulo Bluetooth HC-05
- **Driver de Potencia**: ULN2003 (o 2004)
- **Actuadores**: Módulo de 12 Relés de 12V
- **Alimentación**: Fuente Step-Down LM2596 (para bajar y estabilizar todo a 5V)

## 🔌 Diagrama de Conexiones (Pinout)
Conecten todo siguiendo estrictamente esta tabla. Hemos ocupado todos los pines digitales (D2 a D13).

| Relé (Función) | Pin en Arduino | Comando ON | Comando OFF |
|----------------|----------------|------------|-------------|
| Relé 1 (Adelante) | D2 | `A` | `a` |
| Relé 2 (Atrás) | D3 | `B` | `b` |
| Relé 3 (Izquierda) | D4 | `C` | `c` |
| Relé 4 (Derecha) | D5 | `D` | `d` |
| Relé 5 (Accesorio/Luz) | D6 | `E` | `e` |
| Relé 6 (Accesorio/Luz) | D7 | `F` | `f` |
| Relé 7 (Accesorio/Luz) | D8 | `G` | `g` |
| Relé 8 (Accesorio/Luz) | D9 | `H` | `h` |
| Relé 9 (Accesorio/Luz) | D10 | `I` | `i` |
| Relé 10 (Accesorio/Luz)| D11 | `J` | `j` |
| Relé 11 (Accesorio/Luz)| D12 | `K` | `k` |
| Relé 12 (Accesorio/Luz)| D13 | `L` | `l` |
| **EMERGENCIA** | N/A | **`X`** | N/A |

---

## 🚀 Guía Rápida (5 Pasos para Arrancar)
Si son nuevos y están a cargo de esto, sigan estos pasos al pie de la letra (¡no nos llamen llorando si no compila!):

1. **Revisa las Conexiones**: Asegúrate de que los pines del Arduino coincidan exactamente con la tabla de arriba. El módulo HC-05 debe estar conectado a TX/RX (recuerda cruzar TX con RX del módulo a la placa).
2. **Carga el Código**: Abre el archivo `Codigo_Arduino/Codigo_Arduino.ino` en el IDE de Arduino. Selecciona "Arduino Nano", el puerto COM correspondiente y dale a subir. *(NOTA: Desconecta el Bluetooth de los pines RX/TX del Arduino al subir el código, de lo contrario tirará error al compilar/subir).*
3. **Instala la App**: Pasa el archivo `.apk` (generado desde MIT App Inventor) a tu teléfono Android e instálalo.
4. **Vincula el Bluetooth**: Ve a los ajustes de Bluetooth de tu celular y empareja el módulo HC-05 (la contraseña suele ser `1234` o `0000`).
5. **A Mover la Carroza**: Abre la App, conéctate al módulo Bluetooth y ¡listo!

---

## ⚡ Cómo agregar un nuevo relé en 1 minuto
¿Necesitan agregar un relé extra (ej. usando un pin analógico como A0)? Solo tienen que seguir estos 3 pasos (¡es puro copiar y pegar!):

1. **Actualiza el Array**: Al principio del código de Arduino, busca la línea `int pinesRelevadores[]` y agrega tu nuevo pin al final (ej: cambiar `13` por `13, A0`).
2. **Copia las Funciones**: Ve hasta abajo del todo en el código de Arduino. Copia las dos funciones del relé 12, pégalas justo abajo, y cambiales el número:
   ```cpp
   // SI QUIERES AGREGAR EL RELÉ 13, COPIA UNA FUNCIÓN, PÉGALA AQUÍ Y CAMBIA EL NÚMERO
   void rele13_ON() { controlarRele(13, true); }
   void rele13_OFF() { controlarRele(13, false); }
   ```
3. **Agrega la Letra en el Loop**: Busca en el `loop()` la parte de los accesorios y agrega un nuevo `else if` con las letras que vayas a usar (ej: M mayúscula y m minúscula):
   ```cpp
   else if (comando == 'M') { rele13_ON(); }
   else if (comando == 'm') { rele13_OFF(); }
   ```
¡Listo! No rompan nada y disfruten la semana de la Estudiantina. 🎉
