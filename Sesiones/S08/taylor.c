#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

#define ITERS 1000000000

int main()
{
  struct timeval ts_start, ts_end, ts_res;
  int n;
  double sum = 0.0;
  float x;

  printf("Calcular el logaritmo natural de 1+x\n");
  printf("Dame el valor de x :");
  scanf("%f",&x);

  gettimeofday(&ts_start, NULL);
  {
    for(n=1;n<ITERS;n++)
      sum = sum + pow(-1,n+1) * pow(x,n) / n;
  }
  gettimeofday(&ts_end, NULL);

  timersub(&ts_end, &ts_start, &ts_res);

  printf("Result = %.16lf\n",sum);
  printf("Computed time: %lld sec %lld msec\n", ts_res.tv_sec, ts_res.tv_usec);
}
