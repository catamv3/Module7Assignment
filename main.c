#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Forks as global mutexes
pthread_mutex_t fork1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t fork2 = PTHREAD_MUTEX_INITIALIZER;

void* philosopher0(void* arg) {
    while (1) {
        printf("Philosopher 0 is thinking...\n");
        sleep(rand() % 3 + 1);

        printf("Philosopher 0 is hungry.\n");

        // Philosopher 0 picks up fork1 then fork2
        pthread_mutex_lock(&fork1);
        printf("Philosopher 0 picked up fork1.\n");

        pthread_mutex_lock(&fork2);
        printf("Philosopher 0 picked up fork2 and is eating.\n");

        sleep(rand() % 2 + 1);  // Eating

        printf("Philosopher 0 finished eating.\n");

        pthread_mutex_unlock(&fork2);
        pthread_mutex_unlock(&fork1);
        return NULL;
    }

}

void* philosopher1(void* arg) {
    while (1) {
        printf("Philosopher 1 is thinking...\n");
        sleep(rand() % 3 + 1);

        printf("Philosopher 1 is hungry.\n");

        // Philosopher 1 picks up fork2 then fork1
        pthread_mutex_lock(&fork2);
        printf("Philosopher 1 picked up fork2.\n");

        pthread_mutex_lock(&fork1);
        printf("Philosopher 1 picked up fork1 and is eating.\n");

        sleep(rand() % 2 + 1);  // Eating

        printf("Philosopher 1 finished eating.\n");

        pthread_mutex_unlock(&fork1);
        pthread_mutex_unlock(&fork2);
        return NULL;
    }


}

int main() {
    pthread_t t0, t1;

    pthread_create(&t0, NULL, philosopher0, NULL);
    pthread_create(&t1, NULL, philosopher1, NULL);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    return 0;
}
