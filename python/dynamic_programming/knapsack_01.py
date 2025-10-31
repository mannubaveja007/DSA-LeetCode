# 0/1 Knapsack Problem
# Time Complexity: O(n*W), Space Complexity: O(n*W)

from typing import List

class Solution:
    # Method 1: Memoization
    def solve_memo(self, wt: List[int], val: List[int], n: int, W: int, dp: dict) -> int:
        if n == 0 or W == 0:
            return 0
        if (n, W) in dp:
            return dp[(n, W)]
        
        if wt[n-1] <= W:
            dp[(n, W)] = max(
                val[n-1] + self.solve_memo(wt, val, n-1, W-wt[n-1], dp),
                self.solve_memo(wt, val, n-1, W, dp)
            )
        else:
            dp[(n, W)] = self.solve_memo(wt, val, n-1, W, dp)
        
        return dp[(n, W)]
    
    # Method 2: Tabulation
    def knapsack(self, wt: List[int], val: List[int], n: int, W: int) -> int:
        dp = [[0] * (W + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            for w in range(1, W + 1):
                if wt[i-1] <= w:
                    dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w])
                else:
                    dp[i][w] = dp[i-1][w]
        
        return dp[n][W]
    
    # Method 3: Space Optimized
    def knapsack_optimized(self, wt: List[int], val: List[int], n: int, W: int) -> int:
        prev = [0] * (W + 1)
        curr = [0] * (W + 1)
        
        for i in range(1, n + 1):
            for w in range(1, W + 1):
                if wt[i-1] <= w:
                    curr[w] = max(val[i-1] + prev[w-wt[i-1]], prev[w])
                else:
                    curr[w] = prev[w]
            prev = curr[:]
        
        return prev[W]


if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter number of items: "))
    wt = list(map(int, input("Enter weights: ").split()))
    val = list(map(int, input("Enter values: ").split()))
    W = int(input("Enter knapsack capacity: "))
    
    print(f"Maximum value: {sol.knapsack(wt, val, n, W)}")
