// Optimal Approach - Dynamic Programming (Bottom-Up)
// Problem Link: https://www.leetcode.com/problems/fibonacci-number/
#include <iostream>
using namespace std;

class Solution {
public:
    //  Optimal (Iterative Bottom-Up DP)
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int prev2 = 0;  // F(0)
        int prev1 = 1;  // F(1)
        int current;

        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
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

