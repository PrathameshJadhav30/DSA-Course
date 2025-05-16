#include <iostream>
using namespace std;

// Declaration
int add(int, int);

int main() {
    cout << add(2, 3);
    return 0;
}

// Definition
int add(int a, int b) {
    return a + b;
}
