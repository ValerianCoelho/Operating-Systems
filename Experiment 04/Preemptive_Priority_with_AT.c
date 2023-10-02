#include <stdio.h>
#include <limits.h>

// Structure to represent a process
struct Process {
    int PI;
    int AT;
    int RT;
    int WT;
    int TT;
    int BT;
    int priority;
};

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

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

    while (completed < n) {
        int highestPriority = INT_MAX;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].AT <= currentTime && processes[i].priority < highestPriority && processes[i].RT > 0) {
                highestPriority = processes[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess == -1) {
            currentTime++;
        } else {
            processes[selectedProcess].RT--;
            currentTime++;

            if (processes[selectedProcess].RT == 0) {
                completed++;

                // Calculate turnaround time and waiting time
                processes[selectedProcess].WT = currentTime - processes[selectedProcess].AT - processes[selectedProcess].BT;
                processes[selectedProcess].TT = processes[selectedProcess].WT + processes[selectedProcess].BT;

                // Add to total waiting and turnaround times for average calculation
                TWT += processes[selectedProcess].WT;
                TTT += processes[selectedProcess].TT;
            }
        }
    }

    // Output results
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].PI, processes[i].AT, processes[i].RT,
            processes[i].priority, processes[i].WT, processes[i].TT);
    }

    // Calculate and display average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f\n", TWT / n);
    printf("Average Turnaround Time: %.2f\n", TTT / n);

    return 0;
}
