#include <iostream>
using namespace std;

int stepCount = 0;

long long factorial(int n) {

    long long fact = 1;

    for(int i = 1; i <= n; i++) {
        stepCount++;          // loop iteration counted
        fact = fact * i;
    }

    return fact;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long result = factorial(n);

    cout << "Factorial = " << result << endl;
    cout << "Step Count = " << stepCount << endl;

    return 0;
}
