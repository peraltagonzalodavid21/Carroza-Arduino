# Informe del Proyecto – Control de Carroza Estudiantina

**Autor:** Peralta Gonzalo David (Promo 2025)  
**Última actualización:** Agosto 2026  
**Estado:** Funcional / En mantenimiento

---

## 1. Resumen del proyecto

Sistema de control inalámbrico para la carroza de la Semana de la Estudiantina, basado en Arduino Nano y Bluetooth (HC-05). Permite activar 12 relés (4 para motores de desplazamiento y 8 para accesorios) desde una app Android desarrollada en MIT App Inventor. El proyecto fue evolucionando desde prototipos en placa perforada hasta una PCB personalizada con planchado.

---

## 2. Línea de tiempo y versiones

### Versión 2024 (Prototipo inicial)

| Fecha | Hito |
| :--- | :--- |
| Mayo 2024 | Inicio del desarrollo – primer prototipo funcional en protoboard. |
| Julio 2024 | Montaje en placa perforada con relés de 5V, optoacopladores y transistores. |
| Septiembre 2024 | Pruebas en carroza con control básico (4 movimientos + luces). |
| Octubre 2024 | Presentación en la estudiantina (funcionó correctamente). |

**Hardware utilizado:**
- Arduino Nano
- HC-05
- Relés de 5V (con optoacopladores y transistores para manejo)
- PCB perforada (no diseñada, todo cableado manual)

**Aprendizajes y limitaciones:**
- Cableado manual difícil de mantener.
- Los optoacopladores agregaban complejidad innecesaria.
- No se realizó un diseño de PCB.

---

### Versión 2025 (PCB planchada y optimización)

| Fecha | Hito |
| :--- | :--- |
| 22 de mayo | Inicio del desarrollo de la app en MIT App Inventor. |
| 23 de junio | Pruebas funcionales completas en protoboard (código listo). |
| 5 de septiembre | PCB terminada con método de planchado (diseño en KiCad). |
| 8 de septiembre | Armado del tablero de control y cableado provisional. |
| 15 de septiembre | Instalación final en la carroza y pruebas de campo. |

**Mejoras implementadas respecto a 2024:**
- PCB personalizada (método de planchado) – reemplazo de placa perforada.
- Uso de ULN2003 (arrays de Darlingtons) para manejar relés de 12V, eliminando optoacopladores y transistores discretos.
- Alimentación estabilizada con LM2596 (step‑down de 12V a 5V).
- Borneras para facilitar conexiones.
- Esquemático eléctrico en KiCad.
- Se ocuparon todos los pines digitales (D2‑D13) para los 12 relés.

**¿Qué se rompió o falló?**
- Durante la instalación, se quemó un ULN2003 por inversión de polaridad en la alimentación (se reemplazó y se agregó un diodo de protección en el esquemático para futuras revisiones).

---

## 3. Estado actual del proyecto (2026)

- El código y la app funcionan correctamente.
- La PCB está en uso y no presenta fallas.
- El repositorio contiene:
  - Código Arduino (`.ino`).
  - App MIT App Inventor (`.aia`).
  - Archivos de KiCad (esquemático y PCB).
  - Fotos del armado y la carroza.

---

## 4. Sugerencias para futuras versiones

1. **Agregar un relé extra** (13 o más) ampliando el array de pines y las funciones en el código. Es tan sencillo como copiar/pegar una función existente.
2. **Implementar secuencias automáticas** (ej. luces intermitentes o coreografías) usando `millis()` sin bloquear el Bluetooth. Ya hay espacio en la app para agregar botones de "modo automático".
3. **Diseñar una carcasa 3D** para el tablero de control que proteja la PCB de la intemperie.
4. **Reemplazar el HC-05 por un módulo BLE** (como HM‑10) si se quiere compatibilidad con iPhones (el HC‑05 solo funciona bien en Android).
5. **Añadir un botón físico de emergencia** en el tablero (aparte del botón en la app) por si el celular se queda sin batería.

---

## 5. Agradecimientos y contacto

No se si posta van a leer todo esto por su bien espero que si, asi que nada mucha suerte con todo, un saludo al profe buja y el profe sanabria.

**Autor:** Peralta Gonzalo David – Técnico Electromecánico (Promo 2025).

---