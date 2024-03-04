#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define NPROCS 4

// functions
int isprime(int n);
int countprimes(int num_proc, int offset, int range);

// global which would point to the shared memory
int *count = NULL;

int main(int argc, char *argv[])
{
  int start, end;
  int total_count = 0;
  int num_proc;
  int range;
  pid_t pid;

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

  // allocate share memory for NPROC integers (counts)
  int shmid = shmget(0x1234,sizeof(int) * NPROCS, 0666|IPC_CREAT);

  // get the memory address
  count = (int *) shmat(shmid,NULL,0);

  // compute length of series per process
  range = (end - start + 1) / NPROCS;

  // compute partial results
  for(num_proc=0; num_proc < NPROCS; num_proc++) {
    pid=fork();
    if(pid==0)
      countprimes(num_proc, start, range);
  }

  // sum partial results
  for(num_proc=0;num_proc < NPROCS; num_proc++) {
    wait(NULL);
    total_count += count[num_proc];
  }

  printf("number of primes %d\n", total_count);
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

int countprimes(int num_proc, int offset, int range)
{
  int i;
  int proc_count = 0;
  int start = offset + num_proc * range;
  int end = start + range;

  for(i=start; i < end; i++)
    if (isprime(i))
      proc_count++;

  // place result in variable at share memory
  count[num_proc] = proc_count;

  printf("number of local primes %d %d %d %d\n", num_proc, start, end, proc_count);

  // exiting the process is important, otherwise execution
  // thread continues on main
  exit(0);
}
