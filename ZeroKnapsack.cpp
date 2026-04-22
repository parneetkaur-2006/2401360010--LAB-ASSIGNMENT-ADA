#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items and capacity: ";
    cin >> n >> W;

    if(n <= 0 || W < 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<int> value(n), weight(n);

    cout << "Enter value and weight:\n";
    for(int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {

            if(weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxProfit = dp[n][W];

    // Backtracking to find selected items
    vector<pair<int,int>> selected; // {value, weight}

    int w = W;
    for(int i = n; i > 0; i--) {
        if(dp[i][w] != dp[i - 1][w]) {
            selected.push_back({value[i - 1], weight[i - 1]});
            w -= weight[i - 1];
        }
    }

    cout << "\nMaximum Profit: " << maxProfit << endl;

    cout << "Selected Items (value, weight): ";
    for(int i = selected.size() - 1; i >= 0; i--) {
        cout << "(" << selected[i].first << "," << selected[i].second << ") ";
    }

    cout << endl;

    return 0;
}
