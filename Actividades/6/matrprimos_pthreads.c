#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>

#define SIZE 2000

#define INICIAL 900000000
#define FINAL 1000000000

int mat[SIZE][SIZE];

#define NTHREADS 16

void initmat(int mat[][SIZE]);
int countnonzeroes(int mat[SIZE][SIZE]);
int isprime(int n);
void printmat(int mat[][SIZE]);
void *tfunc(void *args);

void *tfunc(void *args)
{
  /* compute index ranges */
  int tnum = *((int *) args);
  int i_start = tnum * SIZE/NTHREADS;
  int i_end = (1+tnum) * SIZE/NTHREADS;

  printf("thread %d start %d end %d\n",tnum, i_start, i_end);

  int i,j;
  for(i=i_start;i<i_end;i++)
    for(j=0;j<SIZE;j++)
      if(!isprime(mat[i][j]))
        mat[i][j]=0;
}

int main()
{
  struct timeval ts_start, ts_end, ts_res;
  int i;
  pthread_t tid[NTHREADS];
  int targs[NTHREADS];
  int count;

  // Inicializa la matriz con números al azar
  initmat(mat);

  gettimeofday(&ts_start, NULL);
  {
    // Eliminar de la matriz todos los números que no son primos
    for(i=0;i<NTHREADS;i++){
      targs[i] = i;
      pthread_create(&tid[i],NULL,tfunc,&targs[i]);
    }

    for(i=0;i<NTHREADS;i++)
      pthread_join(tid[i],NULL);
  }
  gettimeofday(&ts_end, NULL);

  timersub(&ts_end, &ts_start, &ts_res);
  count = countnonzeroes(mat);
  printf("Primes found: %d\n", count);
  printf("Computed time: %lld sec %lld msec\n", ts_res.tv_sec, ts_res.tv_usec);
}

void initmat(int mat[][SIZE])
{
  int i,j;
  int count=0;
  srand(getpid());

  for(i=0;i<SIZE;i++)
    for(j=0;j<SIZE;j++)
      mat[i][j]=INICIAL+rand()%(FINAL-INICIAL);
}

void printmat(int mat[][SIZE])
{
  int i,j;
  for(i=0;i<SIZE;i++)
    for(j=0;j<SIZE;j++)
      printf("%d ", mat[i][j]);
}

int countnonzeroes(int mat[SIZE][SIZE])
{
  int i,j,count=0;
  for(i=0;i<SIZE;i++)
    for(j=0;j<SIZE;j++)
      if(mat[i][j]!=0)
        count++;
  return count;
}

int isprime(int n)
{
  int d=3;
  int prime=n==2;
  int limit=sqrt(n);

  if(n>2 && n%2!=0)
    {
      while(d<=limit && n%d)
        d+=2;
      prime=d>limit;
    }
  return(prime);
}
