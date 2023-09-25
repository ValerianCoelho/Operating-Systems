#include <stdio.h>

#define MAX 100

// Function to perform Round Robin scheduling
void roundRobin(int n, int BT[], int AT[], int timeSlice) {
    int RT[MAX]; // Array to store remaining burst times
    int WT[MAX] = {0}; // Array to store waiting times
    int TT[MAX] = {0}; // Array to store turnaround times
    int currentTime = 0; // Current time
    int completed = 0; // Number of completed processes

    // Initialize RT with BT
    for (int i = 0; i < n; i++) {
        RT[i] = BT[i];
    }

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (AT[i] <= currentTime) {
                if (RT[i] > 0) {
                    if (RT[i] <= timeSlice) {
                        // Process completes within the time slice
                        currentTime += RT[i];
                        TT[i] = currentTime - AT[i];
                        RT[i] = 0;
                        completed++;
                    } else {
                        // Process still has remaining burst time
                        currentTime += timeSlice;
                        RT[i] -= timeSlice;
                    }

                    // Calculate waiting time
                    WT[i] = TT[i] - BT[i];
                }
            }
        }
    }
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int BT[MAX]; // Array to store burst times
    int AT[MAX]; // Array to store arrival times
    int timeSlice; // Time slice for Round Robin scheduling

    // Input burst times, arrival times, and time slice
    printf("Enter burst times and arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
    }

    printf("Enter the time slice for Round Robin: ");
    scanf("%d", &timeSlice);

    // Perform Round Robin scheduling
    roundRobin(n, BT, AT, timeSlice);

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
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, BT[i], AT[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
