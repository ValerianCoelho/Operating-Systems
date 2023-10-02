#include <stdio.h>
#include <limits.h>

struct Process {
    int PI;
    int AT;
    int BT;
    int RT;
    int WT;
    int TT;
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
        processes[i].RT = processes[i].BT;
    }

    int currentTime = 0;
    int completed = 0;
    float TWT = 0;
    float TTT = 0;

    while (completed < n) {
        int shortest = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].AT <= currentTime && processes[i].RT < shortestTime && processes[i].RT > 0) {
                shortest = i;
                shortestTime = processes[i].RT;
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            processes[shortest].RT--;
            currentTime++;

            if (processes[shortest].RT == 0) {
                processes[shortest].TT = currentTime - processes[shortest].AT;
                processes[shortest].WT = processes[shortest].TT - processes[shortest].BT;

                TWT += processes[shortest].WT;
                TTT += processes[shortest].TT;

                completed++;
            }
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].PI, processes[i].AT, processes[i].BT, processes[i].WT, processes[i].TT);
    }

    printf("\nAverage Waiting Time: %.2f\n", TWT / n);
    printf("Average Turnaround Time: %.2f\n", TTT / n);

    return 0;
}
