#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int AT[n]; // Array to store arrival times
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times

    // Input burst times and arrival times for each process
    printf("Enter burst times and arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        processes[i] = i + 1; // Initialize process numbers
    }

    // Sort processes by arrival time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (AT[j] > AT[j + 1]) {
                // Swap the elements to sort by arrival time
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    // Perform FCFS scheduling
    int currentTime = 0; // Initialize the current time
    for (int i = 0; i < n; i++) {
        if (AT[i] > currentTime) {
            currentTime = AT[i];
        }
        WT[i] = currentTime - AT[i];
        TT[i] = WT[i] + BT[i];
        currentTime += BT[i];
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

    // Display the results including averages
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], BT[i], AT[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
