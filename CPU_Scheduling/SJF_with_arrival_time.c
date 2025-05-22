#include <stdio.h>

int main() {
    int n, at[10], bt[10], ct[10], wt[10], tat[10], p[10];
    int i, j, done[10] = {0}, time = 0, min_bt, min_idx;

    printf("num of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("p%d arrival: ", i + 1);
        scanf("%d", &at[i]);
        printf("p%d burst: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        min_bt = 9999;
        min_idx = -1;

        for (j = 0; j < n; j++) {
            if (!done[j] && at[j] <= time && bt[j] < min_bt) {
                min_bt = bt[j];
                min_idx = j;
            }
        }

        if (min_idx == -1) {
            time++;
            i--;
            continue;
        }

        time += bt[min_idx];
        ct[min_idx] = time;
        tat[min_idx] = ct[min_idx] - at[min_idx];
        wt[min_idx] = tat[min_idx] - bt[min_idx];
        done[min_idx] = 1;
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
