// Three-Dimensional Array (3D)
#include<iostream>
using namespace std;

int main(){
    int cube[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    }; // 3D array with 2 layers, 2 rows, 2 columns

    cout << "3D Array Elements:\n";
    for(int i = 0; i < 2; i++) // Loop through layers
    {
        cout << "Layer " << i + 1 << ":\n";
        for(int j = 0; j < 2; j++) // Loop through rows
        {
            for(int k = 0; k < 2; k++) // Loop through columns
            {
                cout << cube[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
