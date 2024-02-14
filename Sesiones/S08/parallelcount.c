#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 4
#define ITERS 1000000

int global=0;

void *tfunc(void *args)
{
  int i;
  for(i=0;i<ITERS;i++)
    global++;
}

int main()
{
  pthread_t tid[NTHREADS];
  int i;

  for(i=0;i<NTHREADS;i++)
    pthread_create(&tid[i],NULL,tfunc,NULL);

  for(i=0;i<NTHREADS;i++)
      pthread_join(tid[i],NULL);

  printf("global computed=%d expected=%d\n", global,NTHREADS*ITERS);

}
