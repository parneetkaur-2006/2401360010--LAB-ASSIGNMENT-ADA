#include <iostream>
using namespace std;

int stepCount = 0;

long long factorial(int n) {

    stepCount++;   // function call counted

    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
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
