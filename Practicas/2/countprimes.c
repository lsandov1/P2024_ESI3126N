#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

int isprime(int n);

int main()
{
  int i, start, end, count;

  start = 1;
  end = 10000000;
  count = 0;

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
