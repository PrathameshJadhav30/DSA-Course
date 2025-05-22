// Better Approach (Iterative Fast Power)
// Problem Link : https://leetcode.com/problems/powx-n/description/
#include <iostream>
using namespace std;

// Fast power function (binary exponentiation)
double myPowFast(double x, int n) {
    long long N = n; // Convert exponent to long long to handle INT_MIN safely

    // If exponent is negative, take reciprocal of base and make exponent positive
    if (N < 0) {
        x = 1 / x;  // Invert base
        N = -N;     // Make exponent positive
    }

    double result = 1.0; // Initialize result to 1.0

    // Loop to apply binary exponentiation
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x; // If exponent is odd, multiply result with current base
        }

        x *= x;     // Square the base
        N /= 2;     // Divide exponent by 2
    }

    return result;
}

int main() {
    double x; // Base value
    int n;    // Exponent value

    cout << "Enter base (x): ";
    cin >> x; // Input base from user

    cout << "Enter exponent (n): ";
    cin >> n; // Input exponent from user

    double result = myPowFast(x, n); // Compute power using fast exponentiation
    cout << "Result using Fast Power: " << result << endl; // Display result
}
