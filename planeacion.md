# Planeacion

## Lunes

- Presentacion del Profesor
  - Indicar experiencia
- Presentacion del alumno
  - Lenguajes de Programacion?
  - SO utilizados?
  - Experiencia laboral

- Canvas
  - Difundir guía de aprendizaje
  - Materiales de la clase
  - Tareas, y las entregas de las tareas a través de la plataforma
  - Explicar que cada clase, el alumno tendra que ver videos y con este se podra
    resolver tanto las evaluaciones previas a clase como las actividades

- Planificación del curso
  ▪ 25 sesiones efectivas
  o 16 semanas x 2 sesiones = 32 sesiones
  o -1 Sesión de arranque muy importante explicar la guía de aprendizaje, reglas del
  juego
  o 3 sesiones de exámenes parciales
  o 3 días festivos o antes de cada examen una sesión de repaso y dudas

- Retroalimentación y calificaciones
  ▪ Mantener al día en Canvas las calificaciones de los alumnos, no publicar calificaciones del
  grupo a todo el grupo
  ▪ Tener calificado todo lo que sea posible antes que finalice la semana 12. La semana 12 es
  la semana de bajas de materias
  ▪ A partir de la semana 13 procurar que los alumnos participen en el IAE (Instrumento de
    Apreciación Estudiantil)

- Asesorías
  ▪ Acordar un horario de asesoría con los alumnos, horarios en los que se les puede brindar
  atención a las dudas.
  
- Creacion de grupos, 2 max

- 3 fuentes de informacion:
  - videos del mtro. Elvira
    Se tendran que ver previo a la sesion
  - slides del mtro. Elvira
    Si los videos no quedan claros, esta es una buena fuente.
    NOTA: hay pequenas diferencias entre   videos y slides
  - slides del libro OSC
    estos slides nos complementaran y ayudaran a entender conceptos.
    No es necesario que los lean, el mtro. solo les mostrara aquello revelante

- NOTA NOTA:
  - Es mucho material, son muchas activades, son muchos previos de examen.

- Maquina virtual mostrarles el resultado
  no la requeriremos esta semana pero el proximo lunes se revisara status

## S01 Miercoles

Esta sera una clase mas teorica que practica, pero es muy imporante por sus conceptos

formacion de grupos

Actividad grupal:
- revision maquina virtual (mostrar mi maquina)

Actividad por grupos individuales:
    - multiprogramacion versus monoprogramacion:

    1. mencione un problema de computo en el cual se puede atacar mejor con multiprogramacion
    2. habra problemas que no se puedan paralelizar? mencionar ejemplos si los hay
    3. https://en.wikipedia.org/wiki/Amdahl%27s_law

Slides SOC:
    - 1.5
    - 1.6
    - 1.7
    - 1.10
    - 1.24
    - 1.26
    - 1.27
    - 1.29
    - 1.32
    - 1.34
    - 1.46
    - 1.47
    - 1.48
    - 1.52
    - 1.53
    - 1.57
    - 1.68
    - 1.69
    - 2.7
    - 2.8
    - 2.9 (demo it on the VM)
    
Preguntas Generales:
- Proteccion del hardware
    - Para que queremos proteger al HW?
    - Para que tenemos modos de operacion?
      - NOTA: al modo supervisor generalmente se llama en ingles 'kernel mode'
    - que son las llamadas al sistema (system calls)?
    - cuales son los metodos para pasar parametros desde el modo usuario al modo supervisor?



## SO2 Lunes

De nuevo, una clase mas teorica que practica

- Revision status de maquina virtual (10 min)
  - solucion de dudas
  - la siguiente clase, ya la usaremos

- Actividad por grupos individuales (10min)

    - buscar en mi SO (windows, MacOS) la aplicacion de monitoreo de procesos y tratar de enteder las columnas que se presentan
    - dar algunos ejemplos de procesos que
      - gasten mucho tiempo en E/S
      - gasten mucho tiempo en el CPU
      - gasten mucho tiempo en tanto en CPU como en E/S
    - cuantos procesadores tiene mi sistema de computo?
    - cuantos cores hay en cada procesador?

- Book 'Structured Parallel Programming: Patters for efficient Computation' (20 min)

    - Think Parallel
    Figure 1.1
    Figure 1.2
    Figure 1.3 (Moore Law)
    Figure 1.4
    Figure 1.5
    Fig. 1.6
    Fig. 1.7

- Comenzar Actividad 2 (lo que le reste a la clase)

- opcional: Slides SOC
  3.4
  3.5
  3.6
  3.7  


## S03 Miercoles

- Revision status de maquina virtual (5 min)

- Revision de Slides (30 min)
  - desde la maquina virtual, obtener documentacion de la llamada de sistema fork
    - man fork
    - info fork
  - ejecutar el comando pstree (si no esta, instalarlo con apt)

- instalar git

- desde la maquina virtual, clonar repositorio
  https://github.com/lsandov1/P2024_ESI3126N
- pequena intro a git
- recomendar su uso
- compilar algunos de los programas de procesos

## S04 Lunes

1. Revision de slides

2. Actividades en clase

  2.1 IPC: Signals: en el tema de senales, generar un programa que solo duerma  y usar el commando kill para terminaro

  2.2 Revisar el programa P2024_ESI3126N/1.-Procesos/mem_compartida_ejemplo.c y compilarlo
    - Semaforos: indicar su uso en el caso de memoria compartida

3. Introducion a la herramienta make
   3.1 pedir a los alumnos que realizen un Makefile el cual compile todos los programas de procesos


## S05 Miercoles

0. Usaremos Google Meet ya que la licencia de Zoom no se resuelve

1. Revision de Actividad 3 por equipo (5 min max por equipo)
   1.1 preparar su maquina virtual, el grupo que la tenga lista
   le mando un meet y revisamos en grupo
   
1. Revision de Actividad 4

2. Revision de Slides Hilos 1/2

## S0X

Dia feriado

## S06 Miercoles

1. Proponer pequenos cambios en las actividades 3 y 4, dar 1hr
   3.1
   - que pasa si quitamos las llamadas a sleep()? y ademas aumentamos las iteraciones?
   3.2
   - que pasa si quitamos el el brinco de linea en la funcion que imprime a pantalla? 
   3.3
   - utilizar la llamada execl en vez de system (tip: ver man system)
   4.1
   - ahora hacer lo mismo que el un proceso nieto termine tanto al padre como al abuelo
   4.2
   - sin cambios
   4.3
   - sin cambios
   4.4
   - sin cambios
   A
2. Cada equipo nos mostrara su solucion
3. Revision de slides

