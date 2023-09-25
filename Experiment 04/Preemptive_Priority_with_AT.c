#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the process with the highest priority
int findHighestPriorityJob(int n, int priority[], int AT[], int currentTime) {
    int highestPriority = INT_MAX;
    int highestPriorityJob = -1;

    for (int i = 0; i < n; i++) {
        if (AT[i] <= currentTime && priority[i] < highestPriority) {
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
    int AT[MAX]; // Array to store arrival times
    int priority[MAX]; // Array to store priorities
    int WT[MAX]; // Array to store waiting times
    int TT[MAX]; // Array to store turnaround times
    int completed = 0; // Number of completed processes
    int currentTime = 0; // Current time

    // Input burst times, arrival times, and priorities for each process
    printf("Enter burst times, arrival times, and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Priority (lower value indicates higher priority): ");
        scanf("%d", &priority[i]);
    }

    while (completed < n) {
        int highestPriorityJob = findHighestPriorityJob(n, priority, AT, currentTime);

        if (highestPriorityJob == -1) {
            currentTime++;
        } else {
            BT[highestPriorityJob]--;
            currentTime++;

            if (BT[highestPriorityJob] == 0) {
                completed++;
                TT[highestPriorityJob] = currentTime - AT[highestPriorityJob];
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
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, BT[i], AT[i], priority[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
