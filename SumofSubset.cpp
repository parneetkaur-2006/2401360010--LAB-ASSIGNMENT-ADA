#include <iostream>
#include <vector>
using namespace std;

int n, target;
vector<int> arr;
vector<int> subset;
bool found = false;

// Backtracking function
void sumOfSubsets(int index, int currentSum) {

    // If solution found
    if(currentSum == target) {
        cout << "Subset: ";
        for(int x : subset)
            cout << x << " ";
        cout << endl;

        found = true;
        return;
    }

    // Stop conditions
    if(index == n || currentSum > target)
        return;

    // Include current element
    subset.push_back(arr[index]);
    sumOfSubsets(index + 1, currentSum + arr[index]);

    // Backtrack (exclude element)
    subset.pop_back();
    sumOfSubsets(index + 1, currentSum);
}

int main() {

    cout << "Enter number of elements: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    arr.resize(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    cout << "\nSubsets with sum " << target << ":\n";

    sumOfSubsets(0, 0);

    if(!found) {
        cout << "No subset found!" << endl;
    }

    return 0;
}
