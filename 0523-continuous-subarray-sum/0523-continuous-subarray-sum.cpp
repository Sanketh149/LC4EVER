class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long int sum = 0, n = nums.size();
        unordered_map<long long int, long long int>mp;
        mp[0] = -1;
        for(long long int i = 0;i<n;i++)
        {
            sum += nums[i];
            if(sum % k == 0 & i>0) return true;
            if(k)
                sum %= k;
            if(mp.find(sum) != mp.end())
            {
                if(i - mp[sum] >= 2) //length atleast 2
                    return true;
            }
            else mp[sum] = i;
        }
        return false;
    }
};