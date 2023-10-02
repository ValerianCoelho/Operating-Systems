#include <stdio.h>

struct Process {
    int PI;
    int BT;
    int RT;
    int WT;
    int TT;
};

int main() {
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].PI = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].BT);
        processes[i].RT = processes[i].BT;
        processes[i].WT = 0;
        processes[i].TT = 0;
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].RT > 0) {
                if (processes[i].RT <= time_quantum) {
                    currentTime += processes[i].RT;
                    processes[i].RT = 0;
                    completed++;

                    processes[i].WT = currentTime - processes[i].BT;
                    processes[i].TT = processes[i].WT + processes[i].BT;
                } else {
                    currentTime += time_quantum;
                    processes[i].RT -= time_quantum;
                }
            }
        }
    }

    // Calculate and display average waiting time and average turnaround time
    float TWT = 0;
    float TTT = 0;

    for (int i = 0; i < n; i++) {
        TWT += processes[i].WT;
        TTT += processes[i].TT;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t\t%d\t\t%d\n", processes[i].PI, processes[i].BT,
            processes[i].WT, processes[i].TT);
    }

    printf("\nAverage Waiting Time: %.2f\n", TWT / n);
    printf("Average Turnaround Time: %.2f\n", TTT / n);

    return 0;
}
