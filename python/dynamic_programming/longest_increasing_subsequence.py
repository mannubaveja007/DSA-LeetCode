# Longest Increasing Subsequence - LeetCode 300
# Time Complexity: O(n^2) for DP, O(n log n) for Binary Search
# Space Complexity: O(n)

from typing import List
import bisect

class Solution:
    # Method 1: Memoization
    def solve_memo(self, nums: List[int], curr: int, prev: int, dp: dict) -> int:
        if curr == len(nums):
            return 0
        if (curr, prev) in dp:
            return dp[(curr, prev)]
        
        take = 0
        if prev == -1 or nums[curr] > nums[prev]:
            take = 1 + self.solve_memo(nums, curr+1, curr, dp)
        not_take = self.solve_memo(nums, curr+1, prev, dp)
        
        dp[(curr, prev)] = max(take, not_take)
        return dp[(curr, prev)]
    
    # Method 2: Tabulation
    def lengthOfLIS_tab(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        max_len = 1
        
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            max_len = max(max_len, dp[i])
        
        return max_len
    
    # Method 3: Binary Search (Most Efficient)
    def lengthOfLIS(self, nums: List[int]) -> int:
        temp = [nums[0]]
        
        for i in range(1, len(nums)):
            if nums[i] > temp[-1]:
                temp.append(nums[i])
            else:
                idx = bisect.bisect_left(temp, nums[i])
                temp[idx] = nums[i]
        
        return len(temp)


if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter array size: "))
    nums = list(map(int, input("Enter array elements: ").split()))
    print(f"Length of LIS: {sol.lengthOfLIS(nums)}")
