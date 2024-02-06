/*
  P2024_ESI3126N - Tareas - Actividad 4.1
  Leonardo Sandoval Gonzalez

  1.- Desarrolla un programa donde un proceso padre crea un proceso hijo,
  al iniciar este proceso hijo, deberá matar o terminar a su padre.

Entrega el ejercicio en el archivo ejer1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void sigquit();

int main()
{

  int pid;

  printf("Padre crea proceso hijo\n");
  if (!(pid=fork()))
    {
      printf("Hijo termina a padre %d\n", getppid());
      kill(getppid(), SIGQUIT);
    }
    else {
      signal(SIGQUIT, sigquit);
        for (;;)
          ;
    }
}

void sigquit()
{
  printf("Adios, mi pid es %d\n",getpid());
  exit(0);
}
