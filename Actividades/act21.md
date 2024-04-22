1. Considerando que tengo un sistema de cómputo donde hay memoria física de 32 Kb dividida 
en 8 marcos de 4096 bytes, se tiene un espacio de intercambio del doble de la memoria física. 
En este sistema se ejecutarán 2 procesos de 32 Kb.

Basándose en la asignación de marcos fija considerando que a cada proceso se le asignan 4 marcos físicos
y usamos un alcance de reemplazo local, donde se emplea el algoritmo de reemplazo LRU. 
Considere la secuencia de eventos donde los procesos acceden las siguientes direcciones lógicas:

    Proceso A accede la dirección 0x035A
    Proceso B accede la dirección 0x6001
    Proceso B accede la dirección 0x5000
    Proceso A accede la dirección 0x106F
    Proceso A accede la dirección 0x235A
    Proceso B accede la dirección 0x4FFF
    Proceso B accede la dirección 0x3000
    Proceso A accede la dirección 0x306F
    Proceso B accede la dirección 0x2000
    Proceso A accede la dirección 0x406F
    Proceso A accede la dirección 0x535A
    Proceso B accede la dirección 0x1FFF
    Proceso A accede la dirección 0x635A
    Proceso B accede la dirección 0x0FFF
    Proceso A accede la dirección 0x735A
    Proceso B accede la dirección 0x7FFF

    Muestra con un dibujo  como queda la memoria física y los marcos virtuales.


    Indique cómo quedan las tablas de páginas, incluya el bit de presente.

https://docs.google.com/spreadsheets/d/1vN6-MT-JREgXwRc5FnNwQQhn3KohfVaKhKBJk529duU/edit?usp=sharing
