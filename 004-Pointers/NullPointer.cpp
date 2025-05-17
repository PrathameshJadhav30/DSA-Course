//Null Pointer : A null pointer is a pointer that does not point to any valid memory location
#include<iostream>
using namespace std;

int main(){
    int* ptr = nullptr; // Initialize a pointer to Null(it points to Nothing)

    //check if the pointer is null before using it
    if(ptr == nullptr){
        cout<<"Pointer is Null. It doesn't point to any valid memory."<< endl;
    }

    //assign it to valid variable
    int a = 50;
    ptr = &a; // Now the pointer points to the address of "a"

    //dereferencing the pointer after assigning the valid address
    cout<<"Pointer is now pointing to a: "<< *ptr << endl;

    return 0;
}