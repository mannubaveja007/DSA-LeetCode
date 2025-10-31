# Longest Common Subsequence - LeetCode 1143
# Time Complexity: O(m*n), Space Complexity: O(m*n)

class Solution:
    # Method 1: Memoization
    def solve_memo(self, text1: str, text2: str, i: int, j: int, dp: dict) -> int:
        if i < 0 or j < 0:
            return 0
        if (i, j) in dp:
            return dp[(i, j)]
        
        if text1[i] == text2[j]:
            dp[(i, j)] = 1 + self.solve_memo(text1, text2, i-1, j-1, dp)
        else:
            dp[(i, j)] = max(self.solve_memo(text1, text2, i-1, j, dp),
                            self.solve_memo(text1, text2, i, j-1, dp))
        return dp[(i, j)]
    
    # Method 2: Tabulation
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[m][n]
    
    # Method 3: Space Optimized
    def longestCommonSubsequence_optimized(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        prev = [0] * (n + 1)
        curr = [0] * (n + 1)
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i-1] == text2[j-1]:
                    curr[j] = 1 + prev[j-1]
                else:
                    curr[j] = max(prev[j], curr[j-1])
            prev = curr[:]
        
        return prev[n]


if __name__ == "__main__":
    sol = Solution()
    text1 = input("Enter first string: ")
    text2 = input("Enter second string: ")
    print(f"Length of LCS: {sol.longestCommonSubsequence(text1, text2)}")
