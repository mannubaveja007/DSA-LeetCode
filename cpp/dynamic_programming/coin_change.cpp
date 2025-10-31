// Coin Change - LeetCode 322
// Time Complexity: O(amount * n), Space Complexity: O(amount)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Memoization
    int solveMemo(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (dp[amount] != -1) return dp[amount];
        
        int mini = INT_MAX;
        for (int coin : coins) {
            int res = solveMemo(coins, amount - coin, dp);
            if (res != INT_MAX) {
                mini = min(mini, res + 1);
            }
        }
        return dp[amount] = mini;
    }
    
    // Method 2: Tabulation (Bottom-Up)
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    int n, amount;
    cout << "Enter number of coin denominations: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Enter target amount: ";
    cin >> amount;
    
    int result = sol.coinChange(coins, amount);
    if (result == -1) {
        cout << "Cannot make the amount with given coins" << endl;
    } else {
        cout << "Minimum coins needed: " << result << endl;
    }
    return 0;
}
