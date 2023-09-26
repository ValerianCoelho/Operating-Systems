#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;         // Process ID
    int burst_time;  // Burst time
    int priority;    // Priority (lower value means higher priority)
    bool completed;  // Indicates if the process has completed
};

int main() {
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input burst times and priorities for each process
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].completed = false;
    }

    int current_time = 0;
    int completed = 0;

    printf("\nProcess execution order:\n");

    while (completed < n) {
        int highest_priority = -1;
        int highest_priority_index = -1;

        // Find the process with the highest priority among the non-completed processes
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].priority > highest_priority) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
        }

        if (highest_priority_index != -1) {
            // Execute the process with the highest priority for 1 time unit
            processes[highest_priority_index].burst_time--;
            current_time++;

            // Print the execution information
            printf("Process %d (Priority: %d) executed. Current time: %d\n",
                   processes[highest_priority_index].pid,
                   processes[highest_priority_index].priority,
                   current_time);

            // Check if the process has completed
            if (processes[highest_priority_index].burst_time == 0) {
                processes[highest_priority_index].completed = true;
                completed++;
            }
        } else {
            // If no process is ready to execute, increment current_time
            current_time++;
        }
    }

    return 0;
}
