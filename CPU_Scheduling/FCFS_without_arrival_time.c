#include <stdio.h>

int main() {
    int n, i;
    int bt[10], wt[10], tat[10];

    printf("num of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("p%d burst: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("PID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
