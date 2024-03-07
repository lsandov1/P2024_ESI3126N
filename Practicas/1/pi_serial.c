#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

#define ITERS 10000000

int main()
{
	long long start_ts;
	long long stop_ts;
	long long elapsed_time;
	long lElapsedTime;
	struct timeval ts;
	int n;
	double sum = 0.0;
	double x=0;
	double y;
	double delta=1.0/ITERS;
	double hdelta=delta/2;

	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec; // Tiempo inicial

	for(n=1;n<ITERS;n++)
	  {
	  x += delta;
	  y = sqrt(1-pow(x-hdelta,2));
	  sum += delta*y;
	  }

	sum *= 4;

	gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec; // Tiempo final

	elapsed_time = stop_ts - start_ts;
	printf("computed %.32lf expected %.32lf \n", sum, M_PI);
}
