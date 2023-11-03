#include <stdio.h>

int main() {
    int n, m;
    
    printf("Enter the Number of Processes : ");
    scanf("%d", &n);

    printf("Enter the Number of Resources : ");
    scanf("%d", &m);

    int available[m];
    int max[n][m];
    int allocation[n][m];

    printf("Enter the Available Processes : ");
    for(int i=0; i<m; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter The Max Matrix :-");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter The Allocation Matrix :-");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    int need[n][m];
    int finish[n];
    int sequence[n];
    int work[m];
    int count = 0;

    // Calculate the need matrix
    printf("Need Matrix :-\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Initialize the work array
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int safe = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        safe = 0;
                        break;
                    }
                }
                if (safe) {
                    for (int j = 0; j < m; j++) {
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
    for (int i = 0; i < n; i++) {
        printf("P%d", sequence[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");

    int process_id;
    int request[m];

    printf("Enter the Process ID : ");
    scanf("%d", &process_id);

    printf("Enter the request : ");
    for(int i=0; i<m; i++) {
        scanf("%d", &request[i]);
    }

    // Check if the request can be granted
    int canAllocate = 1;
    for (int i = 0; i < m; i++) {
        if (request[i] > need[process_id][i] || request[i] > available[i]) {
            canAllocate = 0;
            break;
        }
    }
    if(canAllocate) {
        printf("Request can be granted");
    } else {
        printf("Request cannot be granted");
    }

    return 0;
}
