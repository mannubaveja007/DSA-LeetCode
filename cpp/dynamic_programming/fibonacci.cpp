// Fibonacci Number - LeetCode 509
// Time Complexity: O(n), Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization (Top-Down)
    int fibMemo(int n, vector<int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    }
    
    // Method 2: Tabulation (Bottom-Up)
    int fibTab(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // Method 3: Space Optimized
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << sol.fib(n) << endl;
    return 0;
}
