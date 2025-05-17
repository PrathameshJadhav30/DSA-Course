// Changing Values Using Pointers: You can change a variable’s value indirectly using a pointer.
#include<iostream>
using namespace std;

int main(){
    int x = 5;
    int* ptr = &x;

    *ptr = 20; // Changes x through the pointer

    cout<<"x = " << x << endl;  // output: 20
    return 0;
}