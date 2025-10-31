// Climbing Stairs - LeetCode 70
// Time Complexity: O(n), Space Complexity: O(1)

import java.util.*;

class ClimbingStairs {
    // Method 1: Memoization
    public int climbStairsMemo(int n, int[] dp) {
        if (n <= 2) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairsMemo(n-1, dp) + climbStairsMemo(n-2, dp);
    }
    
    // Method 2: Tabulation
    public int climbStairsTab(int n) {
        if (n <= 2) return n;
        int[] dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // Method 3: Space Optimized (Best)
    public int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ClimbingStairs sol = new ClimbingStairs();
        System.out.print("Enter number of stairs: ");
        int n = sc.nextInt();
        System.out.println("Ways to climb " + n + " stairs: " + sol.climbStairs(n));
        sc.close();
    }
}
