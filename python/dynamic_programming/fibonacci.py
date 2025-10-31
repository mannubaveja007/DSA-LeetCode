# Fibonacci Number - LeetCode 509
# Time Complexity: O(n), Space Complexity: O(n)

class Solution:
    # Method 1: Memoization (Top-Down)
    def fib_memo(self, n: int, dp: dict) -> int:
        if n <= 1:
            return n
        if n in dp:
            return dp[n]
        dp[n] = self.fib_memo(n-1, dp) + self.fib_memo(n-2, dp)
        return dp[n]
    
    # Method 2: Tabulation (Bottom-Up)
    def fib_tab(self, n: int) -> int:
        if n <= 1:
            return n
        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
    
    # Method 3: Space Optimized
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        prev2, prev1 = 0, 1
        for i in range(2, n + 1):
            curr = prev1 + prev2
            prev2 = prev1
            prev1 = curr
        return prev1


if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter n: "))
    print(f"Fibonacci({n}) = {sol.fib(n)}")
