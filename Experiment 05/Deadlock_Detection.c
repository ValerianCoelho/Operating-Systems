#include<stdio.h>

int n, m, i, j, request[10][10], p[10], alloc[10][10], work[10], finish[10], count = 0, seq[10], s = 0, check1, check2, avl_vec[10];
int req[10][10], reqprocess, update_req[10];
void input() {
    printf("Enter number of processes\n");
    scanf("%d", & n);
    printf("\nEnter number of resources\n");
    scanf("%d", & m);
    printf("\nEnter the request matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", & request[i][j]);
        }
    }
    printf("\n");
    printf("Enter available vector\n");
    for (i = 0; i < m; i++) {
        scanf("%d", & avl_vec[i]);
    }
    printf("\nEnter allocation matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {

            scanf("%d", & alloc[i][j]);
        }
    }
}
void deadlock_detection() {
    count = 0, check1 = 0, check2 - 0, s = 0;
    for (i = 0; i < m; i++) {
        work[j] = avl_vec[j];
    }
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    while (count != n) {
        for (i = 0; i < n; i++) {
            check1 = 0;
            if (finish[i]) continue;
            for (j = 0; j < m; j++) {
                if (request[i][j] < ; = work[j]) {
                    check1++;
                }
                if (check1 == m) {
                    for (j = 0; j < m; j++) {

                        work[j] = work[j] + alloc[i][j];
                    }
                    finish[i] = 1;
                    seq[s] = i;
                    s++;
                }
            }
        }
        count++;
    }
    for (i = 0; i < n; i++) {
        if (finish[i] == 1) {
            check2++;
        }
    }
    if (check2 == n) {
        printf("\nSafe sequence exists\n");
        for (i = 0; i < n; i++) {
            printf("%d\t", seq[i]);
        }
        printf("\nDeadlock does not exists since safe sequence exists\n");
    } else {
        printf("\nDeadlock exists since safe sequence does not exist");
    }
}

void resource_request() {
    printf("\nEnter the process requested\n");
    scanf("%d", & reqprocess);
    printf("Enter the additional request\n");
    for (j = 0; j < m; j++) {
        scanf("%d", & update_req[j]);
    }
    for (j = 0; j < m; j++) {
        req[reqprocess][j] += update_req[j];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d", req[i][j]);
        }
        printf("\n");
    }
    deadlock_detection();
}

void main() {
    input();
    deadlock_detection();
    resource_request();
}