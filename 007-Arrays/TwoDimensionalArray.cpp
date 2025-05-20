// Two-Dimensional Array (Matrix)
#include<iostream>
using namespace std;

int main(){
    int mat[2][3];  // Declaration of a 2x3 matrix

    // Initialization of another 2x3 matrix
    int mat1[2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "Enter elements for 2x3 matrix:\n";
    // Input values into mat
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
        }
    }

    cout << "Matrix is:\n";
    // Display values of mat
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // Display values of initialized mat1
    cout << "Matrix is:\n";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
 1 2 