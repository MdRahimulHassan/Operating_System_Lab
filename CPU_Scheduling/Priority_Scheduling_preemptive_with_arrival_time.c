#include <stdio.h>

int main() {
    int n, at[1000], bt[1000], rt[1000], pr[1000], t = 0, done = 0, i;
    int wt[1000], tat[1000], ct[1000];

    printf("num of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("p%d arrival: ", i+1);
        scanf("%d", &at[i]);
        printf("p%d burst: ", i+1);
        scanf("%d", &bt[i]);
        printf("p%d priority: ", i+1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        int min = 999, idx = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && pr[i] < min) {
                min = pr[i];
                idx = i;
            }
        }

        if (idx == -1) {
            t++;
            continue;
        }

        rt[idx]--;
        t++;

        if (rt[idx] == 0) {
            ct[idx] = t;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done++;
        }
    }

    printf("PID\tAT\tPri\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], pr[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}
