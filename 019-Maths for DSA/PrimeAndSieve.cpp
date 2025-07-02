#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    cout << "Primes up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (prime[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter a number to check prime and print primes till N: ";
    cin >> num;

    cout << (isPrime(num) ? "Prime" : "Not Prime") << endl;
    sieve(num);
    return 0;
}
