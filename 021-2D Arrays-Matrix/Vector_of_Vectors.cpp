#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3, m = 3;
    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter elements for 3x3 matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    cout << "Matrix:\n";
    for (auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
