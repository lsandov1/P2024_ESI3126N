/*
  P2024_ESI3126N - Tareas - Actividad 4.2
  Leonardo Sandoval Gonzalez

  2.- Desarrolla un programa donde un proceso padre crea un hijo,
  el padre tendrá una duración de 20 segundos y el hijo una duración de
  1 segundo.

  Ejecuta el proceso padre en segundo plano y antes de que el padre
  termine observa qué procesos hay.

$ ./ejer2 &

$ ps
*/

#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SLEEP_PARENT 20
#define SLEEP_CHILD 1

int
main(void)
{
  pid_t pid;

    pid = fork();
    switch (pid) {
    case -1:
      perror("fork");
      exit(EXIT_FAILURE);
    case 0:
      sleep(SLEEP_CHILD);
      puts("Child exiting.");
      exit(EXIT_SUCCESS);
    default:
      printf("Child is PID %jd\n", (intmax_t) pid);
      sleep(SLEEP_PARENT);
      puts("Parent exiting.");
      exit(EXIT_SUCCESS);
    }
}
