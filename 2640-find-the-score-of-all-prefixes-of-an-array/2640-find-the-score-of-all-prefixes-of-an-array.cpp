class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxi(n, 0);
        maxi[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            maxi[i] = max(maxi[i-1], nums[i]);
        }
        vector<long long>res(n, 0);
        res[0] = 2*nums[0];
        for(int i = 1;i<n;i++)
        {
            res[i] = res[i-1]+nums[i]+maxi[i];
        }
        return res;
    }
};