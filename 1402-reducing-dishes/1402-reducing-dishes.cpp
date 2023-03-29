class Solution {
public:
    int dfs(int i, int prod, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i >= nums.size()) return 0;
        if(dp[i][prod] != -1) return dp[i][prod];
        int take = nums[i]*prod + dfs(i+1, prod+1, nums, dp);
        int notTake = dfs(i+1, prod, nums, dp);
        return dp[i][prod] = max(take, notTake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>dp(n, vector<int> (n+1, -1));
        return dfs(0, 1, satisfaction, dp);
    }
};