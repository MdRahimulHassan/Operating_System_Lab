#include <stdio.h>

int main() {
    int n, bt[1000], p[1000], pr[1000], wt[1000], tat[1000];
    int i, j, temp;

    printf("num of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("p%d burst: ", i+1);
        scanf("%d", &bt[i]);
        printf("p%d priority: ", i+1);
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("PID\tPri\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);

    return 0;
}
