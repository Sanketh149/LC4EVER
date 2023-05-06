class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>power(n, 1);
        int mod = 1e9+7;
        for(int i = 1;i<n;i++)
            power[i] = (power[i-1]*2)%mod;
        sort(nums.begin(), nums.end());
        int left = 0, right = n-1;
        int res = 0;
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {
                res += power[right-left];
                left++;
                res %= mod;
            }
            else{
                right--;
            }
        }
        return res%mod;
    }
};