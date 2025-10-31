// Edit Distance - LeetCode 72
// Time Complexity: O(m*n), Space Complexity: O(m*n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization
    int solveMemo(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (word1[i] == word2[j]) {
            return dp[i][j] = solveMemo(word1, word2, i-1, j-1, dp);
        }
        
        int insertOp = 1 + solveMemo(word1, word2, i, j-1, dp);
        int deleteOp = 1 + solveMemo(word1, word2, i-1, j, dp);
        int replaceOp = 1 + solveMemo(word1, word2, i-1, j-1, dp);
        
        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
    
    // Method 2: Tabulation
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // Base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
    
    // Method 3: Space Optimized
    int minDistanceOptimized(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> prev(n+1), curr(n+1);
        
        for (int j = 0; j <= n; j++) prev[j] = j;
        
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = 1 + min({curr[j-1], prev[j], prev[j-1]});
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};

int main() {
    Solution sol;
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;
    
    cout << "Minimum edit distance: " << sol.minDistance(word1, word2) << endl;
    return 0;
}
