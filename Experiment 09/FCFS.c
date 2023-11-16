#include <stdio.h>
#include <math.h>

#define MAX 30

int main() {
    int sequenceSize;
    int current;
    int sequence[MAX];
    int totalHeadMovement = 0;
    int displacement;

    printf("Enter the Start Position : ");
    scanf("%d", &current);

    printf("Enter the number of reads : ");
    scanf("%d", &sequenceSize);

    printf("Enter the Sequence : ");
    for(int i=1; i<=sequenceSize; i++) {
        scanf("%d", &sequence[i]);
    }

    sequence[0] = current;
    sequenceSize++;

    printf("Scheduling Sequence : %d ", sequence[0]);
    for(int i=1; i<sequenceSize; i++) {
        displacement = abs(sequence[i] - sequence[i-1]);
        totalHeadMovement += displacement;
        printf("%d ", sequence[i]);

    }
    printf("\nTotal Head Movement = %d", totalHeadMovement);
    return 0;
}