// Coin Change - LeetCode 322
// Time Complexity: O(amount * n), Space Complexity: O(amount)

import java.util.*;

class CoinChange {
    // Method 1: Memoization
    public int solveMemo(int[] coins, int amount, int[] dp) {
        if (amount == 0) return 0;
        if (amount < 0) return Integer.MAX_VALUE;
        if (dp[amount] != -1) return dp[amount];
        
        int mini = Integer.MAX_VALUE;
        for (int coin : coins) {
            int res = solveMemo(coins, amount - coin, dp);
            if (res != Integer.MAX_VALUE) {
                mini = Math.min(mini, res + 1);
            }
        }
        return dp[amount] = mini;
    }
    
    // Method 2: Tabulation (Bottom-Up)
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CoinChange sol = new CoinChange();
        
        System.out.print("Enter number of coin denominations: ");
        int n = sc.nextInt();
        int[] coins = new int[n];
        
        System.out.print("Enter coin values: ");
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }
        
        System.out.print("Enter target amount: ");
        int amount = sc.nextInt();
        
        int result = sol.coinChange(coins, amount);
        if (result == -1) {
            System.out.println("Cannot make the amount with given coins");
        } else {
            System.out.println("Minimum coins needed: " + result);
        }
        sc.close();
    }
}
