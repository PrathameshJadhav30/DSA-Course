# 🧠 Time and Space Complexity Guide
**Name: Prathamesh Arvind Jadhav**

---

## 1. 📌 Introduction to Complexity Analysis

In competitive programming, understanding how fast and memory-efficient your code is becomes critical. Time and Space Complexity help you predict performance.

- **Time Complexity**: Measures how the runtime of an algorithm increases with input size `n`.
- **Space Complexity**: Measures how much extra memory an algorithm uses as input size `n` increases.

---

## 2. ⏱️ Time Complexity

### 2.1 📖 Definition

Time Complexity is the amount of time taken by an algorithm to run, as a function of the length of the input.

---

### 2.2 📐 Notations

- **Big O (O)**: Worst-case
- **Big Omega (Ω)**: Best-case
- **Big Theta (Θ)**: Average-case (tight bound)

> **Note:** In Competitive Programming, we mostly focus on **Big O**.

---

### 2.3 🧮 Common Time Complexities

| Time Complexity | Description     | Example Algorithm          |
|-----------------|------------------|-----------------------------|
| O(1)            | Constant Time     | Accessing array element     |
| O(log n)        | Logarithmic       | Binary Search               |
| O(n)            | Linear            | Linear Search               |
| O(n log n)      | Linearithmic      | Merge Sort, Heap Sort       |
| O(n²)           | Quadratic         | Bubble Sort, Insertion Sort |
| O(n³)           | Cubic             | Matrix Multiplication       |
| O(2ⁿ)           | Exponential       | Recursive Fibonacci         |
| O(n!)           | Factorial         | Backtracking (e.g. permutations) |

---

### 2.4 🔁 Time Complexity of Loops

#### ✅ Single Loop

```cpp
for (int i = 0; i < n; i++) {
    // constant work
}
```
Time Complexity: O(n)

## ✅ Nested Loop
```
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // constant work
    }
}
```
Time Complexity: O(n²)

## ✅ Logarithmic Loop
```
for (int i = 1; i < n; i *= 2) {
    // constant work
}
```
Time Complexity: O(log n)

## 2.5 🔁 Time Complexity of Recursion
🚀 Example: Fibonacci
```
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```
Recurrence: T(n) = T(n-1) + T(n-2)

Time Complexity: O(2ⁿ)

## ✅ Optimized Fibonacci using DP
```
int fibDP(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
```
Time Complexity: O(n)

Space Complexity: O(n) (can be reduced to O(1))

## 2.6 ⌛ Estimating Time Limit in Competitive Coding
| Input Size `n` | Acceptable Time Complexity |
| -------------- | -------------------------- |
| ≤ 10           | O(n!), O(2ⁿ)               |
| ≤ 100          | O(n³)                      |
| ≤ 1,000        | O(n²)                      |
| ≤ 100,000      | O(n log n)                 |
| ≤ 10⁷          | O(n)                       |
| ≤ 10⁸          | O(1), O(log n)             |

🧠 Rule of Thumb: 1 second ≈ 10⁸ operations

# 3. 💾 Space Complexity
## 3.1 📖 Definition
Space Complexity is the total memory space required by an algorithm with respect to input size n.

Includes:

- Input space

- Auxiliary space (temporary variables, recursion stack)

## 3.2 🧮 Common Space Complexities
| Space Complexity | Example                 |
| ---------------- | ----------------------- |
| O(1)             | In-place algorithms     |
| O(n)             | Arrays, Hash Maps       |
| O(log n)         | Binary Search recursion |
| O(n²)            | 2D arrays               |
## 3.3 🔁 Space in Recursion
```
void recurse(int n) {
    if(n == 0) return;
    recurse(n - 1);
}
```
Time Complexity: O(n)

Space Complexity: O(n) (due to recursion stack)

# 4.💡Tips for Competitive Programming
- Always consider worst-case time complexity.

- Avoid nested loops for large inputs.

- Use efficient data structures (set, map, heap, etc.).

- Estimate runtime using 10⁸ operations/second.

- Convert recursion to iteration to avoid stack overflow.

- Optimize space using in-place algorithms.

- Know when to use fast sorting algorithms (avoid O(n²) if n is large).

# 📊 Summary Table

| Example             | Time Complexity | Space Complexity | Description           |
| ------------------- | --------------- | ---------------- | --------------------- |
| Single Loop         | O(n)            | O(1)             | Linear iteration      |
| Nested Loop         | O(n²)           | O(1)             | Quadratic iteration   |
| Binary Search       | O(log n)        | O(1) or O(log n) | Divide-and-conquer    |
| Recursive Fibonacci | O(2ⁿ)           | O(n)             | Exponential recursion |
| Dynamic Fibonacci   | O(n)            | O(n) or O(1)     | Optimized using DP    |

## Author: Prathamesh Arvind Jadhav
## Topic: Time and Space Complexity for Competitive Programming

