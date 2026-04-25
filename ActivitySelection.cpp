#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store activity
struct Activity {
    int start, finish;
};

// Comparator function to sort by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity> &arr) {
    int n = arr.size();

    // Sort activities by finish time
    sort(arr.begin(), arr.end(), compare);

    cout << "Selected activities:\n";

    // First activity is always selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";

    // Select remaining activities
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j;
        }
    }
}

int main() {
    vector<Activity> arr = {
        {1, 2}, {3, 4}, {0, 6}, {5, 7},
        {8, 9}, {5, 9}
    };

    activitySelection(arr);

    return 0;
}
