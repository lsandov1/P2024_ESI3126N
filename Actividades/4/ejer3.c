/*
  P2024_ESI3126N - Tareas - Actividad 4.3
  Leonardo Sandoval Gonzalez

  3.- Desarrolla un programa donde un proceso padre crea un hijo,
  el padre tendrá una duración de 1 segundo y el hijo una duración de
  20 segundos.

  Ejecuta el proceso padre en segundo plano y antes de que el padre
  termine observa qué procesos hay.

  $ ./ejer3 &

  $ ps --user iteso f

  ¿En qué estado se encuentra el padre?, ¿por qué?

  Entrega el ejercicio en el archivo ejer3.c

*/

#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SLEEP_PARENT 1
#define SLEEP_CHILD 20

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
