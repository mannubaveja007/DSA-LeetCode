// Longest Common Subsequence - LeetCode 1143
// Time Complexity: O(m*n), Space Complexity: O(m*n)

import java.util.*;

class LongestCommonSubsequence {
    // Method 1: Memoization
    public int solveMemo(String text1, String text2, int i, int j, int[][] dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (text1.charAt(i) == text2.charAt(j)) {
            return dp[i][j] = 1 + solveMemo(text1, text2, i-1, j-1, dp);
        }
        return dp[i][j] = Math.max(solveMemo(text1, text2, i-1, j, dp), 
                                    solveMemo(text1, text2, i, j-1, dp));
    }
    
    // Method 2: Tabulation
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[][] dp = new int[m+1][n+1];
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i-1) == text2.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    // Method 3: Space Optimized
    public int longestCommonSubsequenceOptimized(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[] prev = new int[n+1];
        int[] curr = new int[n+1];
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i-1) == text2.charAt(j-1)) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = Math.max(prev[j], curr[j-1]);
                }
            }
            prev = curr.clone();
        }
        return prev[n];
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LongestCommonSubsequence sol = new LongestCommonSubsequence();
        
        System.out.print("Enter first string: ");
        String text1 = sc.next();
        System.out.print("Enter second string: ");
        String text2 = sc.next();
        
        System.out.println("Length of LCS: " + sol.longestCommonSubsequence(text1, text2));
        sc.close();
    }
}
