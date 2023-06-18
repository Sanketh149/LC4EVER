class Solution {
public:
    int dp[1<<14][15];
    int mod = 1e9+7;
    int rec(vector<int> &nums, int idx, int prev, int n, int mask)
    {
        if(idx == n) 
        {
            return ((1<<n)-1 == mask);
        }
        int cost = 0;
        if(dp[mask][prev+1] != -1) return dp[mask][prev+1];
        if(prev == -1)
        {
            for(int i = 0;i<n;i++)
            {
                if(mask & (1<<i)) continue;
                else cost += rec(nums, idx+1, i, n, mask|(1<<i));
                cost %= mod;
            }
        }
        else{
            for(int i = 0;i<n;i++)
            {
                if(mask & (1<<i)) continue;
                else{
                    if(nums[i]%nums[prev] == 0 or nums[prev]%nums[i] == 0)
                    {
                        cost += rec(nums, idx+1, i, n, mask|(1<<i));
                        cost %= mod;
                    }
                }
            }
        }
        return dp[mask][prev+1] = cost%mod;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(nums, 0, -1, nums.size(), 0);
    }
};