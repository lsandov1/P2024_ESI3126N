## 1 

En la paginación cada acceso a memoria requiere al menos dos accesos a memoria, explica por qué.

Uno para la tabla de paginas y con este obtener el numero de marco y  otro para acceder a la memoria (por el dato/instruccion)

## 2

¿Qué efecto tiene permitir que dos entradas de una tabla de paginas apunten al mismo marco de página en la memoria?, 

 **Comparticion** de memoria. 
 
¿Qué efecto tendría sobre una de las paginas la actualización de un byte en la otra?

Como las dos paginas apuntan al mismo marco, cualquier modificacion de este ultimo se vera reflejada en las
dos paginas.

Esto es parecido a la memoria compartida por los hilos de un proceso, donde cualquier cambio en la memoria global
es vista por todos los hilos o tambien podremoso ver cuando en distintos procesos se genera y comparte
memoria.

## 3

¿Cuál es la diferencia de memoria física y memoria virtual? ¿qué es la paginación?

**Memoria Fisica**: es la memoria que tenemos fisicamente en un sistema de computo y generalmente le llamamos
memoria RAM

**Memoria virtual**: es un espacio de direcciones virtual (o logico)
que usan todos los procesos que se estan ejecutando en un sistema operativo y le permite a un sistema tener
mejor control del espacio de memoria. 

Al utilizar la memoria virtual el SO nos permite las siguientes ventajas:

- Los Procesos estan aislados unos de otros y del kernel, asi que un proceso no puede leer o modificar
la memoria de otro proceso o kernel. Eso se logra a traves de una tabla de paginas por cada proceso
que apuntan a diferentes conjuntos de paginas en RAM (o en el area de intercambio o *swap*)

- Dos o mas procesos pueden compartir memoria por la razon dada anteriormente.

- La implementacion de la proteccion de memoria se facilita.

- Programadores y herramientas como compiladores y enlazadores, no tienen que entende la disposicion (*layout*)
del programa en RAM

- Ya que solo una parte el programa necesita residir en memoria, en programa se carga y ejecuta mas rapidamente.
Ademas la huella de memoria (i.e virtual size) del proceso puede exceder la capacidad de la RAM

## 4

En un sistema de cómputo que emplea paginación utiliza registros asociativos en el CPU para acelerar 
el proceso de traducción de direcciones físicas a direcciones lógicas, cada referencia a memoria del procesador 
se lleva un tiempo de 20 nanosegundos, y cada referencia a un registro asociativo se lleva 1 nanosegundo. 
Si el porcentaje de aciertos a los registros asociativos es del 65 %, determine el tiempo de acceso efectivo a la memoria.

Ciclo de memoria = `20 ns`
Busqueda asociativa = e = `1 ns`
Tasa aciertos = a = `0.65`

```
TAE = (20ns + e) a + (40ns + e) (1-a)
    = (20ns + 1ns) * 0.65 + (40ns + 1ns) * 0.35
    = 21*0.65 + 41*0.35 = 28 ns
```

Ahora, consideremos  casos extremos, mejor y peor caso:


Recordemos que los registros asociativos tambien se encuentran en memoria, y si en el caso donde
siempre se encuentre el marco en estos registros, no es necesario el acceso a la tabla
de paginas debido a que ya tenemos el marco, por lo tanto


```
a = 1

TAE = (20ns + e) a + (40ns + e) (1-a)
    = (20ns + 1ns) * 1 + (40ns + 1ns) * 0
    = 21*1= 21 ns
```

en el peor de los casos, tenemos que se requiren dos ciclos de memoria, uno para buscar el marco
en los registros asociativos pero como no esta ahi, se hace la busqueda en la tabla de paginas,
por lo tanto

```
a = 0

TAE = (20ns + e) a + (40ns + e) (1-a)
    = (20ns + 1ns) * 0 + (40ns + 1ns) * 1
    = 41*1= 41 ns
```
ya que se requiren **dos* ciclo de memoria (`40ns`) mas el tiempo de busqueda asociativa (`1ns`)

## 5

Un sistema implementa un espacio de direcciones virtual paginado para cada proceso usando una tabla de páginas de dos niveles, el
tamaño máximo del espacio de direcciones virtual es de `16` Gb. El tamaño de página es de `4` Kb, el tamaño del directorio de
páginas es de `12` bits, y el tamaño de la memoria física es de `2` Gb.

Lo primero que tenemos que hacer es saber cuando bits contiene nuestra direccion virtual. Si el taman~o maximo es `16` Gb, por
ende tenemos que `34` bits.

En un sistema de pagina de 1 nivel tendriamos que


```
# tabla de paginas | desplazamiento
┌──┬──┐
│22│12│
└──┴──┘
```

Sin embargo queremos un sistema de paginacion 2 niveles, donde el directorio de paginas es de `12` bits, por ende

```
# tabla de paginas externa | # tabla de paginas interna | desplazamiento
┌──┬──┬──┐
│12│10│12│
└──┴──┴──┘
```

- ¿Cuántos bits se requieren por cada entrada en la tabla de páginas externa? `12`
- ¿Cuántos bits se requieren por cada entrada en la tabla de páginas interna? `10`
- ¿Cuál es el número máximo de entradas en una tabla de páginas interna? `4096`
- ¿Cuántos bits hay en una dirección virtual?`34 bits`

## 6

En un sistema de segmentación explica, ¿cómo puedes implementar que dos procesos compartan memoria?

Asi como la paginacion es una forma en que la memoria de un proceso se divide en memoria, la segmentacion es otra
forma de division de un proceso en memoria, solo que en esta ultima la division es logica, es decir, se divide
en las diferentes partes logicas de un proceso, como el segmento de codigo, el segmento de datos y el
segmento de stack por mencionar algunos.

## 7

Menciona 3 diferencias entre la paginación y segmentación

	1. La pagina tiene un taman~o constante y un segmento no
    2. Una pagina puede contener datos y codigo pero en un segmento solo tenemos o datos o codigo
    3. Tanto la pagina como la segmentacion, ambas se realizan sin intervencion del usuario
    pero en esta ultima, por la direccion sabemos a que segmento nos estamos refiriendo.
    4. Un SO puede usar o paginacion o segmentacion o segmentacion con paginacion
	3. El contenido de las tablas es distinto

## 8

Tenemos un proceso que tiene `3` segmentos cargados en memoria física. El segmento `0` inicia en la dirección física `0x100` 
y mide `5.5` Kbytes,  el segmento  `1` inicia en la dirección física `0x2300` y mide `17` Kbytes,  y el segmento `2` inicia en la dirección física 
`0xA000` y mide `25` Kbytes.

¿Cómo quedan los segmentos en la memoria física?, has un dibujo.
¿Cómo queda la tabla de segmentos?

| Indice      | Direccion Base | Tamano        | Direccion Fin  |
| ----------- | -----------    | --------------| -------------- |
| 0           | 0x100          | 0x1600 (5.5k) | 0x1700         |
| 1           | 0x2300         | 0x4400 (17k)  | 0x6700         |
| 2           | 0xA000         | 0x6400 (25k)  | 0x10400        |



| Indice      | Base        | Tamano (Kb en dec) |
| ----------- | ----------- | ----------- |
| 0           | 0x100       | 5.5         |
| 1           | 0x2300      | 17          |
| 2           | 0xA000      | 25          |


Si tengo las siguientes direcciones lógicas, a qué direcciones físicas corresponden, indicar si son direcciones inválidas

```
    0:0x0100 - Valida
    0:0xA000 - Invalida
    1:0x02F0 - Valida
    2:0x1F00 - Valida
```

9.- ¿Qué aprendiste?
