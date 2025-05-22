#include <stdio.h>
#include <pthread.h>

int data = 0, readers = 0;
pthread_mutex_t mutex, wrt;

void* reader(void* arg) {
    pthread_mutex_lock(&mutex);
    readers++;
    if (readers == 1)
        pthread_mutex_lock(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("Reader read: %d\n", data);

    pthread_mutex_lock(&mutex);
    readers--;
    if (readers == 0)
        pthread_mutex_unlock(&wrt);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* writer(void* arg) {
    pthread_mutex_lock(&wrt);
    data++;
    printf("Writer wrote: %d\n", data);
    pthread_mutex_unlock(&wrt);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1, w2;
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&wrt, NULL);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w2, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&wrt);
    return 0;
}
