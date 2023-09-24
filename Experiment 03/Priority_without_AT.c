#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n]; // Array to store process numbers
    int BT[n]; // Array to store burst times
    int priority[n]; // Array to store priorities
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times

    // Input burst times and priorities for each process
    printf("Enter burst times and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Priority (lower value indicates higher priority): ");
        scanf("%d", &priority[i]);
        processes[i] = i + 1; // Initialize process numbers
    }

    // Sort processes based on priority (lower priority first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priorities, burst times, and process numbers
                swap(&priority[j], &priority[j + 1]);
                swap(&BT[j], &BT[j + 1]);
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    // Calculate waiting time and turnaround time
    WT[0] = 0; // The first process has 0 waiting time
    for (int i = 1; i < n; i++) {
        WT[i] = WT[i - 1] + BT[i - 1];
    }

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
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], BT[i], priority[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
