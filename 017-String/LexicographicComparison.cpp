#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> words = {"banana", "apple", "grape"};
    sort(words.begin(), words.end()); // lexicographical sort
    for (string w : words) 
    {
        cout << w << " ";
    }
    cout << endl;

    cout << "Compare apple < banana: " << ("apple" < "banana") << endl;
    return 0;
}
