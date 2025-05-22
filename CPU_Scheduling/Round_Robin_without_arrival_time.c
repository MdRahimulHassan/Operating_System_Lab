#include <stdio.h>

int main() {
    int n, i, bt[10], rt[10], tq, t = 0, done = 0;
    int wt[10] = {0}, tat[10];

    printf("Number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("P%d burst time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Time quantum: ");
    scanf("%d", &tq);

    while (done < n) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    tat[i] = t;
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    done++;
                }
            }
        }
    }

    printf("\nPID\tBT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], tat[i], wt[i]);

    return 0;
}
