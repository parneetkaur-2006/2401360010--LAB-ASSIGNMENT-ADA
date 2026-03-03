#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n, int &swapCount) {
    int stepCount = 0;
    swapCount = 0;
    bool swapped;

    for(int i = 0; i < n - 1; i++) {
        swapped = false;

        for(int j = 0; j < n - i - 1; j++) {
            stepCount++;   // comparison

            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;   // swap counted
                swapped = true;
            }
        }

        if(!swapped)
            break;   // Best case optimization
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
    int steps = bubbleSort(arr, n, swapCount);

    cout << "\nSorted Array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparison Count: " << steps;
    cout << "\nSwap Count: " << swapCount;

    int bestComp = n - 1;
    int worstComp = (n * (n - 1)) / 2;

    if(steps == bestComp && swapCount == 0)
        cout << " BEST CASE ";
    else if(steps == worstComp && swapCount == worstComp)
        cout << " WORST CASE ";
    else
        cout << " AVERAGE CASE ";

    return 0;
}
