// 0/1 Knapsack Problem
// Time Complexity: O(n*W), Space Complexity: O(n*W)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization
    int solveMemo(vector<int>& wt, vector<int>& val, int n, int W, vector<vector<int>>& dp) {
        if (n == 0 || W == 0) return 0;
        if (dp[n][W] != -1) return dp[n][W];
        
        if (wt[n-1] <= W) {
            return dp[n][W] = max(
                val[n-1] + solveMemo(wt, val, n-1, W-wt[n-1], dp),
                solveMemo(wt, val, n-1, W, dp)
            );
        } else {
            return dp[n][W] = solveMemo(wt, val, n-1, W, dp);
        }
    }
    
    // Method 2: Tabulation
    int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i-1] <= w) {
                    dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][W];
    }
    
    // Method 3: Space Optimized
    int knapsackOptimized(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i-1] <= w) {
                    curr[w] = max(val[i-1] + prev[w-wt[i-1]], prev[w]);
                } else {
                    curr[w] = prev[w];
                }
            }
            prev = curr;
        }
        return prev[W];
    }
};

int main() {
    Solution sol;
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];
    
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> val[i];
    
    cout << "Enter knapsack capacity: ";
    cin >> W;
    
    cout << "Maximum value: " << sol.knapsack(wt, val, n, W) << endl;
    return 0;
}
