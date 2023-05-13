class Solution {
public:
    int rec(int idx, vector<int> &dp, vector<int> &res)
    {
        if(idx >= 10001) return 0;
        if(res[idx] != -1) return res[idx];
        int take = idx*dp[idx] + rec(idx+2, dp, res);
        int nottake = rec(idx+1, dp, res);
        return res[idx] = max(take, nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<int>dp(10001, 0);
        vector<int>res(10001, -1);
        for(auto it:nums)
            dp[it]++;
        return rec(0, dp, res);
    }
};