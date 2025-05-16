#include <iostream>
using namespace std;

// 1. No arguments, no return
void showMessage() {
    cout << "Welcome!" << endl;
}

// 2. With argument, no return
void greet(string name) {
    cout << "Hello " << name << endl;
}

// 3. No arguments, with return
int giveNumber() {
    return 10;
}

// 4. With arguments, with return
int square(int x) {
    return x * x;
}

int main() {
    showMessage();             // No args, no return
    greet("Prathamesh");       // With args, no return
    cout << giveNumber() << endl;     // No args, with return
    cout << square(5) << endl;        // With args, with return
    return 0;
}
