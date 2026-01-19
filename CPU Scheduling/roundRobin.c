#include <stdio.h>

int main() {
    int n, tq, time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        visited[i] = 0;
        printf("Enter arrival time and burst time of P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Queue simulation using array
    int queue[100], front = 0, rear = 0;

    // Add first arriving processes
    for (int i = 0; i < n; i++) {
        if (at[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];

        if (rt[idx] > tq) {
            rt[idx] -= tq;
            time += tq;
        } else {
            time += rt[idx];
            rt[idx] = 0;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed++;

            avg_wt += wt[idx];
            avg_tat += tat[idx];
        }

        // Add newly arrived processes
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // If process not finished, push back to queue
        if (rt[idx] > 0) {
            queue[rear++] = idx;
        }
    }

    printf("\nRound Robin Scheduling\n");
    printf("PID\tAT\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
