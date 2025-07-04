#include <iostream>
using namespace std;

int main() {
    int n = 3, m = 4;
    int matrix[n][m];

    cout << "Enter elements for a 3x4 matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    cout << "Matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
