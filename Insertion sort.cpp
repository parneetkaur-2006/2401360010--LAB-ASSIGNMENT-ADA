#include <iostream>
using namespace std;

int insertionSort(int arr[], int n) {
    int stepCount = 0;

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0) {
            stepCount++;   // comparison

            if(arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = key;
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

    int steps = insertionSort(arr, n);

    cout << "\nSorted Array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nStep Count: " << steps;

    // Case Detection using formula
    int bestSteps = n - 1;
    int worstSteps = (n * (n - 1)) / 2;

    if(steps == bestSteps)
        cout << "\nCase Detected: BEST CASE )";
    else if(steps == worstSteps)
        cout << "\nCase Detected: WORST CASE )";
    else
        cout << "\nCase Detected: AVERAGE CASE ";

    return 0;
}
