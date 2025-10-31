# Climbing Stairs - LeetCode 70
# Time Complexity: O(n), Space Complexity: O(1)

class Solution:
    # Method 1: Memoization
    def climb_stairs_memo(self, n: int, dp: dict) -> int:
        if n <= 2:
            return n
        if n in dp:
            return dp[n]
        dp[n] = self.climb_stairs_memo(n-1, dp) + self.climb_stairs_memo(n-2, dp)
        return dp[n]
    
    # Method 2: Tabulation
    def climb_stairs_tab(self, n: int) -> int:
        if n <= 2:
            return n
        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
    
    # Method 3: Space Optimized (Best)
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        prev2, prev1 = 1, 2
        for i in range(3, n + 1):
            curr = prev1 + prev2
            prev2 = prev1
            prev1 = curr
        return prev1


if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter number of stairs: "))
    print(f"Ways to climb {n} stairs: {sol.climbStairs(n)}")
