#include <stdio.h>

// Structure to represent a process
struct Process {
    int PI; // Process ID
    int BT; // Burst Time
    int RT; // Remaining Time
    int WT; // Waiting Time
    int TT; // Turnaround Time
};

int main() {
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[n];

    // Input process information for each process.
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

    // Execute the Round Robin scheduling algorithm until all processes are completed.
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

    float TWT = 0;
    float TTT = 0;

    for (int i = 0; i < n; i++) {
        TWT += processes[i].WT;
        TTT += processes[i].TT;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i].PI, processes[i].BT,
            processes[i].WT, processes[i].TT);
    }

    printf("\nAverage Waiting Time: %.2f\n", TWT / n);
    printf("Average Turnaround Time: %.2f\n", TTT / n);

    return 0;
}
