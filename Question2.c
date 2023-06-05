//Implementing the given piecewise recurrence relation F(n) = F(n-3) + F(n-2) in three different ways in C
//using recursion, dynamic programming (memoization), and iterative approaches.

#include <stdio.h>


//1. Recursion
int recursiveFibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return recursiveFibonacci(n - 3) + recursiveFibonacci(n - 2);
}
/*
Advantages of Recursion:
- Simple and easy to understand.
- Directly follows the recurrence relation.

Disadvantages of Recursion:
- Inefficient for larger values of n due to repeated function calls.
- High time complexity, leading to exponential time complexity O(2^n).
- Can cause stack overflow errors for large values of n.
*/


//2. Dynamic Programming (Memoization)
int memoizationFibonacci(int n, int* memo) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else {
        if (memo[n] != -1)
            return memo[n];
        else {
            memo[n] = memoizationFibonacci(n - 3, memo) + memoizationFibonacci(n - 2, memo);
            return memo[n];
        }
    }
}
/*
Advantages of Dynamic Programming:
- Avoids redundant function calls by memoizing previously computed values.
- Improves time complexity to O(n) due to caching computed results.
- Suitable for larger values of n.

Disadvantages of Dynamic Programming:
- Requires additional memory for memoization table.
- Recursive implementation can still lead to stack overflow errors for very large values of n.
*/

//3. Iterative
int iterativeFibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 2;
    int current;

    for (int i = 3; i <= n; i++) {
        current = prev3 + prev2;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}
/*
Advantages of Iterative:
- Efficient and has linear time complexity O(n).
- Does not suffer from stack overflow issues for large values of n.
- No extra memory overhead.

Disadvantages of Iterative:
- May not be as intuitive as the recursive or memoization approaches.
- It computes all values up to n, even if only F(n) is required.
*/


int main() {
    int n = 10; // Example value for n

    // Recursive approach
    int recursiveResult = recursiveFibonacci(n);
    printf("Recursive Fibonacci(%d) = %d\n", n, recursiveResult);

    // Memoization approach
    int memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    int memoizationResult = memoizationFibonacci(n, memo);
    printf("Memoization Fibonacci(%d) = %d\n", n, memoizationResult);

    // Iterative approach
    int iterativeResult = iterativeFibonacci(n);
    printf("Iterative Fibonacci(%d) = %d\n", n, iterativeResult);

    return 0;
}