#include <iostream>
using namespace std;

int selectionSort(int arr[], int n, int &swapCount) {
    int stepCount = 0;
    swapCount = 0;

    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            stepCount++;   // comparison

            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++;   // swap counted
        }
    }

    return stepCount;
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int swapCount;
    int steps = selectionSort(arr, n, swapCount);

    cout << "\nSorted Array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparison Count: " << steps;
    cout << "\nSwap Count: " << swapCount;

    // Case Detection
    if(swapCount == 0)
        cout << "\nCase Detected: BEST CASE (O(n^2))";
    else if(swapCount == n - 1)
        cout << "\nCase Detected: WORST CASE (O(n^2))";
    else
        cout << "\nCase Detected: AVERAGE CASE (O(n^2))";

    return 0;
}
