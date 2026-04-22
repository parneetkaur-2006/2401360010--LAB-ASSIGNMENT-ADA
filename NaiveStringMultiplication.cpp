#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);   

    cout << "Enter pattern: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();

   
    if (m > n) {
        cout << "Pattern longer than text → Not found\n";
        return 0;
    }

    long long comparisons = 0;
    bool found = false;

    cout << "\nPattern found at index: ";

    for (int i = 0; i <= n - m; i++) {

        int j;
        for (j = 0; j < m; j++) {
            comparisons++;

            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "Not found";

    cout << "\nTotal Comparisons: " << comparisons << endl;

    return 0;
}
