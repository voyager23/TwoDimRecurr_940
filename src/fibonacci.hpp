#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <vector>

namespace fibonacci {

// Iterative implementation
inline unsigned long long iterative(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    unsigned long long prev = 0, curr = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        unsigned long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// Recursive implementation (inefficient for large n)
inline unsigned long long recursive(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return recursive(n - 1) + recursive(n - 2);
}

// Memoized implementation
inline unsigned long long memoized(unsigned int n, std::vector<unsigned long long>& memo) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != 0) return memo[n];
    memo[n] = memoized(n - 1, memo) + memoized(n - 2, memo);
    return memo[n];
}

inline unsigned long long memoized(unsigned int n) {
    std::vector<unsigned long long> memo(n + 1, 0);
    return memoized(n, memo);
}

} // namespace fibonacci

#endif // FIBONACCI_H
