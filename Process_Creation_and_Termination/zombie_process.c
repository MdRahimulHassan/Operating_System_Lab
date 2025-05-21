#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int p = fork();

    if (p == 0) {
        printf("child done\n");
        exit(0);
    } else {
        sleep(5);
        printf("parent run\n");
        wait(1);
    }

    return 0;
}
