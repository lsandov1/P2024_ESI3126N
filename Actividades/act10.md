# Problema 1

Considere un programa concurrente con dos procesos P y Q, definidos a continuación. A, B, C, D y E 
son sentencias arbitrarias atómicas (indivisibles). Supóngase que el programa principal (no mostrado) ejecuta
concurrentemente los procesos P y Q

P()
{
    A;
    B;
    C;
}
Q()
{
    D;
    E;
}

# Respuesta 1

Sabemos que el order de las sentencias se tiene que respetar en cada proceso, sin embargo el planificador
puede intercalar la ejecucion entre P y Q, por ende podemos tener diferentes lines de ejecucion

Para entender mejor este problema, supongamos que elegimos las primeras 2 posibles sentencias

- AB (PP)
- AD (PQ)
- DE (QQ)
- DA (QP)

arriba podemos ver que en dos casos, no se intercalo la ejecucion y en las otras dos si. En el tiempo 3
tenemos que

- ABC (PPP)
- ABD (PPQ)
- ADB (PQP)
- ADE (PQQ)
- DEA (QQP)
- DAB (QPP)
- DAE (QPQ)

en el tiempo 4 tenemos que

- ABCD (PPPQ)
- ABDC (PPQP)
- ABDE (PPQQ)
- ADBC (PQPP)
- ADBE (PQPQ)
- ADEB (PQQP)
- DEAB (QQPP)
- DABC (QPPP)
- DABE (QPPQ)
- DAEB (QPQP)

y finalmente en el tiempo 5, ultimo tiempo, se define todos los caminos posibles

1. ABCDE (PPPQQ)
2. ABDCE (PPQPQ)
3. ABDEC (PPQQP)
4. ADBCE (PQPPQ)
5. ADBEC (PQPQP)
6. ADEBC (PQQPP)
7. DEABC (QQPPP)
8. DABCE (QPPPQ)
9. DABEC (QPPQP)
10. DAEBC (QPQPP)

por ende tenemos 10 posibles hilos de ejecucion.


# Problema 2

Considere la siguiente función llamada por un pthread_create  donde dos hilos incrementan una variable global.

```
int cuenta=0;

void total()
{
    int i;
    for(i=0;i<1000;i++)
       cuenta++;
}
```

Determinar los valores mínimos y máximos que puede tomar la variable cuenta. Suponga que incrementar una variable en memoria requiere 3 operaciones

Carga la variable en un registro
Incrementa el registro
Carga el registro en la variable

# Respuesta 2

Se asumen que los dos hilos ejecutan completamente sus respectivos ciclos.

Tenemos 2 posibles casos  en la ejecucion del hilo

1. No-intercalacion
2. Intercalacion

En el primer caso, primero se ejecuta un hilo, despues el otro, por ende el valor resultante es `2000`
y este sera el valor maximo. En el segundo caso, intercalacion, podemos tener situaciones de carrera tambien
llamadas condiciones de carrera y si suponemos que el siguiente escenario donde la itercalacion sucede de la siguiente manera
siempre

| tiempo | hilo 0                          | hilo 1                             | cuenta |
|--------|---------------------------------|------------------------------------|--------|
| N      | mov eax, DWORD PRT cuenta[rpi]  |                                    | 0      |
| N+1    |                                 | mod eax, DWORD PRT cuenta[rpi]     | 0      |
| N+2    | add eax,1                       |                                    | 0      |
| N+3    |                                 | add eax,1                          | 0      |
| N+4    | mov  DWORD PTR cuenta[rip], eax |                                    | 1      |
| N+5    |                                 | mov     DWORD PTR cuenta[rip], eax | 1      |
| N+6    | mov eax, DWORD PRT cuenta[rpi]  |                                    | 1      |
| N+7    |                                 | mod eax, DWORD PRT cuenta[rpi]     | 1      |
| N+8    | add eax,1                       |                                    | 1      |
| N+9    |                                 | add eax,1                          | 1      |
| N+10   | mov  DWORD PTR cuenta[rip], eax |                                    | 2      |
| N+11   |                                 | mov     DWORD PTR cuenta[rip], eax | 2      |
| .      |                                 |                                    |        |
| .      |                                 |                                    |        |


Ver https://godbolt.org/z/5Yar4c4Go


# Problema 3
El código que se muestra en la Figura 1 es el intento donde dos procesos P(0) y P(1) se sincronizan a través de un algoritmo por software empleando variables en memoria compartida.


Haga un análisis de la ejecución concurrente de los dos procesos en una tabla donde se muestra la ejecución intercalada de instrucciones de ambos procesos, y muestre si esta solución funciona o no funciona, en caso de no funcionar explique el por qué.


```
boolean flag[2]={false,false};
int turno=0;

P(i)
{
  j=1-i;
  while(forever)
  {
      turno=j;
      while(flag[j] && turno!=i){};
      flag[i]=true;
      CS
      flag[i]=false;
      RS
  }
}
```
Figura 1. Código que ejecutan P(0) y P(1)

# Respuesta 3

El ciclo while que nos sirve como coordinador/sincronizador de los dos procesos es el siguiente

```
      while(flag[j] && turno!=i){};
```

Sin embargo, ningun de los dos procesos se detiene ya que la condicion es falta ya que

```
boolean flag[2]={false,false};
```

por ende en algun momento los dos procesos estan ejecutando  la seccion critica (CS) de manera
intercalada, no respetando la exclusion mutua.
