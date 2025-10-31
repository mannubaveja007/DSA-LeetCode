// House Robber - LeetCode 198
// Time Complexity: O(n), Space Complexity: O(1)

import java.util.*;

class HouseRobber {
    // Method 1: Memoization
    public int solveMemo(int[] nums, int n, int[] dp) {
        if (n < 0) return 0;
        if (n == 0) return nums[0];
        if (dp[n] != -1) return dp[n];
        
        int pick = nums[n] + solveMemo(nums, n-2, dp);
        int notPick = solveMemo(nums, n-1, dp);
        
        return dp[n] = Math.max(pick, notPick);
    }
    
    // Method 2: Tabulation
    public int robTab(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    
    // Method 3: Space Optimized (Best)
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int curr = Math.max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HouseRobber sol = new HouseRobber();
        
        System.out.print("Enter number of houses: ");
        int n = sc.nextInt();
        
        int[] nums = new int[n];
        System.out.print("Enter money in each house: ");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        System.out.println("Maximum money that can be robbed: " + sol.rob(nums));
        sc.close();
    }
}
