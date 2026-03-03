#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid + 1;   // Returning position instead of index
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int arr[] = {5, 15, 25, 35, 45, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 35;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Element found at position: " << result;
    else
        cout << "Element not found";

    return 0;
}
