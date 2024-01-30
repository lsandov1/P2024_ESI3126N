#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// sigquit() function definition
void sigquit()
{
  printf("Adios, mi pid es %d\n",getpid());
  exit(0);
}

int main()
{

  int pid;

  if (!(pid=fork())) {
      pid_t ppid = getppid();      // PPID padre
      sleep(1);
      printf("Hijo manda senal SIGQUIT a %d\n", ppid);
      kill(ppid, SIGQUIT);       // mandar la senal al padre PPID
    }
    else {
      // reciba la senal
      // mostral el ID
      // salir
      signal(SIGQUIT, sigquit);
        for (;;)
          ;
    }
}
