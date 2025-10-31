# Edit Distance - LeetCode 72
# Time Complexity: O(m*n), Space Complexity: O(m*n)

class Solution:
    # Method 1: Memoization
    def solve_memo(self, word1: str, word2: str, i: int, j: int, dp: dict) -> int:
        if i < 0:
            return j + 1
        if j < 0:
            return i + 1
        if (i, j) in dp:
            return dp[(i, j)]
        
        if word1[i] == word2[j]:
            dp[(i, j)] = self.solve_memo(word1, word2, i-1, j-1, dp)
        else:
            insert_op = 1 + self.solve_memo(word1, word2, i, j-1, dp)
            delete_op = 1 + self.solve_memo(word1, word2, i-1, j, dp)
            replace_op = 1 + self.solve_memo(word1, word2, i-1, j-1, dp)
            dp[(i, j)] = min(insert_op, delete_op, replace_op)
        
        return dp[(i, j)]
    
    # Method 2: Tabulation
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        # Base cases
        for i in range(m + 1):
            dp[i][0] = i
        for j in range(n + 1):
            dp[0][j] = j
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
        
        return dp[m][n]
    
    # Method 3: Space Optimized
    def minDistance_optimized(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        prev = [j for j in range(n + 1)]
        curr = [0] * (n + 1)
        
        for i in range(1, m + 1):
            curr[0] = i
            for j in range(1, n + 1):
                if word1[i-1] == word2[j-1]:
                    curr[j] = prev[j-1]
                else:
                    curr[j] = 1 + min(curr[j-1], prev[j], prev[j-1])
            prev = curr[:]
        
        return prev[n]


if __name__ == "__main__":
    sol = Solution()
    word1 = input("Enter first word: ")
    word2 = input("Enter second word: ")
    print(f"Minimum edit distance: {sol.minDistance(word1, word2)}")
