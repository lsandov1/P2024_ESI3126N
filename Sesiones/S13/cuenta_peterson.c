#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 2
#define ITERS 10000

int cuenta=0;
int flag[NTHREADS] = {0,0};
int turno = 0;

void *tfunc(void *args)
{
  int i = *((int *) args);
  int j = 1-i;
  int k;

  for(k=0;k<ITERS;k++)
    {
      flag[i] = 1;
      turno = j;
      while (flag[j] && turno==j) {}; // Espera
      cuenta++; //CS
      flag[i] = 0;
    }
}

int main()
{
    pthread_t tid[NTHREADS];
    int tnum[NTHREADS];
    int i;

    for(i=0;i<NTHREADS;i++)
      {
        tnum[i]=i;
        pthread_create(&tid[i],NULL,tfunc,tnum+i);
      }

    for(i=0;i<NTHREADS;i++)
        pthread_join(tid[i],NULL);

    printf("cuenta %d\n", cuenta);
}
