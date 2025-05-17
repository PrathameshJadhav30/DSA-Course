// Pointer to different Datatypes
#include <iostream>  
using namespace std; 

int main() {
    int a = 5;           // Declare an integer variable and initialize it with 5
    float b = 3.14;      // Declare a float variable and initialize it with 3.14
    char c = 'A';        // Declare a char variable and initialize it with 'A'

    // Declare pointer variables and assign them the addresses of a, b, and c
    int* p1 = &a;        // p1 points to the address of integer variable a
    float* p2 = &b;      // p2 points to the address of float variable b
    char* p3 = &c;       // p3 points to the address of char variable c

    // Dereference the pointers to access and print the values they point to
    cout << "*p1 = " << *p1 << endl;  // Outputs: *p1 = 5
    cout << "*p2 = " << *p2 << endl;  // Outputs: *p2 = 3.14
    cout << "*p3 = " << *p3 << endl;  // Outputs: *p3 = A

    return 0; 
}
