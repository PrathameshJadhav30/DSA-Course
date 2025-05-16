#include <iostream>
using namespace std;

void change(int &a) {
    a = 10;
}

int main() {
    int x = 5;
    change(x);
    cout << "x = " << x << endl;  // x becomes 10
    return 0;
}
