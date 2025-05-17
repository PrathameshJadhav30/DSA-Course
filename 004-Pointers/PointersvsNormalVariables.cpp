//Pointers vs Normal Variables

#include <iostream> 
using namespace std; 

int main() {
    int x = 42;      // Declare an integer variable 'x' and initialize it with 42
    int* p = &x;     // Declare a pointer 'p' that stores the address of 'x'

    // Print the value of x and its memory address
    cout << "x = " << x << ", &x = " << &x << endl;

    // Print the value pointed to by p (i.e., value of x) and the address stored in p
    cout << "*p = " << *p << ", p = " << p << endl;

    return 0; 
}
