Hacer los siguientes ejercicios:

# 1
Si tengo la memoria del sistema dividida en páginas de 4 Kb. y ocurren los siguientes eventos

    Se carga un proceso A de 14 Kb.
    Se carga un proceso B de 8 Kb.
    Se carga un proceso C de 5 Kb.
    Se expulsa el proceso C de la memoria
    Se carga un proceso D de 17 Kb.
    Se expulsa el proceso B de la memoria
    Se carga un proceso F de 11 Kb.

## 1.1

Haz el dibujo indicando como queda la memoria

## 1.2

¿Cómo quedan las tablas de páginas para cada proceso?

## 1.3

Si la dirección lógica es de 20 bits, ¿Cuántos bits se usan para el número de página y cuántos para el desplazamiento?


`8` bits para el numero de pagina
`12` bits para el desplazamiento

## 1.4

Si para el proceso F tengo la dirección lógica `14FBh`, ¿A qué dirección física debe ser traducida?

La direccion tiene `20` bits, lo cual podemos verla asi

```
0000 0001 0100 1111 1011
   0    1    4    F    B
```

Al marco indicado en el indice `0x01`, desplazado `0x4FB` bytes.

## 2

Considera que ahora tenemos la memoria del sistema dividida en páginas de 1 Kb. y ocurren los siguientes eventos:

    Se carga un proceso A de 3.5 Kb.
    Se carga un proceso B de 2.7 Kb.
    Se carga un proceso C de 2.5 Kb.
    Se expulsa el proceso C de la memoria
    Se carga un proceso D de 4.2 Kb.
    Se expulsa el proceso B de la memoria
    Se carga un proceso F de 3.6 Kb.

1.1.- Haz el dibujo indicando como queda la memoria

1.2.- ¿Cómo quedan las tablas de páginas para cada proceso?

1.3.- Si la dirección lógica es de 18 bits, ¿Cuántos bits se usan para el número de página y cuántos para el desplazamiento?

`8` bits para el numero de pagina
`10` bits para el desplazamiento

1.4.-Si para el proceso D tengo la dirección lógica `0x05EA`, ¿A qué dirección física debe ser traducida?

Nuestra direccion tiene 18 bits, lo cual podemos verla asi

```
00 0000 0101 1110 1010
   0    5    E    A
```

por lo tanto los primeros `8` bits representan la posicion en la tabla de paginas el cual es

Al marco indicado por el indice `00 0000 01` binario o `0x1` hexadecimal con desplazamiento (en memoria fisica) de `01 1110 1010`
o `0x1EA`

3.- ¿Qué aprendiste?

Subir un archivo en formato PDF con las respuestas a los problemas
