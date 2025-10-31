# House Robber - LeetCode 198
# Time Complexity: O(n), Space Complexity: O(1)

from typing import List

class Solution:
    # Method 1: Memoization
    def solve_memo(self, nums: List[int], n: int, dp: dict) -> int:
        if n < 0:
            return 0
        if n == 0:
            return nums[0]
        if n in dp:
            return dp[n]
        
        pick = nums[n] + self.solve_memo(nums, n-2, dp)
        not_pick = self.solve_memo(nums, n-1, dp)
        
        dp[n] = max(pick, not_pick)
        return dp[n]
    
    # Method 2: Tabulation
    def rob_tab(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, n):
            dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        
        return dp[n-1]
    
    # Method 3: Space Optimized (Best)
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        
        prev2 = nums[0]
        prev1 = max(nums[0], nums[1])
        
        for i in range(2, n):
            curr = max(nums[i] + prev2, prev1)
            prev2 = prev1
            prev1 = curr
        
        return prev1


if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter number of houses: "))
    nums = list(map(int, input("Enter money in each house: ").split()))
    print(f"Maximum money that can be robbed: {sol.rob(nums)}")
