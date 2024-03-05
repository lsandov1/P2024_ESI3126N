# Problema 1

Considere el siguiente programa que es el intento donde dos procesos P(0) y P(1) se sincronizan a
través de un algoritmo por software empleando variables en memoria compartida.

Haga un análisis de la ejecución concurrente de los dos procesos en una tabla donde se muestra
la ejecución intercalada de instrucciones de ambos procesos, y muestre que este intento no funciona, explique en dónde falla

```
int flag[2] = {FALSE,FALSE};
int turno=0;

void P(int i)
{
    int j=1–i;

    while(TRUE)
    {
        flag[i]=TRUE;

        while(turno!=i)
        {
            while(flag[j])
            {
                turno=i;
            }
        }
        /* Sección crítica */

        flag[i]=falso;

        /* Resto */
    }
}
```

# Respuesta 1


# Pregunta 2

2.- Considera el algoritmo de Dekker con la siguiente modificación con la intención de que funcione con 3 procesos. 
Mostrar que esta solución NO FUNCIONA, haciendo una tabla que muestre la secuencia de los 3 procesos concurrentes y
los valores de las variables. El que no funcione correctamente no necesariamente es que dos o más entren a la sección crítica. 
Considera posibilidades como de que uno de los tres no inicie y los otros dos sí.

```
int flag[3]={FALSE,FALSE,FALSE};
int turno=0;

void P(int i)
{
    int j=(i+1)%3;
    int k=(i+2)%3;

    while(1)
    {
        flag[i]=true;
        while(flag[j] || flag[k])
        {
             flag[i]=false;
             while(turno!=i);
             flag[i]=true;
        }

        CS

        turno=j;
        flag[i]=false;

        RS
    }
}
```
