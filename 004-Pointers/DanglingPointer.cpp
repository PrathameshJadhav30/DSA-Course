// Dangling Pointer: A dangling pointer is a pointer that points to memory that has been deallocated or is out of scope.
#include<iostream>
using namespace std;

int main(){
    int* ptr = new int(25); //Dynamically allocated memory
    delete ptr; // Memory free

    ptr = nullptr; //Now it's safe. Can check: if(ptr != nullptr)

    cout<<"After delete, ptr is dangling!"<< endl;
    cout<<"*ptr = "<< *ptr <<"(undefined behavior)" << endl; //Dangerous

    return 0;
}