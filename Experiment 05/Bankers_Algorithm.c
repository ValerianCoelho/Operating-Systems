#include <stdio.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int main() {
    int available[NUM_RESOURCES] = {3, 3, 2};
    int max[NUM_PROCESSES][NUM_RESOURCES] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int need[NUM_PROCESSES][NUM_RESOURCES];
    int finish[NUM_PROCESSES] = {0};
    int sequence[NUM_PROCESSES];
    int work[NUM_RESOURCES];
    int count = 0;

    // Calculate the need matrix
    for (int i = 0; i < NUM_PROCESSES; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize the work array
    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (count < NUM_PROCESSES) {
        int found = 0;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                int safe = 1;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        safe = 0;
                        break;
                    }
                }
                if (safe) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    sequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in an unsafe state.\n");
            return 1;
        }
    }

    printf("Safe sequence: ");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("P%d", sequence[i]);
        if (i != NUM_PROCESSES - 1)
            printf(" -> ");
    }
    printf("\n");

    // Now, let's simulate a resource request from a process (e.g., P1)
    int process_id = 3;
    int request[NUM_RESOURCES] = {2, 1, 0}; // The request for resources

    // Check if the request can be granted
    int canAllocate = 1;
    for (int i = 0; i < NUM_RESOURCES; i++) {
        if (request[i] > need[process_id][i] || request[i] > available[i]) {
            canAllocate = 0;
            break;
        }
    }
    printf("Can Allocate : %d", canAllocate);

    return 0;
}
