// Recursion Basics and Types
#include <iostream>
using namespace std;

// Tail Recursion
void tailRecursion(int n) {
    if (n == 0) return;
    cout << n << " ";
    tailRecursion(n - 1);
}

// Head Recursion
void headRecursion(int n) {
    if (n == 0) return;
    headRecursion(n - 1);
    cout << n << " ";
}

// Tree Recursion
void treeRecursion(int n) {
    if (n == 0) return;
    cout << n << " ";
    treeRecursion(n - 1);
    treeRecursion(n - 1);
}

// Indirect Recursion
void funcB(int n); // forward declaration
void funcA(int n) {
    if (n <= 0) return;
    cout << "A: " << n << endl;
    funcB(n - 1);
}
void funcB(int n) {
    if (n <= 0) return;
    cout << "B: " << n << endl;
    funcA(n / 2);
}

// Nested Recursion
int nestedRec(int n) {
    if (n > 100) return n - 10;
    return nestedRec(nestedRec(n + 11));
}

int main() {
    cout << "Tail Recursion: ";
    tailRecursion(5);
    cout << "\nHead Recursion: ";
    headRecursion(5);
    cout << "\nTree Recursion: ";
    treeRecursion(3);
    cout << "\nIndirect Recursion:\n";
    funcA(10);
    cout << "Nested Recursion: " << nestedRec(95) << endl;
    return 0;
}
