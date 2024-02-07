/*
  P2024_ESI3126N - Tareas - Actividad 4.4
  Leonardo Sandoval Gonzalez

  4.- Desarrolla un programa que al ejecutarse cree dos procesos hijos y
  cada uno de los hijos creará 3 nuevos procesos hijos. De esta manera
  habrá un proceso padre, dos procesos hijos y seis procesos nieto.
  Los hijos y los nietos deberán tener al final la instrucción sleep(20),
  pero el padre después de ejecutar la instrucción sleep(5)
  deberá terminar a todos los hijos y nietos.

  Entrega el ejercicio en el archivo ejer4.c
*/

#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SLEEP_PARENT 5
#define SLEEP_NON_PARENT 20

void create_grandchildren(char *son);

int
main(void)
{

  pid_t pid;

  pid = fork();
  if (pid == 0)
    {
      printf("1C\n");
      create_grandchildren("1C");
      sleep(SLEEP_NON_PARENT);
      exit(0);
    }
  else {
    pid = fork();
    if (pid == 0)
      {
        printf("2C\n");
        create_grandchildren("2C");
        sleep(SLEEP_NON_PARENT);
        exit(0);
      }
    printf("1P\n");
    sleep(SLEEP_PARENT);
    // TODO: matar todos los hijos y nietos
    wait(NULL);
  }
}

void create_grandchildren(char *son)
{
  pid_t pid;
  pid = fork();
  if (pid == 0)
    {
      // primer nieto
      printf("%s-1GC\n",son);
      sleep(SLEEP_NON_PARENT);
      exit(0);
    }
  else
    {
      pid = fork();
      if (pid == 0)
        {
          // segundo nieto
          printf("%s-2GC\n",son);
          sleep(SLEEP_NON_PARENT);
          exit(0);
        }
      else
        {
          pid = fork();
          if (pid == 0)
            {
              // tercer nieto
              printf("%s-3GC\n",son);
              sleep(SLEEP_NON_PARENT);
              exit(0);
            }
        }
    }
}
