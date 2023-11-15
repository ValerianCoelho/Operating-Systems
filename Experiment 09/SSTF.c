#include <stdio.h>
#include <math.h>

#define MAX 100

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int findIndex(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int current; // Position of the current Head Position
    int diskSize; // Size of the disk
    int sequenceSize; // Size of the Head Movement Sequence
    int index; // Store the index of current head position while scheduling
    int rightIndex;
    int leftIndex;
    int prevIndex; // Store the index of previous head position while scheduling
    int repositioningIndex; // repositioning index to be set after index hits upper or lower bound
    int count = 0; // count the number of request scheduled
    int totalHeadMovement = 0; // store the total Head Movement
    int displacement; // Calculate the displacement between current and previous disk scheduled
    int leftDisplacement;
    int rightDisplacement;

    int sequence[MAX]; // Store the Head Movement Sequence

    printf("Enter the current position : ");
    scanf("%d", &current);

    printf("Enter the disk size : ");
    scanf("%d", &diskSize);

    printf("Enter the Size of the Sequence : ");
    scanf("%d", &sequenceSize);

    printf("Enter the sequence : ");
    for(int i=0; i<sequenceSize; i++) {
        scanf("%d", &sequence[i]);
    }

    sequence[sequenceSize] = current; // Add the current Head Position in the sequence
    sequenceSize++; // Accommodate for the new element inserted above

    bubbleSort(sequence, sequenceSize); // sort the sequence in ascending order

    index = findIndex(sequence, sequenceSize, current); // Find the index of the value stored in current
    leftIndex = index - 1;
    rightIndex = index + 1;

    prevIndex = index;

    while(count < sequenceSize) {
        displacement = abs(sequence[index] - sequence[prevIndex]);
        totalHeadMovement += displacement;
        prevIndex = index;

        leftDisplacement = abs(sequence[index] - sequence[leftIndex]);
        rightDisplacement = abs(sequence[rightIndex] - sequence[index]);

        if(leftDisplacement < rightDisplacement 
           && leftIndex >= 0 // if leftIndex >=0 means that the leftDisplacement Calculated Above is invalid
           || rightIndex >= sequenceSize // if rightIndex >= sequenceSize means that the rightDisplacement Calculated Above is invalid
        ) {
            index = leftIndex;
            leftIndex--;
        }
        else {
            index = rightIndex;
            rightIndex++;
        }
        count++;
    }

    printf("Total Head Movement : %d", totalHeadMovement);

}

// Previous Head Position : 50
// Current Head Position : 64
// No of Disks : 200
// Sequence Size : 12
// Sequence: 181 6 100 9 77 45 170 132 53 190 88 61

// Previous Head Position : 100
// Current Head Position : 143
// No of Disks : 2500
// Sequence Size : 10
// Sequence : 80 400 2300 1500 1050 2000 100 1888 1580 1700