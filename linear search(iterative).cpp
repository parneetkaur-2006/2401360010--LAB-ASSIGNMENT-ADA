#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &stepCount, string &caseType) {

    stepCount = 0;

    for(int i = 0; i < n; i++) {
        stepCount++;   // comparison count

        if(arr[i] == key) {

            if(i == 0)
                caseType = "Best Case (O(1))";
            else if(i == n - 1)
                caseType = "Worst Case (O(n))";
            else
                caseType = "Average Case (O(n))";

            return i;   // element found
        }
    }

    caseType = "Worst Case (Element Not Found - O(n))";
    return -1;   // not found
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

    int stepCount;
    string caseType;

    int result = linearSearch(arr, n, key, stepCount, caseType);

    if(result != -1)
        cout << "\nElement found at index: " << result;
    else
        cout << "\nElement not found";

    cout << "\nStep Count: " << stepCount;
    cout << "\nCase Detected: " << caseType;

    return 0;
}
