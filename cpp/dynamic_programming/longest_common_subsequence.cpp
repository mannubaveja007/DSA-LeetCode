// Longest Common Subsequence - LeetCode 1143
// Time Complexity: O(m*n), Space Complexity: O(m*n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization
    int solveMemo(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solveMemo(text1, text2, i-1, j-1, dp);
        }
        return dp[i][j] = max(solveMemo(text1, text2, i-1, j, dp), 
                               solveMemo(text1, text2, i, j-1, dp));
    }
    
    // Method 2: Tabulation
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    // Method 3: Space Optimized
    int longestCommonSubsequenceOptimized(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};

int main() {
    Solution sol;
    string text1, text2;
    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;
    
    cout << "Length of LCS: " << sol.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
