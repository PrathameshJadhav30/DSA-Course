#include <iostream>
using namespace std;

int power(int a, int b, int m) {
    int result = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1)
            result = (1LL * result * a) % m;
        a = (1LL * a * a) % m;
        b /= 2;
    }
    return result;
}

int main() {
    int a, b, m;
    cout << "Enter base, exponent and modulo: ";
    cin >> a >> b >> m;

    cout << "Result: " << power(a, b, m) << endl;
    return 0;
}
