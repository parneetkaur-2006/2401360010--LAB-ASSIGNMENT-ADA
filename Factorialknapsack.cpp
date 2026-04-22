#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

// sort in descending order of ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items and capacity: ";
    cin >> n >> capacity;

    if(n <= 0 || capacity <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<Item> items(n);

    cout << "Enter value and weight:\n";
    for(int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;

        if(items[i].weight <= 0) {
            cout << "Weight must be > 0!" << endl;
            return 0;
        }

        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double maxProfit = 0.0;

    cout << "\nItems taken:\n";

    for(int i = 0; i < n; i++) {
        if(capacity == 0) break;

        if(items[i].weight <= capacity) {
            // take full item
            cout << "Take full item (value=" << items[i].value 
                 << ", weight=" << items[i].weight << ")\n";

            capacity -= items[i].weight;
            maxProfit += items[i].value;
        }
        else {
            // take fraction
            double fraction = (double)capacity / items[i].weight;

            cout << "Take " << fraction * 100 << "% of item (value=" 
                 << items[i].value << ", weight=" << items[i].weight << ")\n";

            maxProfit += items[i].value * fraction;
            capacity = 0;
        }
    }

    cout << "\nMaximum Profit: " << maxProfit << endl;

    return 0;
}
