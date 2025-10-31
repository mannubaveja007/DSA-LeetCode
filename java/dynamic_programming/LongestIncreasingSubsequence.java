// Longest Increasing Subsequence - LeetCode 300
// Time Complexity: O(n^2) for DP, O(n log n) for Binary Search
// Space Complexity: O(n)

import java.util.*;

class LongestIncreasingSubsequence {
    // Method 1: Memoization
    public int solveMemo(int[] nums, int curr, int prev, int[][] dp) {
        if (curr == nums.length) return 0;
        if (dp[curr][prev+1] != -1) return dp[curr][prev+1];
        
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solveMemo(nums, curr+1, curr, dp);
        }
        int notTake = solveMemo(nums, curr+1, prev, dp);
        
        return dp[curr][prev+1] = Math.max(take, notTake);
    }
    
    // Method 2: Tabulation
    public int lengthOfLISTab(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int maxLen = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxLen = Math.max(maxLen, dp[i]);
        }
        return maxLen;
    }
    
    // Method 3: Binary Search (Most Efficient)
    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(nums[0]);
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > temp.get(temp.size()-1)) {
                temp.add(nums[i]);
            } else {
                int idx = Collections.binarySearch(temp, nums[i]);
                if (idx < 0) idx = -(idx + 1);
                temp.set(idx, nums[i]);
            }
        }
        return temp.size();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LongestIncreasingSubsequence sol = new LongestIncreasingSubsequence();
        
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        
        int[] nums = new int[n];
        System.out.print("Enter array elements: ");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        System.out.println("Length of LIS: " + sol.lengthOfLIS(nums));
        sc.close();
    }
}
