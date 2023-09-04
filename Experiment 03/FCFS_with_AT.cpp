#include <iostream>
using namespace std;

#define MAX 20

void bubbleSort(int arr[], int index[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements in the AT array
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Swap the elements in the index array
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    int AT[MAX], BT[MAX], TL[MAX], EQ[MAX], WT[MAX], TT[MAX];

    cout << "Enter the number of processes : ";
    cin >> n;

    cout << "Enter the Arrival Times : ";
    for(int i=0; i<n; i++) {
        cin >> AT[i];
    }

    cout << "Enter the Burst Times : ";
    for(int i=0; i<n; i++) {
        cin >> BT[i];
    }

    for(int i=0; i<n; i++) {
        EQ[i] = i;
    }

    bubbleSort(AT, EQ, n);

    TL[0] = AT[EQ[0]];

    for(int i=0; i<n; i++) {
        TL[i+1] = TL[i] + BT[EQ[i]];
    }

    for(int i=0; i<n; i++) {
        for(int j=n-1; j>=0; j--) {
            if(i == EQ[j]) {
                WT[i] = TL[j] - AT[j];
                TT[i] = WT[i] + BT[i];
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << WT[i] << " ";
    } 
    cout << endl;
    for(int i=0; i<n; i++){
        cout << TT[i] << " ";
    }
    return 0;
}