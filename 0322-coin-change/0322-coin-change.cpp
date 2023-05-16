class Solution {
public:
    int rec(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp)
    {
        if(amount == 0) return 0;
        if(idx >= coins.size()) 
            return 1e9;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int take = 1e9;
        int notTake = rec(coins, idx+1, amount, dp);
        if(amount - coins[idx] >= 0)
            take = 1 + rec(coins, idx, amount - coins[idx], dp);
        return dp[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int count = rec(coins, 0, amount, dp);
        return count == 1e9?-1:count;
    }
};