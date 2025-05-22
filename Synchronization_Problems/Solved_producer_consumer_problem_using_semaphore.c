#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer = 0;
sem_t full, empty;

void* producer(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&empty);
        buffer++;
        printf("Producer: %d\n", buffer);
        sem_post(&full);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&full);
        printf("Consumer: %d\n", buffer);
        buffer--;
        sem_post(&empty);
    }
    return NULL;
}

int main() {
    pthread_t p, c;
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
