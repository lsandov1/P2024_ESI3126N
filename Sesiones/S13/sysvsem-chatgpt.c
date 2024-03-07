/* Reference: ChatGPT
   Question: provide a simple example in C using SysV semaphores

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

// Define semaphore key
#define SEM_KEY 1234

// Function to perform work in the critical section
void criticalSection(int semid) {
    struct sembuf semaphoreOperation;

    // Wait (decrement) the semaphore
    semaphoreOperation.sem_num = 0;
    semaphoreOperation.sem_op = -1;
    semaphoreOperation.sem_flg = 0;
    semop(semid, &semaphoreOperation, 1);

    // Critical section: simulated work
    printf("Inside Critical Section\n");
    sleep(2);

    // Signal (increment) the semaphore
    semaphoreOperation.sem_op = 1;
    semop(semid, &semaphoreOperation, 1);
}

int main() {
    int semid;
    key_t key;

    // Create a unique key
    if ((key = ftok(".", 's')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create or get the semaphore
    if ((semid = semget(key, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore value to 1
    semctl(semid, 0, SETVAL, 1);

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child Process\n");

        // Perform work in the critical section
        criticalSection(semid);
    } else {
        // Parent process
        printf("Parent Process\n");

        // Perform work in the critical section
        criticalSection(semid);

        // Wait for the child process to finish
        wait(NULL);

        // Remove the semaphore
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}
