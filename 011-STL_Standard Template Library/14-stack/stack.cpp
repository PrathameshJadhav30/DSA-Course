// stack in STL
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top of the stack: " << s.top() << endl; // 30

    s.pop(); // removes 30

    cout << "After pop, top: " << s.top() << endl; // 20

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
}
