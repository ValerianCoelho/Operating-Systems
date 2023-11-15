#include <stdio.h>
#include <math.h>

#define MAX 100 // Assuming a maximum array size

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int start;
    int sequence[MAX];
    int totalHeadMovement = 0;
    int left = -1; // Initialize to -1 to handle cases where the start is at the beginning
    int right = n; // Initialize to n to handle cases where the start is at the end
    int count = 0;
    int current;

    printf("Enter the Start Position : ");
    scanf("%d", &start);

    printf("Enter the number of reads : ");
    scanf("%d", &n);

    printf("Enter the Sequence : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // Sort the sequence array using bubble sort
    bubbleSort(sequence, n);

    // Calculate Left and Right Index
    for (int i = 0; i < n - 1; i++) {
        if (start >= sequence[i] && start <= sequence[i + 1]) {
            left = i;
            right = i + 1;
            break;
        }
    }

    if (start - sequence[left] < sequence[right] - start) {
        current = left;
        left = left - 1;
    } else {
        current = right;
        right = right + 1;
    }
    totalHeadMovement += abs(start - sequence[current]);
    count = count + 1;

    while (count < n) {
        if (sequence[current] - sequence[left] < sequence[right] - sequence[current] && left >= 0 || right >= 12) {
            totalHeadMovement += abs(sequence[current] - sequence[left]);
            current = left;
            left = left - 1;
        } else {
            totalHeadMovement += abs(sequence[right] - sequence[current]);
            current = right;
            right = right + 1;
        }
        count++;
    }
    printf("\nTotal Head Movement : %d", totalHeadMovement);

    return 0;
}