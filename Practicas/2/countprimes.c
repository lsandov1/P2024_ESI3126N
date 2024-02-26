#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

int isprime(int n);

int main(int argc, char *argv[])
{
  int i, start, end, count = 0;

  if (argc != 3)
    {
      fprintf(stderr, "usage: %s <start> <end>", argv[0]);
      exit(-1);
    }
  else
    {
      start = atoi(argv[1]);
      end = atoi(argv[2]);
    }

  for(i=start;i<=end;i++)
    if (isprime(i))
      count++;

  printf("number of primes %d\n", count);
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
