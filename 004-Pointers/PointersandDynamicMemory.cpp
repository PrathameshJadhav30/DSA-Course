//Pointers and Dynamic Memory (new/delete)
#include<iostream>
using namespace std;

int main(){
    int* ptr = new int;  // Dynamically allocating memory
    *ptr = 100;

    cout<<" Dynamically allocated value: "<< *ptr << endl;

    delete ptr;  // deallocated memory

    return 0;
}