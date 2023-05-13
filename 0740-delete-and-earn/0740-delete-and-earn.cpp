class Solution {
public:
    int rec(int idx, vector<int> &dp, vector<int> &nums)
    {
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int currsum = nums[idx];
        int ptr = idx+1;
        while(ptr<nums.size() and nums[ptr] == nums[idx])
        {
            currsum += nums[ptr];
            ptr++;
        }
        while(ptr<nums.size() and nums[ptr] == nums[idx]+1) 
            ptr++;
        return dp[idx] = max(currsum + rec(ptr, dp, nums), rec(idx+1, dp, nums));
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>dp(20001, -1);
        return rec(0, dp, nums);
    }
};