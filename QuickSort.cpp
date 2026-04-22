#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;

long long comparisons = 0;

// Partition using last element as pivot
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        comparisons++;

        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    comparisons = 0;

    quickSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for(int x : arr) cout << x << " ";

    cout << "\nComparisons: " << comparisons << endl;

    return 0;
}
