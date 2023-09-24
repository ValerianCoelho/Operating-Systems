#include <stdio.h>

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times

    // Input burst times for each process
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
        processes[i] = i + 1; // Initialize process numbers
    }

    // Calculate waiting time for each process
    WT[0] = 0; // The first process has 0 waiting time
    for (int i = 1; i < n; i++) {
        WT[i] = WT[i - 1] + BT[i - 1];
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        TT[i] = BT[i] + WT[i];
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

    // Display the results, including averages
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], BT[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
