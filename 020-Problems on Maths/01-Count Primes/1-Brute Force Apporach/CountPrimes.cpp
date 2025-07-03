// Brute Force Apporach
//Problem Link: https://leetcode.com/problems/count-primes/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int num) 
    {
        if (num < 2){
           return false; // Not prime
        } 
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false; // Not prime
        }
        return true;
    }

    int countPrimes(int n) 
    {
        int count = 0;
        for (int i = 2; i < n; i++) 
        {
            if (isPrime(i)){
               count++; // Count if prime
            } 
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n = 10;
    cout << "Count of primes less than " << n << ": " << sol.countPrimes(n) << endl;
    return 0;
}
