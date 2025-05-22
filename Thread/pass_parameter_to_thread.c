#include <stdio.h>
#include <pthread.h>

void* print_msg(void* arg) {
    char* msg = (char*) arg;
    printf("Thread says: %s\n", msg);
    return NULL;
}

int main() {
    pthread_t tid;
    char* message = "Hello from thread";

    pthread_create(&tid, NULL, print_msg, message);
    pthread_join(tid, NULL);

    return 0;
}
