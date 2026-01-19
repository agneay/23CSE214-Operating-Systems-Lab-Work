#include <stdio.h>

struct process {
    int pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    int completed;
};

int main() {
    int n, time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time of P%d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].completed = 0;
    }

    while (completed < n) {
        int idx = -1;
        int min_burst = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].completed == 0) {
                if (p[i].burst < min_burst) {
                    min_burst = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += p[idx].burst;
            p[idx].turnaround = time - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].completed = 1;
            completed++;

            avg_wt += p[idx].waiting;
            avg_tat += p[idx].turnaround;
        } else {
            time++;
        }
    }

    printf("\nSJF Non-Preemptive Scheduling\n");
    printf("PID\tAT\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].waiting, p[i].turnaround);
    }

    printf("Average Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
