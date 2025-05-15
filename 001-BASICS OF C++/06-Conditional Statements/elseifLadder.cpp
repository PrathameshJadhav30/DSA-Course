#include <iostream>
using namespace std;

int main() {
    int score = 75;  // Declare and initialize score

    // Check multiple ranges using else-if ladder
    // Only the first true condition block will execute
    if (score >= 90) {
        cout << "Grade A" << endl;
    } else if (score >= 80) {
        cout << "Grade B" << endl;
    } else if (score >= 70) {
        cout << "Grade C" << endl;
    } else {
        // If none of the above are true
        cout << "Fail" << endl;
    }

    return 0;
}
