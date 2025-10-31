// Fibonacci Number - LeetCode 509
// Time Complexity: O(n), Space Complexity: O(n)

import java.util.*;

class Fibonacci {
    // Method 1: Memoization (Top-Down)
    public int fibMemo(int n, int[] dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    }
    
    // Method 2: Tabulation (Bottom-Up)
    public int fibTab(int n) {
        if (n <= 1) return n;
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // Method 3: Space Optimized
    public int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Fibonacci sol = new Fibonacci();
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        System.out.println("Fibonacci(" + n + ") = " + sol.fib(n));
        sc.close();
    }
}
