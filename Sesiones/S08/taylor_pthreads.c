#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>

#define NTHREADS 4
#define ITERS 1000000

double sum = 0.0;
float x = 0.0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *tfunc(void *args)
{
  /* compute index ranges */
  int tnum = *((int *) args);
  int n_start = tnum * (ITERS/NTHREADS);
  int n_end = (1+tnum) * (ITERS/NTHREADS);
  int n;
  double local_sum=0;

  // the taylor series start at n=1, so jump the 0
  n_start = (n_start == 0)? 1: n_start;

  // intensive computation
  for(n=n_start;n<n_end;n++)
      local_sum += pow(-1,n+1) * pow(x,n) / n;

  printf("thread %d n_start %d n_end %d local_sum %lf\n", tnum, n_start, n_end, local_sum);

  // critical section
  pthread_mutex_lock(&mtx);
  sum += local_sum;
  pthread_mutex_unlock(&mtx);

}

int main()
{
  struct timeval ts_start, ts_end, ts_res;
  pthread_t tid[NTHREADS];
  int id[NTHREADS];
  int i;

  printf("Calcular el logaritmo natural de 1+x\n");
  printf("Dame el valor de x :");
  scanf("%f",&x);

  gettimeofday(&ts_start, NULL);
  {
    for(i=0;i<NTHREADS;i++)
      {
        id[i]=i; // passing  &i directly is incorrect because
                 // pointed value changes for every iteration,
                 // thus we need an array
        pthread_create(&tid[i], NULL, tfunc, &id[i]);
      }

    for(i=0;i<NTHREADS;i++)
      pthread_join(tid[i],NULL);

  }
  gettimeofday(&ts_end, NULL);

  timersub(&ts_end, &ts_start, &ts_res);

  printf("Result = %.16lf\n",sum);
  printf("Computed time: %lld sec %lld msec\n", ts_res.tv_sec, ts_res.tv_usec);
}
