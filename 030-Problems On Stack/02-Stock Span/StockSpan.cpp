//Problem Link:https://www.hackerearth.com/problem/algorithm/stock-span-4-a0d4600b-b5c6efe0/
#include <bits/stdc++.h>
using namespace std;

// Function to calculate stock span values
vector<int> calculateSpan(vector<int>& prices, int n) {
    vector<int> span(n);        // Result array
    stack<int> st;              // Stack to store indices

    // Span of first element is always 1
    st.push(0);
    span[0] = 1;

    // Loop through rest of the days
    for (int i = 1; i < n; i++) {
        // Pop elements while stack is not empty and
        // current price is higher than price at top index
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // If stack becomes empty -> price[i] is highest so far
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push this day's index to stack
        st.push(i);
    }
    return span;
}

int main() {
    int n;
    cin >> n; // Number of days

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<int> result = calculateSpan(prices, n);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
