#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex[5];

void* thread(void* arg) {
    int id = *(int*)arg;
    int next = (id + 1) % 5;
    pthread_mutex_lock(&mutex[id]);
    printf("Thread %d acquired mutex%d\n", id, id);
    sleep(1); // Simulating some work
    pthread_mutex_lock(&mutex[next]);
    printf("Thread %d acquired mutex%d\n", id, next);
    pthread_mutex_unlock(&mutex[next]);
    pthread_mutex_unlock(&mutex[id]);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int ids[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++) {
        pthread_mutex_init(&mutex[i], NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
