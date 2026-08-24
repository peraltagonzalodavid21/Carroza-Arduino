## Bienvenida:
Buenasss, no se quien este leyendo esto, pero mientras voy comentando como esta planteado esto, en este repositorio se encuentra todo el codigo de la carroza, un poco de los diagramas para usar de referencia, ademas de intrucciones para poner a punto la placa y algunos consejos que pueden ser utiles al momento de armarla. Ademas del MIT app inventor para programar la app. Tambien voy a dejar las capturas y el archivo de kicad para futuras mejoras que voy a comentar al final.

## Creditos:

Aca aunque ya me conozcan dejo mi nombre y promo por si este repo se sigue utilizando:

Alumno: Peralta Gonzalo David
Promo: 2025
Colegio: E.P.E.T N°12
Año: 2026

## Hardware del Proyecto

El sistema de control funciona con los siguientes componentes:
* Microcontrolador: Arduino Nano (se utilizan todos los pines digitales del D2 al D13, 12 salidas en total).
* Módulo Bluetooth: HC-05 (para la conexión con la aplicación).
* Drivers de Potencia: ULN2003 para el manejo seguro de los relés.
* Actuadores: 12 Relés de 5V (4 para movimiento, 8 para accesorios/luces).
* Alimentación: Módulo Step-down LM2596 (Regula de 12V a 5V para alimentar la lógica).

## Diagrama de Pines (Pinout) y Mapeo Bluetooth

Es fundamental conectar los pines correctamente según la siguiente tabla:

| Relé / Función | Pin en Arduino | Tipo de Botón en App | Letra ON | Letra OFF |
|----------------|----------------|----------------------|----------|-----------|
| Relé 1 (Adelante) | D2 | Momentáneo | A | a |
| Relé 2 (Atrás) | D3 | Momentáneo | B | b |
| Relé 3 (Izquierda)| D4 | Momentáneo | C | c |
| Relé 4 (Derecha) | D5 | Momentáneo | D | d |
| Relé 5 (Mas)| D6 | Momentáneo | E | e |
| Relé 6 (Menos)| D7 | Momentáneo | F | f |
| Relé 7 (Accesorio 1)| D8 | Toggle (Interruptor) | G | g |
| Relé 8 (Accesorio 2)| D9 | Toggle (Interruptor) | H | h |
| Relé 9 (Accesorio 3)| D10 | Toggle (Interruptor) | I | i |
| Relé 10 (Accesorio 4)| D11 | Toggle (Interruptor) | J | j |
| Relé 11 (Accesorio 5)| D12 | Toggle (Interruptor) | K | k |
| Relé 12 (Accesorio 6)| D13 | Toggle (Interruptor) | L | l |
| EMERGENCIA (STOP) | N/A | Botón de Pánico | X | N/A |

Nota sobre el funcionamiento de los botones:
- Momentáneo: La acción se ejecuta solo mientras se mantiene presionado el botón en la aplicación.
- Toggle: Funciona como un interruptor estándar. Se presiona una vez para encender y otra para apagar.

## Guía de Instalación (5 Pasos)

Para poner en marcha el control de la carroza, seguir estos pasos:

1. Paso 1 - Cargar el código:
   Descargar el código Arduino desde este repositorio, abrirlo en el IDE y cargarlo al Arduino Nano (asegurarse de configurar el puerto y el tipo de placa correctos).
2. Paso 2 - Conectar los módulos:
   Conectar el módulo HC-05 (TX a RX y RX a TX del Arduino), el regulador LM2596 (ajustado a 5V) y el ULN2003 a los pines de los relés según la tabla anterior.
3. Paso 3 - Descargar la app:
   Descargar la aplicación desde el repositorio (archivo .aia) o importarla desde el enlace compartido de MIT App Inventor.
4. Paso 4 - Instalar y vincular:
   Instalar la aplicación en el dispositivo Android y vincular el módulo HC-05 mediante Bluetooth desde los ajustes del sistema.
5. Paso 5 - Probar la seguridad:
   Abrir la aplicación, conectar el Bluetooth y probar inmediatamente el botón de STOP (EMERGENCIA) para verificar que todos los relés se apagan correctamente.

## Cómo agregar un nuevo relé en 1 minuto

Si en el futuro es necesario agregar más funcionalidades, el procedimiento es el siguiente:

1. Ir al código Arduino, copiar una función rele13_ON() y su correspondiente OFF, pegarla y cambiarle el número.
2. Agregar un nuevo else if en la sección del loop() para capturar la nueva letra (por ejemplo, 'M' y 'm').
3. Actualizar el array de pines al inicio del código, si corresponde.
4. En la aplicación (MIT App Inventor), copiar un interruptor (switch) existente, cambiarle el nombre y configurarlo para que envíe las nuevas letras ('M' y 'm').

## Carpetas del repo
/Codigo_Arduino → Archivo .ino con el programa principal.

/App_MIT_Inventor → Archivo .aia de la app, Si se abre el mit app inventor pueden modificar la app.

/PCB_KiCad → Archivos del esquemático y diseño de la PCB, Si se abre el KiCad pueden modificar la PCB.

/Docs → Imágenes, diagramas, fotos de la carroza, etc. Aca tambien ya dejo un par de capturas de la carroza.

## Galería

Se recomienda agregar fotos de la PCB, los circuitos, el chasis y la carroza terminada en la carpeta /Docs como registro visual del trabajo. (Creen una carpeta con el año y fotos de la carroza, placa, etc). 

## Cierre
Bueno aca ya dejo el cierre, no se quien lea esto pero espero que el proyecto siga avanzando y mejoren, como un esp32 con mas pines y bluetooth integrado, ya que es el proximo paso, o que la carroza no se mueva sola pero tenga un show de luces o algo mas elaborado, como un sistema que se prenda solo cuando tenga musica fuerte, no se, depende de la creatividad de cada uno. 

Mientras tanto los dejo tranquilos, yo voy a ver si la facu no me mata, saludos.

-Peralta Gonzalo David. 
