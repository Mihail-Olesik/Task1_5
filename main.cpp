#include <iostream>
#include <chrono>

using namespace std;

int factorial(int n) {
    if(n > 0)
        return n * factorial(n - 1);
    if (n == 0)
        return 1; 
    else
        return 0;
}

int main() {
    unsigned int fact;
    int n = 255;
    auto begin = chrono::steady_clock::now();
    fact = factorial(n);
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << elapsed_ms.count() << " ns" << endl;
    begin = chrono::steady_clock::now();
    fact = 1;
    if (n < 0)
        fact = 0;
    if (n == 0)
        fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    end = chrono::steady_clock::now();
    elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << elapsed_ms.count() << " ns" << endl;
}