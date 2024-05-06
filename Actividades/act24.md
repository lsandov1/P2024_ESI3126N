Si tengo un disco duro que físicamente tiene 900 cilindros (C), 16 superficies (H) y 37 sectores por pista (S), indica:

1) ¿Cuál es el número total de sectores que va a tener la unidad?

```
# sectores = C * H * S = 900 x 16 x 37 = 532800
```

2) Si los sectores tienen capacidad de almacenar 512 bytes, ¿cuál va a ser la capacidad del disco?

```
capacidad = # sectores x 512 = 272793600 bytes = 260.156 Mbytes
```

3) Si quiero tener ese disco con 2 particiones, la primera que tenga capacidad de un poco más de 100 Mbytes, 
toma en cuenta que para eso una partición inicia desde el inicio de un cilindro, es decir, 
en la superficie 0 y primer sector físico disponible, y termina al final de un cilindro, 
es decir en la última superficie del cilindro y en el último sector físico disponible.
La segunda partición será del espacio del tamaño restante de la unidad.

¿Cómo quedarían los bytes CHS inicial y CHS final en las dos entradas de la tabla de particiones?


Lo primero que tenemos que hacer es calcular el numero de sectores logicos que cada particion requiere y
a partir de esto tenemos los sectores logicos iniciales de cada uno,

```
# sectores 1era particion = # capacidad 1era particion / tam sector =  100MB / # tam sector               = 100 * 1024 * 1024  / 512      = 204800 sectores
# sectores 2da particion  = # capacidd 2da particion / tam sector   = (260.156 MB - 100MB) / # tam sector = (272793600 - 104857600) / 512 = 328000 sectores
```

Para la primera particion tenemos que

```
C = # Cylinder = (# sectores / # sectores por cilindro)                = (204800) / (16 * 37) = 346 = 0x15B
H = # Head     = (# sectores / # sectores por pista) % (# superficies) = (204800 / 37) % 16   = 15  = 0xF
S = # Sector   = (# sectores % # sectores por pista) + 1               = (204800 % 37) + 1    = 6   = 0x6
```

Sabemos que para la siguiente particion no podemos comenzar inmediatamente despues e.g `CHS=346.15.7` como lo indica el
parrafo 3 por lo que iniciara en el siguiente cilindro disponible, es decir

```
C = # Cylinder = (# sectores / # sectores por cilindro)                = (204800) / (16 * 37) = 347 = 0x15C
H = # Head     = (# sectores / # sectores por pista) % (# superficies) = (204800 / 37) % 16   = 0   = 0x0
S = # Sector   = (# sectores % # sectores por pista) + 1               = (204800 % 37) + 1    = 0   = 0x0
```


Con estos numeros, podemos calcular los valores de CHS inicial y final para cada particion

┌────────────┬───────────────────┬──────────┐
│Superficie-8│Cilindro-2,Sector-6│Cilindro-8│
└────────────┴───────────────────┴──────────┘

1era particion

CHS inicial/final
┌──┬──┬──┐
│00│01│00│
└──┴──┴──┘
┌──┬──┬──┐
│FF│16│5B│
└──┴──┴──┘

2era particion

CHS inicial/final
┌──┬──┬──┐
│00│10│5C│
└──┴──┴──┘
┌──┬──┬──┐
│10│E5│84│
└──┴──┴──┘

4) En la primera partición, ¿cuales van a ser los cilindros, superficies y sectores físicos
correspondientes a los sectores lógicos 180, 600, 1200?

Tenemos que el sector logico de inicio de particion es 1, por ende aplicamos las siguientes
formulas

```
sectorFísico = ((sectorLógico + sectorLógicoInicioPartición) % SEC_X_TRACK) + 1
superficie = ((sectorLógico + sectorLógicoInicioPartición) / SEC_X_TRACK) % SUPERFICIES
cilindro = (sectorLógico + sectorLógicoInicioPartición) / (SEC_X_TRACK * SUPERFICIES)
```

Sector logico 180

```
sectorFisico = 181%37 + 1 ~ 34
superficie = (181/37)%16 ~ 5
cilindro = 181/(37*16) ~ 0
```

Sector logico 600

```
sectorFisico = 601%37 + 1 ~ 10
superficie = (601/37)%16 ~ 0
cilindro = 601/(37*16) ~ 1
```

Sector logico 1200

```
sectorFisico = 1201%37 + 1 ~ 18
superficie = (1201/37)%16 ~ 0
cilindro = 1201/(37*16) ~ 2
```

5) En la segunda partición, ¿cuales van a ser los cilindros, superficies y sectores físicos 
correspondientes a los sectores lógicos 810, 1600, 2400?

Tenemos que nuestra segunda particion inicia

```
	Superficie inicial = 0
	Sector inicial = 0
	Cilindro inicial = 347
```

por ende, el sector logico inicial esta dada por la formula

```
sectorLógicoInicioPartición = 	cilindroInicial * SEC_X_TRACK * SUPERFICIES +
				superficieInicial * SEC_X_TRACK +
				sectorInicial –
				1
	= 347 * 37 * 16 + 0*37 + 0 - 1 = 205423
```


Sector logico 810

```
sectorFisico = (810 + 205423)%37 + 1 ~ 33
superficie   = ((810 + 205423)/37)%16 ~ 6
cilindro     = (810 + 205423)/(37*16) ~ 348
```

Sector logico 1600

```
sectorFisico = (1600 + 205423)%37 + 1 ~ 9
superficie = ((1600 + 205423)/37)%16 ~ 11
cilindro = (1600 + 205423)/(37*16) ~ 350
```


Sector logico 2400

```
sectorFisico = (2400 + 205423)%37 + 1 ~ 32
superficie = ((2400 + 205423)/37)%16  ~ 0
cilindro = (2400 + 205423)/(37*16) ~ 351
```
