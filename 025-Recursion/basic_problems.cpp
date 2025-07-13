// Common Recursive Problems
#include <iostream>
using namespace std;

// 1. Factorial
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

// 2. Fibonacci
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// 3. Print 1 to N
void print1ToN(int n) {
    if (n == 0) return;
    print1ToN(n - 1);
    cout << n << " ";
}

// 4. Sum of Digits
int sumDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumDigits(n / 10);
}

// 5. Reverse a String
void reverseStr(string &s, int i, int j) {
    if (i >= j) return;
    swap(s[i], s[j]);
    reverseStr(s, i + 1, j - 1);
}

int main() {
    cout << "Factorial of 5: " << fact(5) << endl;
    cout << "Fibonacci of 6: " << fib(6) << endl;
    cout << "Print 1 to 5: ";
    print1ToN(5);
    cout << "\nSum of digits (1234): " << sumDigits(1234) << endl;

    string s = "hello";
    reverseStr(s, 0, s.size() - 1);
    cout << "Reversed String: " << s << endl;

    return 0;
}
