#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process {
    int pid;             // Process ID
    int arrival_time;    // Arrival time
    int burst_time;      // Burst time
    int remaining_time;  // Remaining burst time
    bool completed;      // Indicates if the process has completed
};

int main() {
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input arrival times and burst times for each process
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = false;
    }

    int current_time = 0;
    int completed = 0;
    int execution_order[n];
    int execution_index = 0;

    while (completed < n) {
        int shortest_remaining_time = INT_MAX;
        int shortest_remaining_time_index = -1;

        // Find the process with the shortest remaining burst time among the non-completed processes that have arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival_time <= current_time &&
                processes[i].remaining_time < shortest_remaining_time) {
                shortest_remaining_time = processes[i].remaining_time;
                shortest_remaining_time_index = i;
            }
        }

        if (shortest_remaining_time_index != -1) {
            // Execute the process with the shortest remaining burst time for 1 time unit
            processes[shortest_remaining_time_index].remaining_time--;
            current_time++;

            // Record the execution order
            execution_order[execution_index++] = processes[shortest_remaining_time_index].pid;

            // Check if the process has completed
            if (processes[shortest_remaining_time_index].remaining_time == 0) {
                processes[shortest_remaining_time_index].completed = true;
                completed++;
            }
        } else {
            // If no process is ready to execute, increment current_time
            current_time++;
        }
    }

    // Display the execution order of processes
    printf("\nProcess execution order:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", execution_order[i]);
    }
    printf("\n");

    return 0;
}
