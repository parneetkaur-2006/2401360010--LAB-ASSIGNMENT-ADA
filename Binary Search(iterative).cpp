#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoids overflow

        if (arr[mid] == key) {
            return mid;   // Element found
        }
        else if (arr[mid] < key) {
            low = mid + 1;   // Search in right half
        }
        else {
            high = mid - 1;  // Search in left half
        }
    }

    return -1;   // Element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
