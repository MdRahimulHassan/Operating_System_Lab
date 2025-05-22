#include <stdio.h>

int main() {
    int n, at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int t = 0, complete = 0, shortest, min_rt, i;
    int finish;

    printf("num of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("p%d arrival: ", i + 1);
        scanf("%d", &at[i]);
        printf("p%d burst: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while (complete < n) {
        shortest = -1;
        min_rt = 9999;

        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }

        rt[shortest]--;
        t++;

        if (rt[shortest] == 0) {
            complete++;
            ct[shortest] = t;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
