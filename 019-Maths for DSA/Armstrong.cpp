#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

bool isArmstrong(int n) {
    int original = n, sum = 0, digits = countDigits(n);
    while (n != 0) {
        int rem = n % 10;
        sum += pow(rem, digits);
        n /= 10;
    }
    return sum == original;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << (isArmstrong(n) ? "Armstrong Number" : "Not Armstrong") << endl;
    return 0;
}
