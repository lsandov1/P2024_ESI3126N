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

#define SLEEP_PARENT 5
#define SLEEP_NON_PARENT 20

#define NUM_CHILD 2
#define NUM_GRAND_CHILD 3

int
main(void)
{

  pid_t parent_pid, pid;

  for(int i=0; i < 3; i++)
    {
      pid = fork();
      if (!parent_id)
        {
          signal(SIGQUIT, sigquit);
          sleep(SLEEP_NON_PARENT);
        }
    }

  pid = fork();
  if (!pid)
    signal(SIGQUIT, sigquit);

  fork();

  if(getpid()==pid) {

  }
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
