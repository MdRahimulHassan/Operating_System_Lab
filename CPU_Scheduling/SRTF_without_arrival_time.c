#include <stdio.h>

int main() {
    int n, bt[10], rt[10], wt[10], tat[10];
    int i, t = 0, done = 0, shortest, min_rt;
    
    printf("num of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("p%d burst: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        shortest = -1;
        min_rt = 9999;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && rt[i] < min_rt) {
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
            done++;
            tat[shortest] = t;
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    printf("PID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
