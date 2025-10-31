// Climbing Stairs - LeetCode 70
// Time Complexity: O(n), Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization
    int climbStairsMemo(int n, vector<int>& dp) {
        if (n <= 2) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairsMemo(n-1, dp) + climbStairsMemo(n-2, dp);
    }
    
    // Method 2: Tabulation
    int climbStairsTab(int n) {
        if (n <= 2) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // Method 3: Space Optimized (Best)
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
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
    cout << "Enter number of stairs: ";
    cin >> n;
    cout << "Ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
    return 0;
}
