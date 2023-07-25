class Solution {
public:
    int dp[101];
    int rec(int i, vector<int> &nums)
    {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i]+rec(i+2, nums);
        int nottake = rec(i+1, nums);
        return dp[i] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, nums);
    }
};