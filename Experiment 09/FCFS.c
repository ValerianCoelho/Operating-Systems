#include <stdio.h>
#include <math.h>

#define MAX 30

int main() {
    int n;
    int start;
    int sequence[MAX];
    int totalHeadMovement = 0;

    printf("Enter the Start Position : ");
    scanf("%d", &start);

    printf("Enter the number of reads : ");
    scanf("%d", &n);

    printf("Enter the Sequence : ");
    for(int i=0; i<n; i++) {
        scanf("%d", &sequence[i]);
    }

    totalHeadMovement += sequence[0] - start;

    for(int i=1; i<n; i++) {
        totalHeadMovement += abs(sequence[i] - sequence[i-1]);
    }

    printf("Total Head Movement = %d", totalHeadMovement);

    return 0;
}

// 181 6 100 9 77 45 170 132 53 190 80 61