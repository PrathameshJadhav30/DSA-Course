// Brute Force Approach
// Problem Link: https://www.leetcode.com/problems/fibonacci-number/
#include <iostream>
using namespace std;

class Solution {
public:
    //  (Recursive)
    int fib(int n) {
        if (n == 0){
            return 0;
        } 
        if (n == 1){
            return 1;
        } 
        // Recursive case
        // fib(n) = fib(n-1) + fib(n-2)
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter value of n (0 <= n <= 30): ";
    cin >> n;

    int result = sol.fib(n);
    cout << "Fibonacci Number : " << result << endl;

    return 0;
}
