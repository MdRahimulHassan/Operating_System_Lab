#include <stdio.h>

int main() {
    int n, bt[1000], rt[1000], pr[1000], t = 0, done = 0, i, min, idx;
    
    printf("num of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("p%d burst: ", i+1);
        scanf("%d", &bt[i]);
        printf("p%d priority: ", i+1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];
    }

    int wt[10] = {0}, tat[10], ct[10];
    while (done < n) {
        min = 999;
        idx = -1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && pr[i] < min) {
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
            tat[idx] = ct[idx];
            wt[idx] = tat[idx] - bt[idx];
            done++;
        }
    }

    printf("PID\tPri\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, pr[i], bt[i], wt[i], tat[i]);

    return 0;
}
