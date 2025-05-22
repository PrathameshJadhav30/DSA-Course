// Brute Force Approach
// Problem Link : https://leetcode.com/problems/powx-n/description/
#include <iostream>
#include <cmath>
using namespace std;

// Brute force power function
double myPowBruteForce(double x, int n) {
    // Convert n to long long to safely handle large negative values (e.g., -2^31)
    long long power = abs((long long)n); 

    double result = 1.0; // Initialize result to 1.0 (multiplicative identity)

    // Multiply x by itself 'power' times
    for (long long i = 0; i < power; i++) 
    {
        result *= x; // Accumulate the result
    }

    // If exponent is negative, return reciprocal
    return n < 0 ? 1.0 / result : result;
}

int main() {
    double x; // Base value
    int n;    // Exponent value

    cout << "Enter base (x): ";
    cin >> x; // Take base input from user

    cout << "Enter exponent (n): ";
    cin >> n; // Take exponent input from user

    double result = myPowBruteForce(x, n); // Call brute force power function
    cout << "Result using Brute Force: " << result << endl; // Display result
}
