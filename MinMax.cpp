#include <iostream>
using namespace std;

int stepCount = 0;

void findMinMax(int arr[], int n, int &minVal, int &maxVal) {

    minVal = arr[0];
    maxVal = arr[0];

    for(int i = 1; i < n; i++) {

        stepCount++;   // comparison for min
        if(arr[i] < minVal)
            minVal = arr[i];

        stepCount++;   // comparison for max
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int minVal, maxVal;

    findMinMax(arr, n, minVal, maxVal);

    cout << "\nMinimum = " << minVal;
    cout << "\nMaximum = " << maxVal;
    cout << "\nStep Count = " << stepCount;

    return 0;
}
