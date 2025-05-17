// Pointer to Pointer (Double Pointer)
#include<iostream>
using namespace std;

int main(){
    int a = 10;            // Declare an integer variable 'a' and initialize it with 10
    int* ptr = &a;         // 'ptr' is a pointer to int, storing the address of 'a'
    int** pptr = &ptr;     // 'pptr' is a pointer to a pointer to int, storing the address of 'ptr'

    // Print the value of variable 'a'
    cout << "Value of a: " << a << endl;

    // Print the address of variable 'a'
    cout << "Address of a: " << &a << endl;

    // Dereferencing 'ptr' gives the value of 'a'
    cout << "Value pointed by ptr: " << *ptr << endl;

    // Print the address of the pointer 'ptr'
    cout << "Address of ptr: " << &ptr << endl;

    // Double dereferencing '**pptr' gives the value of 'a' through 'ptr'
    cout << "Value pointed by **pptr: " << **pptr << endl;

    return 0;
}
