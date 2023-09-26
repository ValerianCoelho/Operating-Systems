#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, time_slice;

    // Input number of processes and time slice
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time slice: ");
    scanf("%d", &time_slice);

    struct Process processes[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int completed = 0;
    int current_time = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int execute_time = (processes[i].remaining_time < time_slice) ? processes[i].remaining_time : time_slice;
                current_time += execute_time;
                processes[i].remaining_time -= execute_time;

                printf("Process %d executed for %d seconds. Current time: %d\n", processes[i].pid, execute_time, current_time);

                if (processes[i].remaining_time == 0) {
                    completed++;
                    processes[i].turnaround_time = current_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                }
            }
        }
    }

    // Display all values for each process at the end
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}
