# INFORME TÉCNICO – CONTROL DE CARROZA ESTUDIANTINA

**Versión:** [2026]  
**Autor:** Adriel Nicolás Balbuena 
**Institución:** E.P.E.T N°12
**Fecha de emisión:** [24/08/26]  

---

## 1. OBJETIVO DEL PROYECTO

Desarrollar un sistema de control inalámbrico para la carroza de la Semana de la Estudiantina, que permita manejar los motores de desplazamiento y los accesorios (luces, bocinas, etc.) desde un dispositivo Android, reemplazando los engorrosos sistemas de cableado tradicionales y brindando seguridad y facilidad de operación a los estudiantes.

---

## 2. DESCRIPCIÓN DEL SISTEMA

### 2.1. Hardware utilizado
- **Microcontrolador:** Arduino Nano (ATmega328P).
- **Módulo Bluetooth:** HC-05 (esclavo).
- **Driver de relés:** [Especificar según año, ej: Transistores + optoacopladores / ULN2003].
- **Relés:** [Especificar voltaje y cantidad, ej: 12 relés de 12V].
- **Fuente de alimentación:** [Especificar, ej: LM2596 step-down (12V a 5V)].
- **PCB:** [Especificar, ej: Placa perforada / PCB personalizada con planchado].

### 2.2. Software utilizado
- **IDE de programación:** Arduino IDE (versión [indicar]).
- **Entorno de desarrollo de la app:** MIT App Inventor 2.
- **Diseño de PCB:** KiCad (versión [indicar]).
- **Lenguajes:** C++ (Arduino) / Bloques visuales (MIT App Inventor).

---

## 3. CRONOGRAMA E HITOS

| Fecha | Hito / Actividad |
| :--- | :--- |
| [DD/MM] | [Descripción de la actividad, ej: Inicio del desarrollo del código] |
| [DD/MM] | [Descripción, ej: Primeras pruebas en protoboard] |
| [DD/MM] | [Descripción, ej: Fabricación de la PCB] |
| [DD/MM] | [Descripción, ej: Armado final y pruebas en carroza] |
| 25/08 | Desoldar HC-05|
| 25/08 | Conseguir cable de mando de PS3 |
*(Completar con las fechas reales del año correspondiente)*

---

## 4. MEJORAS Y CAMBIOS RESPECTO AL AÑO ANTERIOR

*(Si es la primera versión, aclarar que es el prototipo inicial)*

- [Mejora 1, ej: Se eliminaron los optoacopladores y se utilizó un ULN2003 para simplificar el circuito].
- [Mejora 2, ej: Se diseñó una PCB con método de planchado, reemplazando la placa perforada].
- [Mejora 3, ej: Se añadieron borneras para facilitar el cableado en la carroza].

---

## 5. INCIDENCIAS Y SOLUCIONES APLICADAS

| Problema encontrado | Solución implementada |
| :--- | :--- |
| [Ej: Se quemó un ULN2003 por inversión de polaridad] | [Ej: Se reemplazó el integrado y se agregó un diodo de protección en el esquemático] |
| [Ej: Contacto de bornera flojo en la carroza] | [Ej: Se ajustaron los tornillos y se verificó el apriete de todas las conexiones] |

---

## 6. CONCLUSIONES Y SUGERENCIAS PARA PRÓXIMAS VERSIONES

- **Conclusión general:** El sistema funcionó correctamente durante el evento, cumpliendo con los requisitos de manejo y seguridad.
- **Sugerencia 1:** Agregar un botón físico de emergencia en el tablero (independiente de la app).
- **Sugerencia 2:** Considerar reemplazar el HC-05 por un módulo BLE (HM-10) para compatibilidad con iOS.
- **Sugerencia 3:** Diseñar una carcasa protectora (impresión 3D) para la PCB.
- **Sugerencia 4:** Ampliar el número de relés si se agregan más accesorios (actualmente 12, se puede extender usando un multiplexor o cambiando de microcontrolador).

---

## 7. ANEXOS

- Código fuente (Arduino): disponible en `/Codigo_Arduino` del repositorio.
- App (MIT App Inventor): disponible en `/App_MIT_Inventor` y enlace de proyecto compartido.
- Esquemático y PCB (KiCad): disponibles en `/PCB_KiCad`.
- Fotos y diagramas: disponibles en `/Docs/imagenes`.

---

**Nota:** Este informe es un registro histórico del proyecto. Está sujeto a modificaciones y actualizaciones según los requerimientos de cada año, los avances tecnológicos y las lecciones aprendidas durante la puesta en marcha.

---
*“La técnica es el puente entre la idea y la realidad.”*
