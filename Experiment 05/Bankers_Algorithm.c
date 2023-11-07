#include <stdio.h>

#define MAX 20

int n, m;
int available[MAX];
int max[MAX][MAX];
int allocation[MAX][MAX];
int need[MAX][MAX];

int count = 0;

void input() {
    printf("Enter the Number of Processes : ");
    scanf("%d", &n);

    printf("Enter the Number of Resources : ");
    scanf("%d", &m);

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
    // Calculate the need matrix
    printf("Need Matrix :-\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

void safe_sequence() {
    int work[MAX], finish[MAX], sequence[MAX];

    // set work[i] = available[i]
    for (int i = 0; i < m; i++)   work[i] = available[i];

    // set finished[i] = 0, where i = 0, 1, 2, ...
    for (int i = 0; i < n; i++)   finish[i] = 0;

    while (count < n) {
        int isSafe = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canGrant = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canGrant = 0;
                        break;
                    }
                }
                if (canGrant) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    sequence[count++] = i;
                    finish[i] = 1;
                    isSafe = 1;
                }
            }
        }
        if (!isSafe) {
            printf("System is in an unsafe state.\n");
        }
    }

    printf("Safe sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", sequence[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");
}

void resource_request() {
    int process_id;
    int request[MAX];

    printf("Enter the requested Process ID : ");
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
}

int main() {
    input();
    safe_sequence();
    resource_request();
    return 0;
}

// 7 5 3 
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3

// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// 3 3 2
