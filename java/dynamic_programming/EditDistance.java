// Edit Distance - LeetCode 72
// Time Complexity: O(m*n), Space Complexity: O(m*n)

import java.util.*;

class EditDistance {
    // Method 1: Memoization
    public int solveMemo(String word1, String word2, int i, int j, int[][] dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (word1.charAt(i) == word2.charAt(j)) {
            return dp[i][j] = solveMemo(word1, word2, i-1, j-1, dp);
        }
        
        int insertOp = 1 + solveMemo(word1, word2, i, j-1, dp);
        int deleteOp = 1 + solveMemo(word1, word2, i-1, j, dp);
        int replaceOp = 1 + solveMemo(word1, word2, i-1, j-1, dp);
        
        return dp[i][j] = Math.min(insertOp, Math.min(deleteOp, replaceOp));
    }
    
    // Method 2: Tabulation
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m+1][n+1];
        
        // Base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i-1) == word2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i][j-1], 
                                Math.min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
    
    // Method 3: Space Optimized
    public int minDistanceOptimized(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[] prev = new int[n+1];
        int[] curr = new int[n+1];
        
        for (int j = 0; j <= n; j++) prev[j] = j;
        
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i-1) == word2.charAt(j-1)) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = 1 + Math.min(curr[j-1], 
                                Math.min(prev[j], prev[j-1]));
                }
            }
            prev = curr.clone();
        }
        return prev[n];
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        EditDistance sol = new EditDistance();
        
        System.out.print("Enter first word: ");
        String word1 = sc.next();
        System.out.print("Enter second word: ");
        String word2 = sc.next();
        
        System.out.println("Minimum edit distance: " + sol.minDistance(word1, word2));
        sc.close();
    }
}
