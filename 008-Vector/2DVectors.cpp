// 2D Vectors
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a 3x4 2D vector initialized with 0
    vector<vector<int>> matrix(3, vector<int>(4, 0));

    matrix[1][2] = 5; // Set value at 2nd row, 3rd column to 5

    cout << "2D Matrix:\n";
    // Print the 2D vector
    for (auto row : matrix) {
        for (auto val : row){
           cout << val << " ";
        }
            
        cout << "\n";
    }

    return 0;
}
