class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefix(n+1, 0), suffix(n+1, 0);
        long long mul = 1<<k;
        for(int i = 1;i<n+1;i++)
            prefix[i] = prefix[i-1]|nums[i-1];
        for(int i = n-1;i>=0;i--)
            suffix[i] = suffix[i+1]|nums[i];
        long long maxi = 0;
        for(int i = 0;i<n;i++)
            maxi = max(maxi, (prefix[i] | (nums[i]*mul) | suffix[i+1]));
        return maxi;
    }
};