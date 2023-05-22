class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum = 0,cnt = 0;
        map<int,int>mp;
        for(auto it:nums)
        {
            presum += it;
            if(presum == k) cnt++;
            int remaining = presum - k;
            cnt += mp[remaining];
            mp[presum]++;
        }
        return cnt;
    }
};