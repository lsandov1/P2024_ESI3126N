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

## S07

1. Revision Actividad 2
2. Revision Actividad 5
3. Revision Actividad 6
   3.1 Revision de tiempos
   3.2 Revision de cambios (diff)
   3.3 Revision de desempen~o
     3.3.1 cual es el uso del CPU en cada caso? (/usr/bin/time)
     3.3.2 que sucede cuando tenemos mas hilos que cores?

## S08

(20 min)
1. POSIX Mutex 
  Revisar los siguientes dos videos
  1. https://www.youtube.com/watch?v=vxq7poCZyp8 
     condicion de carrera o condicion de concurso
     seccion critica con pthreads
  2. https://www.youtube.com/watch?v=OEhjG2JbLqg
  

(1hr)
2. De manera individual, realizar en clase el  ejercicio retador de la actividad 6 
   Para los equipos que hicieron el anterior ejercicio, intenar cuaquiera de
   https://chat.openai.com/c/a122b529-7495-4bfe-b4d2-2221bbc1f9dc

(10min)
3. https://chat.openai.com/c/a122b529-7495-4bfe-b4d2-2221bbc1f9dc

(15min)
4. Revision de Slides S07

?
5. Revision de Actividad SO7


## S09

1. Realizar el cuestionario de repaso examen 1
https://canvas.iteso.mx/courses/38111/quizzes/59843

2. Revisar actividad pasada, Taylor Series usando Pthreads

3. Revisar codigo fuente

    /home/lsandova/P2024_ESI3126N/1.-Procesos/mem_compartida_ejemplo.c

4. Arranque Practica 2

3. Revisar Practica 1

## Examn

1. Examen

2. Demo de Practica 1

## S10

1. Revision Practica 1 y 2


## S11

1. Revision de Actividad 8
2. Revision de Actividad 9
3. Revision de Actividad 10

## S12

1. Realizar la encuesta de medio termino
2. Revision Actividad 10 (ver solucion `act10.md` en github)
3. Revision de los algoritmos de Dekker y Peterson
4. Revision Actividad 11
5. Retos Previo a Practica 3. Elegir uno de estos retos, por cada problema resuelto, +5 extra en su practica 3 por cada ejercicio presentado, aun
   sin terminar del todo.
  1. En las soluciones de software para la solucion del problema de la concurrencia, en primer intento
     se comento que NO funcionaba. Explicar el porque.

  2. Utlizar cualquier solucion por Software o Hardware (SW=4 intento|Peterson|Dekker HW=test&set|xcgh) para el siguiente problema usando 2 hilos.
     +5 puntos extra en practica 3 por cada algoritmo, presentar codigo y pruebas al

```
int cuenta=0;

void total()
{
    int i;
    for(i=0;i<1000;i++)
       cuenta++;
}
```

Probarlo con

```
$ while true; do ./cuenta_peterson ; done | uniq
```



5 puntos extras en el siguiente examen al que lo resuelva correctamente.


## S13

1. Revision de Actividad de S12.

2. Breve intro a la optimizacion a traves del compilador
   revisar el man page de gcc y localizar los parametros -O<n>
   compilar la practica 1 y 2 con banderas de optimizacion y ver resultados de desempeno

3. Revisar brevemente el tema de los semaforos

3. Introduccion a los semaforos SysV, ver ejemplo /home/lsandova/P2024_ESI3126N/3.-Sincronizaciвn y comunicaciвn/Semаforos/semsejemplo1.c
   tomar en cuenta la libreria ver la libreria brevemente
   <!--  -->

4. Actividad. Usar chatgpt para generar un programa de semaforos de tipo sysv, entender el
programa y ejecutarlo.


## S14

1. Revision de la Actividad EN CLASE de S12

2. Revision de la Actividad S13

3. Revision de nueva cuenta de los semaforos SysV

4. Presentacion de la practica 3
   - En clase, revisar /home/lsandova/repos/iteso/P2024_ESI3126N/3.-Sincronizaciвn y comunicaciвn/Problemas de concurrencia/mercator_proc.c
   - Crear un Makefile que nos ayude a compilar `mercator_proc.c`
   - Revisar resultado
   - reve analisis del desepen~o del binario usando la herramienta `perf`

   ```
   sudo perf record ./mercator_proc
   sudo perf report
   Samples: 234K of event 'cpu_core/cycles/P', Event count (approx.): 246711056455
   Overhead  Command        Shared Object      Symbol
   74.33%  mercator_proc  mercator_proc      [.] get_member
   18.61%  mercator_proc  mercator_proc      [.] master_proc
    7.03%  mercator_proc  mercator_proc      [.] proc
  ```


## S15

1. Revision de actividad 14

2. Revision de avances de practica 3, por equipo

3. Monitores en Java
   mostrar ejemplos


## S16

Problemas de Concurrencia sesion 7


30 min preparacion / 30 min de presentacion
1. Cada equipo elegira la solucion con monitores en java, entedera, compilara y ejecutara dicha solucion.
   Dicho equipo explicara la solucion en clase e identificara lo siguiente
   1. cual es monitor?
   2. cuales son sus metodos?
   3. Si en Java ejecutas la sentencia notifyAll() se desbloquean todos los hilos que están bloqueados en la sentencia wait(), explica por qué solamente uno que es el siguiente jugador es el que continua.

2. Revision Actividad 15
3. Revision Practica 3
   1. soluciones con pseudocodigo
   2. revision los equipos que la hayan terminado

## S17

Problemas de Concurrencia sesion 8

1. Revision de 'paso de mensajes' con SysV, ver y ejecutar ejemplos dentro de P2024_ESI3126N/3.-Sincronizaciвn y comunicaciвn/Mensajes/.
3. Presentacion Practica 4

## S18

Interbloqueo

1. Repaso Parcial 2
