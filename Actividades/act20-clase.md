Resuelve uno o mas problemas en clase y subelos en formato PDF. La entrega contara como asistencia del dia.

1. En un sistema de cómputo que emplea paginación utiliza registros asociativos en el CPU para acelerar el proceso de traducción de 
direcciones físicas a direcciones lógicas, cada referencia a memoria del procesador se lleva un tiempo de 15 nanosegundos, 
y cada referencia a un registro asociativo se lleva 5 nanosegundo. Si el porcentaje de aciertos a los registros asociativos 
es del 65 %, determine el tiempo de acceso efectivo a la memoria.


- Busqueda asociativa = epsilon = `5` nanosegundos
- Ciclo de memoria = `15` nanosegundos
- Tasa de aciertos = `90%`

por lo tanto

```
EAT = (15 + 5)x0.90 + (30 + 5)(1 - 0.90) = 20x0.90 + 35x0.1 = 21.5 nanosegundos
```

2. Un sistema implementa un espacio de direcciones virtual paginado para cada proceso usando una tabla de páginas de un nivel, 
el tamaño máximo del espacio de direcciones virtual es de `2^64` bytes y tenemos que cada pagina mide `4Kb`,

¿Cuantas paginas podremos tener en nuestro proceso?

```
2^64
---- = 2^52
2^12
```


¿Si cada elemento en la tabla de paginas mide 4 bytes, cuanto medira cada tabla en memoria?

```
2^52 * 4 = 2^52 * 2^2 = 2^54 = 18 014 398 509 481 984 bytes!
```

¿Si tenemos una memoria de 64Gb, cabra una pagina completa en memoria?

no

3. Un sistema implementa un espacio de direcciones virtual paginado para cada proceso usando una tabla de páginas de dos niveles,
el tamaño máximo del espacio de direcciones virtuales es de `2^48` bytes y tenemos que cada pagina mide `4Kb`, ademas
que el taman~o del directorio de paginas es de `12` bits y una memoria fisica de `32` Gb

¿Cuántos bits se requieren por cada entrada en la tabla de páginas externa?

```
48 - 12 = 36 bits
```

¿Cuántos bits se requieren por cada entrada en la tabla de páginas interna?

```
12
```

¿Cuál es el número máximo de entradas en una tabla de páginas interna?

```
2^12 = 4k = 4096
```

¿Cuántos bits hay en una dirección virtual?

```
48
```
