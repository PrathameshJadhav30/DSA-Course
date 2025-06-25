#include <iostream>
using namespace std;

bool bruteForceMatch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++) 
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]){
            j++;
        }
        if (j == m){
            cout << "Pattern found at index: " << i << endl;
            return true;
        }
    }
    return false;
}

int main() {
    string text = "helloworld", pattern = "world";
    cout << "Pattern Found: " << bruteForceMatch(text, pattern) << endl;
    return 0;
}
