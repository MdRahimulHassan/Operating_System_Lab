#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t p;

    printf("parent start\n");

    p = fork();

    if (p < 0) {
        printf("error\n");
        return 1;
    }
    else if (p == 0) {
        printf("child run\n");
        sleep(1);
        printf("child end\n");
        exit(0);
    }
    else {
        wait(NULL);
        printf("parent end\n");
    }

    return 0;
}
