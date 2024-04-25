Resolver los siguientes ejercicios y subir un archivo PDF con las respuestas.

1.- Considera un sistema donde hay 100 marcos de memoria disponibles cuyo tamaño de es 4 Kbytes. En este sistema se ejecutarán 5 procesos de estos tamaños:

    Proceso 1 mide 150 Kbytes
    Proceso 2 mide 230 Kbytes
    Proceso 3 mide 60 Kbytes
    Proceso 4 mide 80 Kbytes
    Proceso 5 mide 120 Kbytes

Considerando una asignación proporcional de marcos, indica cuántos marcos le corresponde a cada uno de los procesos.

```
150/4*x +230/4*x + 60/4*x + 80/4*x +120/4*x = 100

(150/4 +230/4 + 60/4 + 80/4 +120/4)x = 100

(150 230 60 80 120)x = 400

Factor de Proporcion x

x = 400 / 640 = 0.625
```

| Proceso | Tamano | # Marcos totales | # Marcos en memoria (totales * x) |
|---------|--------|------------------|-----------------------------------|
| 1       | 150    | 37.5             | 23.43                              |
| 2       | 230    | 57.5             | 35.93                             |
| 3       | 60     | 15               | 9.37                              |
| 4       | 80     | 20               | 12.5                              |
| 5       | 120    | 30               | 18.75                             |
 

2.- Considera que tenemos un proceso que en la secuencia que se muestra a continuación realiza accesos a memoria a las direcciones que se indican:

    Accede a la dirección 0FBA
    Accede a la dirección 80FE
    Accede a la dirección 5187
    Accede a la dirección D400
    Accede a la dirección 0100
    Accede a la dirección 8000
    Accede a la dirección 6F00
    Accede a la dirección E900
    Accede a la dirección D600
    Accede a la dirección 08FF

a) Si el tamaño de las páginas y marcos es 4 Kb, y para este proceso el SO le hace una asignación de 8 marcos para su ejecución, indica cuántos fallos de página se generarán durante la ejecución del proceso y cómo quedará la tabla de páginas al final de la ejecución, indica en la tabla de páginas con el bit de presente qué páginas quedan asignadas en marcos de memoria principal y qué páginas no quedarán en memoria principal. 

https://docs.google.com/spreadsheets/d/18-l_a6mUSlItmELcWr974Kbgnq1jaB6Xg1sreUJe4dg/edit?usp=sharing

- Cuantos Fallos de Pagina? 6
- tabla de paginas


b) Si el tamaño de las páginas y marcos es 16 Kb, y para este proceso el SO le hace una asignación de 2 marcos para su ejecución, indica cuántos fallos de página se generarán durante la ejecución del proceso y cómo quedará la tabla de páginas al final de la ejecución, indica en la tabla de páginas con el bit de presente qué páginas quedan asignadas en marcos de memoria principal y qué páginas no quedarán en memoria principal.

https://docs.google.com/spreadsheets/d/18-l_a6mUSlItmELcWr974Kbgnq1jaB6Xg1sreUJe4dg/edit?usp=sharing

- Cuantos fallos de pagina? 7

3.- ¿Qué aprendiste?
