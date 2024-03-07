/* Para compilar este ejemplo requieres hacerlo con el archivo semaphoresarray.c
 * Por ejemplo:
 *
 *		gcc -o semsejemplo1 semsejemplo1.c semaphoresarr.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "semaphoresarr.h"

#define NPROCS 10

int proceso(int n);

int semarray;	// ID del semáforo
#define EXMUT 0	// El semáforo EXMUT es el 0 del arreglo

int main()
{
  int i;
  int p;
  int status;

  srand(getpid());

  semarray=createsemarray(0x1234,1);	// Creamos un arreglo de semáforos con un semáforo
  initsem(semarray,EXMUT,1);	// Inicializamos valor del semáforo EXMUT con 1

  for(i=0;i<NPROCS;i++)
    {
      p=fork();
      if(p==0)
        proceso(i);
    }

  for(i=0;i<NPROCS;i++)
    wait(&status);

  erasesem(semarray);	// Eliminar los semáforos del sistema operativo
}

int proceso(int n)
{
  int i;

  for(i=0;i<2;i++)
    {
      usleep(rand()%1000000);

      semwait(semarray,EXMUT);	// Entrada a la sección crítica

      // Sección crítica
      printf("Proceso %d entra a la sección crítica - ",n);
      fflush(stdout);
      usleep(rand()%4000000);
      printf("Proceso %d sale de la seción crítica\n",n);

      semsignal(semarray,EXMUT); // Liberar la sección crítica
    }

  exit(0);
}
