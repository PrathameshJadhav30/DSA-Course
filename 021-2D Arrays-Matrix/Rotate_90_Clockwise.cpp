#include <iostream>
#include <algorithm> // for std::reverse
using namespace std;

int main() {
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    // Transpose
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            swap(matrix[i][j], matrix[j][i]);

    // Reverse each row
    for (int i = 0; i < 3; i++)
        reverse(matrix[i], matrix[i] + 3);

    cout << "Matrix after rotating 90° clockwise:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
