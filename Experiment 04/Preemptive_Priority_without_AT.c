#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the process with the highest priority
int findHighestPriorityJob(int n, int priority[], int RT[]) {
    int highestPriority = INT_MAX;
    int highestPriorityJob = -1;

    for (int i = 0; i < n; i++) {
        if (RT[i] > 0 && priority[i] < highestPriority) {
            highestPriority = priority[i];
            highestPriorityJob = i;
        }
    }

    return highestPriorityJob;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int BT[MAX]; // Array to store burst times
    int priority[MAX]; // Array to store priorities
    int WT[MAX]; // Array to store waiting times
    int TT[MAX]; // Array to store turnaround times
    int RT[MAX]; // Array to store remaining burst times
    int completed = 0; // Number of completed processes
    int currentTime = 0; // Current time

    // Input burst times and priorities for each process
    printf("Enter burst times and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Priority (lower value indicates higher priority): ");
        scanf("%d", &priority[i]);
        RT[i] = BT[i];
    }

    while (completed < n) {
        int highestPriorityJob = findHighestPriorityJob(n, priority, RT);

        if (highestPriorityJob == -1) {
            currentTime++;
        } else {
            RT[highestPriorityJob]--;
            currentTime++;

            if (RT[highestPriorityJob] == 0) {
                completed++;
                TT[highestPriorityJob] = currentTime;
                WT[highestPriorityJob] = TT[highestPriorityJob] - BT[highestPriorityJob];
            }
        }
    }

    // Calculate average waiting time and average turnaround time
    double TWT = 0;
    double TTT = 0;

    for (int i = 0; i < n; i++) {
        TWT += WT[i];
        TTT += TT[i];
    }

    double AWT = TWT / n;
    double ATT = TTT / n;

    // Display the results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, BT[i], priority[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
