#include <stdio.h>

int main() {
    int n, i, at[10], bt[10], rt[10], t = 0, tq, done = 0;
    int wt[10] = {0}, tat[10], ct[10];

    printf("Number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("P%d arrival time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d burst time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Time quantum: ");
    scanf("%d", &tq);

    while (done < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0) {
                flag = 1;
                if (rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    ct[i] = t;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    done++;
                }
            }
        }
        if (!flag)
            t++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}
