#include <iostream>
using namespace std;

int reverseNumber(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(int n) {
    return n == reverseNumber(n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
