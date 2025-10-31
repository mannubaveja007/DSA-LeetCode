// 0/1 Knapsack Problem
// Time Complexity: O(n*W), Space Complexity: O(n*W)

import java.util.*;

class Knapsack01 {
    // Method 1: Memoization
    public int solveMemo(int[] wt, int[] val, int n, int W, int[][] dp) {
        if (n == 0 || W == 0) return 0;
        if (dp[n][W] != -1) return dp[n][W];
        
        if (wt[n-1] <= W) {
            return dp[n][W] = Math.max(
                val[n-1] + solveMemo(wt, val, n-1, W-wt[n-1], dp),
                solveMemo(wt, val, n-1, W, dp)
            );
        } else {
            return dp[n][W] = solveMemo(wt, val, n-1, W, dp);
        }
    }
    
    // Method 2: Tabulation
    public int knapsack(int[] wt, int[] val, int n, int W) {
        int[][] dp = new int[n+1][W+1];
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i-1] <= w) {
                    dp[i][w] = Math.max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][W];
    }
    
    // Method 3: Space Optimized
    public int knapsackOptimized(int[] wt, int[] val, int n, int W) {
        int[] prev = new int[W+1];
        int[] curr = new int[W+1];
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (wt[i-1] <= w) {
                    curr[w] = Math.max(val[i-1] + prev[w-wt[i-1]], prev[w]);
                } else {
                    curr[w] = prev[w];
                }
            }
            prev = curr.clone();
        }
        return prev[W];
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Knapsack01 sol = new Knapsack01();
        
        System.out.print("Enter number of items: ");
        int n = sc.nextInt();
        
        int[] wt = new int[n];
        int[] val = new int[n];
        
        System.out.print("Enter weights: ");
        for (int i = 0; i < n; i++) wt[i] = sc.nextInt();
        
        System.out.print("Enter values: ");
        for (int i = 0; i < n; i++) val[i] = sc.nextInt();
        
        System.out.print("Enter knapsack capacity: ");
        int W = sc.nextInt();
        
        System.out.println("Maximum value: " + sol.knapsack(wt, val, n, W));
        sc.close();
    }
}
