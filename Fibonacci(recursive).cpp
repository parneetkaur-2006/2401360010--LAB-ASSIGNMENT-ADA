#include <iostream>
using namespace std;

int stepCount = 0;

long long fibonacci(int n) {

    stepCount++;   // function call counted

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter position: ";
    cin >> n;

    long long result = fibonacci(n);

    cout << "Fibonacci = " << result << endl;
    cout << "Step Count = " << stepCount << endl;

    return 0;
}
