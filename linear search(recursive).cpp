#include <iostream>
using namespace std;

int stepCount = 0;
string caseType = "";

int linearSearch(int arr[], int n, int key, int index) {

    stepCount++;   // function call counted

    if(index >= n) {
        caseType = "Worst Case (Element Not Found - O(n))";
        return -1;
    }

    if(arr[index] == key) {

        if(index == 0)
            caseType = "Best Case (O(1))";
        else if(index == n - 1)
            caseType = "Worst Case (O(n))";
        else
            caseType = "Average Case (O(n))";

        return index;
    }

    return linearSearch(arr, n, key, index + 1);
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key, 0);

    if(result != -1)
        cout << "\nElement found at index: " << result;
    else
        cout << "\nElement not found";

    cout << "\nStep Count: " << stepCount;
    cout << "\nCase Detected: " << caseType;

    return 0;
}
