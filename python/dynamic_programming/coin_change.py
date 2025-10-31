# Coin Change - LeetCode 322
# Time Complexity: O(amount * n), Space Complexity: O(amount)

from typing import List

class Solution:
    # Method 1: Memoization
    def solve_memo(self, coins: List[int], amount: int, dp: dict) -> int:
        if amount == 0:
            return 0
        if amount < 0:
            return float('inf')
        if amount in dp:
            return dp[amount]
        
        mini = float('inf')
        for coin in coins:
            res = self.solve_memo(coins, amount - coin, dp)
            if res != float('inf'):
                mini = min(mini, res + 1)
        
        dp[amount] = mini
        return dp[amount]
    
    # Method 2: Tabulation (Bottom-Up)
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0 and dp[i - coin] != float('inf'):
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        
        return dp[amount] if dp[amount] != float('inf') else -1


if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter number of coin denominations: "))
    coins = list(map(int, input("Enter coin values: ").split()))
    amount = int(input("Enter target amount: "))
    
    result = sol.coinChange(coins, amount)
    if result == -1:
        print("Cannot make the amount with given coins")
    else:
        print(f"Minimum coins needed: {result}")
