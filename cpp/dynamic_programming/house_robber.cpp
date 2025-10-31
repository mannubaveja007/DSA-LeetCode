// House Robber - LeetCode 198
// Time Complexity: O(n), Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization
    int solveMemo(vector<int>& nums, int n, vector<int>& dp) {
        if (n < 0) return 0;
        if (n == 0) return nums[0];
        if (dp[n] != -1) return dp[n];
        
        int pick = nums[n] + solveMemo(nums, n-2, dp);
        int notPick = solveMemo(nums, n-1, dp);
        
        return dp[n] = max(pick, notPick);
    }
    
    // Method 2: Tabulation
    int robTab(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    
    // Method 3: Space Optimized (Best)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of houses: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Maximum money that can be robbed: " << sol.rob(nums) << endl;
    return 0;
}
