// Longest Increasing Subsequence - LeetCode 300
// Time Complexity: O(n^2) for DP, O(n log n) for Binary Search
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization
    int solveMemo(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
        if (curr == nums.size()) return 0;
        if (dp[curr][prev+1] != -1) return dp[curr][prev+1];
        
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solveMemo(nums, curr+1, curr, dp);
        }
        int notTake = solveMemo(nums, curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(take, notTake);
    }
    
    // Method 2: Tabulation
    int lengthOfLISTab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
    
    // Method 3: Binary Search (Most Efficient)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Length of LIS: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}
