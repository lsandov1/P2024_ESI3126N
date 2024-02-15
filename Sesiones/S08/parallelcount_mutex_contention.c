#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 4
#define ITERS 1000000

int global=0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *tfunc(void *args)
{
  int i;
  int s;

  for(i=0;i<ITERS;i++)
  {
    // Start of Critical path/section
    s = pthread_mutex_lock(&mtx);
    if (s!=0) {
      fprintf(stderr, "pthread_mutex_lock failed");
      exit(s);
    }
    global++;
    s = pthread_mutex_unlock(&mtx);
    if (s!=0) {
      fprintf(stderr, "pthread_mutex_unlock failed");
      exit(s);
    }
    // End of Critical path/section
  }
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
