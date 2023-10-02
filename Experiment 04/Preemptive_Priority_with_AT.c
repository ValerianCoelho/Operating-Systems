#include <stdio.h>
#include <limits.h>

// Structure to represent a process
struct Process {
    int PI;        // Process ID
    int AT;        // Arrival Time
    int RT;        // Remaining Time
    int WT;        // Waiting Time
    int TT;        // Turnaround Time
    int BT;        // Burst Time
    int priority;  // Priority
};

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process information for each process.
    for (int i = 0; i < n; i++) {
        processes[i].PI = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].AT);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].BT);
        printf("Enter priority for process P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].RT = processes[i].BT;
        processes[i].WT = 0;
        processes[i].TT = 0;
    }

    int currentTime = 0;
    int completed = 0; 
    float TWT = 0;
    float TTT = 0;

    // Execute the scheduling algorithm until all processes are completed.
    while (completed < n) {
        int highestPriority = INT_MAX;
        int selectedProcess = -1;

        // Find the process with the highest priority that has arrived and has remaining execution time.
        for (int i = 0; i < n; i++) {
            if (processes[i].AT <= currentTime && processes[i].priority < highestPriority && processes[i].RT > 0) {
                highestPriority = processes[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess == -1) {
            currentTime++;  // No eligible process, time increment
        } else {
            processes[selectedProcess].RT--;  // Execute the selected process for one time unit
            currentTime++;

            if (processes[selectedProcess].RT == 0) {
                completed++;

                processes[selectedProcess].WT = currentTime - processes[selectedProcess].AT - processes[selectedProcess].BT;
                processes[selectedProcess].TT = processes[selectedProcess].WT + processes[selectedProcess].BT;

                TWT += processes[selectedProcess].WT;
                TTT += processes[selectedProcess].TT;
            }
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].PI, processes[i].AT, processes[i].RT,
            processes[i].priority, processes[i].WT, processes[i].TT);
    }

    printf("\nAverage Waiting Time: %.2f\n", TWT / n);
    printf("Average Turnaround Time: %.2f\n", TTT / n);

    return 0;
}
