#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to print optimal parenthesis
void printParenthesis(int i, int j, vector<vector<int>> &bracket, char &name) {
    if (i == j) {
        cout << name++;
        return;
    }

    cout << "(";

    printParenthesis(i, bracket[i][j], bracket, name);
    printParenthesis(bracket[i][j] + 1, j, bracket, name);

    cout << ")";
}

int main() {
    int n;

    cout << "Enter number of dimensions: ";
    cin >> n;

    
    if (n < 2) {
        cout << "Invalid input! Need at least 2 dimensions." << endl;
        return 0;
    }

    vector<int> p(n);

    cout << "Enter dimensions array:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    // L = chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;

            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum Scalar Multiplications: " << m[1][n - 1] << endl;

    cout << "Optimal Parenthesization: ";
    char name = 'A';
    printParenthesis(1, n - 1, bracket, name);

    cout << endl;

    return 0;
}
