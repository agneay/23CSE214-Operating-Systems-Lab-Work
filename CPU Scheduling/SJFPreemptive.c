#include <stdio.h>

struct process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
    int completion;
};

int main() {
    int n, time = 0, completed = 0, min_remaining;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time of P%d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    while (completed < n) {
        int idx = -1;
        min_remaining = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                if (p[i].remaining < min_remaining) {
                    min_remaining = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].remaining--;
            time++;

            if (p[idx].remaining == 0) {
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                completed++;

                avg_wt += p[idx].waiting;
                avg_tat += p[idx].turnaround;
            }
        } else {
            time++;
        }
    }

    printf("\nSJF Preemptive Scheduling (SRTF)\n");
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
