#include <stdio.h>

#define MAX 100

// Function to find minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int BT[MAX]; // Array to store burst times
    int WT[MAX]; // Array to store waiting times
    int TT[MAX]; // Array to store turnaround times

    // Input burst times for each process
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
    }

    int timeSlice; // Time slice (quantum)
    printf("Enter the time slice (quantum): ");
    scanf("%d", &timeSlice);

    int RT[MAX]; // Array to store remaining burst times
    int completed = 0; // Number of completed processes
    int currentTime = 0; // Current time

    // Initialize RT array and WT array
    for (int i = 0; i < n; i++) {
        RT[i] = BT[i];
        WT[i] = 0;
    }

    // Perform Round Robin scheduling
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (RT[i] > 0) {
                int timeExecuted = min(timeSlice, RT[i]);
                RT[i] -= timeExecuted;
                currentTime += timeExecuted;
                WT[i] += currentTime - timeExecuted;
                if (RT[i] == 0) {
                    completed++;
                    TT[i] = currentTime;
                }
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
