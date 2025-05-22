#include <stdio.h>
#include <pthread.h>

int buffer = 0;
pthread_mutex_t lock;

void* producer(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&lock);
        buffer++;
        printf("Producer: %d\n", buffer);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&lock);
        printf("Consumer: %d\n", buffer);
        buffer--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t p, c;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
