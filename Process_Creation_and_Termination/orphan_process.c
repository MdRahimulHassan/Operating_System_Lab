#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int p = fork();

    if (p > 0) {
        printf("parent exit\n");
        exit(0);
    } else if (p == 0) {
        sleep(3);
        printf("child run, parent gone\n");
    }

    return 0;
}
