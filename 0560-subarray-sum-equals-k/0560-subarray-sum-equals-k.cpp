class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum = 0,cnt = 0;
        map<int,int>mp;
        mp[0] = 1;
        for(auto it:nums)
        {
            presum += it;
            int remaining = presum - k;
            cnt += mp[remaining];
            mp[presum]++;
        }
        return cnt;
    }
};