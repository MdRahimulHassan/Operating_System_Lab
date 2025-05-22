#include <stdio.h>
#include <pthread.h>

int buffer = 0;

void* producer(void* arg) {
    for (int i = 0; i < 5; i++) {
        buffer++;
        printf("Producer: %d\n", buffer);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Consumer: %d\n", buffer);
        buffer--;
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
