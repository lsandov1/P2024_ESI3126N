/*
  P2024_ESI3126N - Tareas - Actividad 3.2
  Leonardo Sandoval Gonzalez

  3.- Desarrolla un programa que solicite al usuario una cadena de caracteres,
  esa cadena será el nombre de un programa1 a ejecutarse, una vez que este
  programa termine de ejecutarse permitirá al usuario introducir otro programa a
  ejecutarse, esto terminará cuando el usuario introduzca exit.
  Para este ejercicio utiliza la llamada al sistema system().
  En este ejercicio estamos haciendo nuestro primer shell o intérprete de comandos.

Sube este programa como ejer3.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(void)
{
  char buffer[256];
  int ret;

  while(1)
    {
      printf("$ ");
      scanf("%s",buffer);
      if (strcmp(buffer,"exit")==0)
        break;
      ret = system(buffer);
    }
}
