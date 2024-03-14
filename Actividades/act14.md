# 1

Cuatro personas están sentados en una mesa jugando dominó, se van turnando para tirar una ficha o
pasar si no pueden jugar en el sentido contrario a las manecillas del reloj. Usando pseudocódigo
(no es necesario el código para correr en Linux) Represente a los cuatro jugadores con procesos desde 
P(0) hasta P(3) y como sincronizarían los turnos usando un arreglo de semáforos.


```
Jugador(i)
{
    while(true)
    {
        next = (i+1) % 4;
        wait(semaforo[i]);
        // CS: paso o juego
        signal(semaforo[next]);
    }
}

main()
{
        createsemarray(semaforos, 4);
        semaforos = {1,0,0,0}
        cobegin {
                Jugador(0);Jugador(1);Jugador(2);Jugador(3);
        }
}
```

tambien ver [hoja de calculo](https://docs.google.com/spreadsheets/d/1VWgsjUQPmHv8Ew2UKjnUjnXw3F0e4_rD2J4iYs_DuKM/edit#gid=0)


## 2

Considere el ejemplo del productor consumidor que se muestra a continuación

```
#define TAM_BUFFER 10
Semaphore s = 1;
Semaphore n = 0;
Semaphore e = TAM_BUFFER;

productor()
{
    while(TRUE)
    {
        producir();
        wait(e);
        wait(s);
        añadir();
        signal(s);
        signal(n);
    }
}

consumidor()
{
    while(TRUE)
    {
        wait(n);
        wait(s);
        tomar();
        signal(s);
        signal(e);
        consumir();
    }
}

main() {
    cobegin {
        productor(); consumidor();
    }
}
```

¿Cambiaría el significado del programa si se intercambian las siguientes sentencias?

1. `wait(e); wait(s)`
2. `signal(s); signal(n)`
3. `wait(n); wait(s)`
4. `signal(s); signal(e)`

## 2.1  'wait(e); wait(s)'

Recordemos que el semaforo `e` nos permitira operar en un buffer finito de manera correcta y el
semaforo `s` nos permitira acceder a la seccion critica con exclusion mutua.

Supongamos el siguiente caso donde `e=0`, indicando que no hay elementos disponibles dentro
del buffer para producir donde en este caso el productor se detiene **dentro** de una seccion critica
y nunca sale de ella ya que esta esperando que el consumidor tome y libere (signal) dicho elemento
pero para esto requiere tomar control de la seccion critica, el cual ya esta siempre ocupada.

```
#define TAM_BUFFER 10
Semaphore s = 1;
Semaphore n = 0;
Semaphore e = TAM_BUFFER;

productor()
{
    while(TRUE)
    {
        producir();
        wait(s);
        wait(e);
        añadir();
        signal(s);
        signal(n);
    }
}

consumidor()
{
    while(TRUE)
    {
        wait(n);
        wait(s);
        tomar();
        signal(s);
        signal(e);
        consumir();
    }
}
```

## 2.2 `signal(s); signal(n)`

Recordemos que el semaforo `s` nos ayuda a tener exclusion mutua en seccion critica y `n` nos sirve para que el
consumidor siempre espere al productor antes de tomar el elemento..

En este caso el consumidor podria iniciar su trabajo sin embargo el productor aun no ha terminado ya que
aun necesita liberar su seccion critica, sin embargo no es evidente que haya algun problema.


```
#define TAM_BUFFER 10
Semaphore s = 1;
Semaphore n = 0;
Semaphore e = TAM_BUFFER;

productor()
{
    while(TRUE)
    {
        producir();
        wait(e);
        wait(s);
        añadir();
-       signal(n);
-       signal(s);
    }
}

consumidor()
{
    while(TRUE)
    {
        wait(n);
        wait(s);
        tomar();
        signal(s);
        signal(e);
        consumir();
    }
}
```

## 2.3 `wait(n); wait(s)`

Supongamos que nuestro planificar elige `consumidor` como como primer proceso de ejecucion,
por ende tomara el semaforo de la seccion critica y ademas quedara bloqueado al momento
de llamar `wait(n=0)` y por ende el productor no podra anadir un elemento al buffer ya que este
require el semaforo `s` para su entrada a la seccion critica.

```
#define TAM_BUFFER 10
Semaphore s = 1;
Semaphore n = 0;
Semaphore e = TAM_BUFFER;

productor()
{
    while(TRUE)
    {
        producir();
        wait(e);
        wait(s);
        añadir();
        signal(s);
        signal(n);
    }
}

consumidor()
{
    while(TRUE)
    {
-       wait(s);
-       wait(n);
        tomar();
        signal(s);
        signal(e);
        consumir();
    }
}

main() {
    cobegin {
        productor(); consumidor();
    }
}
```

## 2.4 `signal(s); signal(e)`

Al igual que 2.2, aqui podria suceder que productor arranque poco antes de que el consumidor termine,
sin embargo no es evidente que algun problema ocurra.


```
#define TAM_BUFFER 10
Semaphore s = 1;
Semaphore n = 0;
Semaphore e = TAM_BUFFER;

productor()
{
    while(TRUE)
    {
        producir();
        wait(e);
        wait(s);
        añadir();
        signal(s);
        signal(n);
    }
}

consumidor()
{
    while(TRUE)
    {
        wait(n);
        wait(s);
        tomar();
-       signal(e);
-       signal(s);
        consumir();
    }
}

main() {
    cobegin {
        productor(); consumidor();
    }
}
```


## 3

De ser posible implementar semáforos generales por medio de semáforos binarios. Se pueden usar
las operaciones WaitB y SignalB y dos semáforos binarios espera y exmut. Considere lo siguiente:

```
struct strsemáforo {
     int contador;
     BinSemaphore espera=0;
};


typedef struct strsemáforo * semáforo;
BinSemaphore exmut=1;

void Wait(semáforo s)
{
   WaitB(exmut);
   s->contador--;
-  if(s->contador<0)
   {
        SignalB(exmut);
        WaitB(s->espera);
   }
-  SignalB(exmut);
}

void Signal(semáforo s)
{
   WaitB(exmut);
   s->contador++;
-  if(s->contador<=0)
      SignalB(s->espera);
   SinalB(exmut);
}
```
