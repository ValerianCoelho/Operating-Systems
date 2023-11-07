#include <stdio.h>

#define MAX 20

int n, m;
int request[MAX][MAX], allocation[MAX][MAX], available[MAX];

void input() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix:-\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the request matrix:-\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter available resource vector: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }
}

void deadlock_detection() {
    int s = 0; // Safe Sequence Array Index Variable
    int isSafe; // Check if safe sequence exists
    int canGrant; // Flag to Check if the resource can be granted

    int work[MAX], finished[MAX], sequence[MAX];

    // set work[i] = available[i]
    for (int i = 0; i < m; i++)   work[i] = available[i];

    // set finished[i] = 0, where i = 0, 1, 2, ...
    for (int i = 0; i < n; i++)   finished[i] = 0;

    for(int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            canGrant = 1;

            if (finished[i]) continue;  // Process has finished Execution

            for (int j = 0; j < m; j++) { // Check if Current Request can be granted
                if (request[i][j] > work[j]) {
                    canGrant = 0;
                    break;
                }
            }
            if (canGrant) { // Grant the request if it can be granted
                for (int j=0; j<m; j++) {
                    work[j] += allocation[i][j];
                }
                finished[i] = 1;
                sequence[s++] = i;
            }
        }
        k++;
    }

    for (int i = 0; i < n; i++) { // Check if safe sequence exists
        if (!finished[i]) {
            isSafe = 0;
        }
    }
    if (isSafe) { // If safe sequence exists
        printf("Safe sequence : ");
        for (int i = 0; i < n; i++) printf("P%d ", sequence[i]);
        printf("\nDeadlock Does not Exist");
    } else { // if deadlock exists
        printf("Deadlock exists\n");
    }
}

void resource_request() {
    int process_id; // id of requested process
    int additional_request[MAX];

    printf("\nEnter the requested process ID: ");
    scanf("%d", &process_id);

    printf("Enter the additional request: ");
    for (int j = 0; j < m; j++) {
        scanf("%d", &additional_request[j]);
    }
    
    for (int j = 0; j < m; j++) {
        request[process_id][j] += additional_request[j];
    }
    deadlock_detection();
}

int main() {
    input();
    deadlock_detection();
    resource_request();
    return 0;
}

// Allocation Matrix
// 0 1 0
// 2 0 0
// 3 0 3
// 2 1 7
// 0 0 2

// Request Matrix
// 0 0 0
// 2 0 2
// 0 0 0
// 1 0 0
// 0 0 2

// Available Vector
// 0 0 0

// Requesting process id : 2
// Additional Request : 0 0 1
