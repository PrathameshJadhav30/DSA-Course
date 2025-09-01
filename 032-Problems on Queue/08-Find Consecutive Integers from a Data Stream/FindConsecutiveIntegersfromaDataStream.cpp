//Problem Link: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description
#include <bits/stdc++.h>
using namespace std;

class DataStream {
private:
    int value;       // the target value to check
    int k;           // how many consecutive numbers required
    int count;       // counts how many recent consecutive == value

public:
    // Constructor
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        this->count = 0;
    }

    // Add number to stream and check condition
    bool consec(int num) {
        if (num == value) {
            count++;  // increase streak of value
        } else {
            count = 0; // reset streak if not equal
        }
        return (count >= k);
    }
};

int main() {
    DataStream dataStream(4, 3); // value = 4, k = 3

    cout << boolalpha; // print "true/false" instead of 1/0
    cout << dataStream.consec(4) << endl; // false
    cout << dataStream.consec(4) << endl; // false
    cout << dataStream.consec(4) << endl; // true
    cout << dataStream.consec(3) << endl; // false

    return 0;
}
