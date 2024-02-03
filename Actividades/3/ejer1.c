/*
  P2024_ESI3126N - Tareas - Actividad 3
  Leonardo Sandoval Gonzalez

  1.-Escribir un programa que cree un hijo. El hijo debe escribir: "Soy el hijo" diez veces. El padre debe escribir: "Soy el padre" diez veces. Ambos procesos deberán mostrar concurrentemente sus líneas en pantalla y entre cada linea que escriban deben hacer una pausa de un segundo. El padre debe esperar a que termine el hijo y mostrar el mensaje: "Mi proceso hijo ya ha terminado".

Sube este programa como ejer1.c

Notas:
1. El programa se baso en el man page de fork

*/
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ITERS 10
#define soy_el(expr) for(int i=0;i<ITERS;i++) {puts("Soy el "#expr);sleep(1);}

int
main(void)
{
    pid_t pid;

    if (signal(SIGCHLD, SIG_IGN) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    switch (pid) {
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);
    case 0:
        soy_el(hijo);
        exit(EXIT_SUCCESS);
    default:
        soy_el(padre);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
