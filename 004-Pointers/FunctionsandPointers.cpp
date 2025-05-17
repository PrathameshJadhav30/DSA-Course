// Functions and Pointers (Pass by Reference)
#include<iostream>
using namespace std;

///Function that swap two integers using pointers
void Swap(int* x, int* y){
   int temp = *x; // store value of x in temp
   *x = *y; //copy value of y into x
   *y = temp; // copy temp(original x) into y
}
int main(){
    int a = 10, b = 20;

    cout << "Before Swapping:\n";
    cout<<"a = "<< a << ", b = "<< b <<endl;

    //pass the address of a and b to swap function
    Swap(&a, &b);

     cout << "After Swapping:\n";
    cout<<"a = "<< a << ", b = "<< b <<endl;

    return 0;
}