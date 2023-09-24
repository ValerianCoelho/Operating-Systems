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
    int AT[n]; // Array to store arrival times
    int WT[n]; // Array to store waiting times
    int TT[n]; // Array to store turnaround times
    int completed[n]; // Array to keep track of completed processes

    // Input burst times, priorities, and arrival times for each process
    printf("Enter burst times, priorities, and arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Priority (lower value indicates higher priority): ");
        scanf("%d", &priority[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        processes[i] = i + 1; // Initialize process numbers
        completed[i] = 0; // Initialize as not completed
    }

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int highestPriorityProcess = -1;
        int highestPriority = 9999;

        for (int i = 0; i < n; i++) {
            if (AT[i] <= currentTime && !completed[i] && priority[i] < highestPriority) {
                highestPriorityProcess = i;
                highestPriority = priority[i];
            }
        }

        if (highestPriorityProcess == -1) {
            currentTime++;
        } else {
            WT[highestPriorityProcess] = currentTime - AT[highestPriorityProcess];
            TT[highestPriorityProcess] = WT[highestPriorityProcess] + BT[highestPriorityProcess];
            currentTime += BT[highestPriorityProcess];
            completed[highestPriorityProcess] = 1;
            completedProcesses++;
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

    // Display the results, including averages
    printf("\nProcess\tBurst Time\tPriority\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], BT[i], priority[i], AT[i], WT[i], TT[i]);
    }

    printf("\nAverage Waiting Time: %.2lf\n", AWT);
    printf("Average Turnaround Time: %.2lf\n", ATT);

    return 0;
}
