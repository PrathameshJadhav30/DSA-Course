// What is a Pointer: A pointer is a variable that stores the memory address of another variable.

#include<iostream>
using namespace std;

int main(){
    int x = 10;
    int* ptr = &x;  // Pointer holds the address of x

    cout<<"Value of x: "<< x << endl;
    cout<<"Address of x: "<< &x << endl;
    cout<<"Pointer ptr Holds: "<< ptr << endl;
    cout<<"Value pointed by ptr: "<< *ptr << endl;

    return 0;
}