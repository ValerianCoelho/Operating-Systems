#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the process with the shortest remaining time
int findShortestJob(int n, int RT[]) {
    int shortestTime = INT_MAX;
    int shortestJob = -1;

    for (int i = 0; i < n; i++) {
        if (RT[i] < shortestTime && RT[i] > 0) {
            shortestTime = RT[i];
            shortestJob = i;
        }
    }

    return shortestJob;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int BT[MAX]; // Array to store burst times
    int WT[MAX]; // Array to store waiting times
    int TT[MAX]; // Array to store turnaround times
    int RT[MAX]; // Array to store remaining burst times
    int completed = 0; // Number of completed processes
    int currentTime = 0; // Current time

    // Input burst times for each process
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
        RT[i] = BT[i];
    }

    while (completed < n) {
        int shortestJob = findShortestJob(n, RT);

        if (shortestJob == -1) {
            currentTime++;
        } else {
            RT[shortestJob]--;
            currentTime++;

            if (RT[shortestJob] == 0) {
                completed++;
                TT[shortestJob] = currentTime;
                WT[shortestJob] = TT[shortestJob] - BT[shortestJob];
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
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, BT[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
