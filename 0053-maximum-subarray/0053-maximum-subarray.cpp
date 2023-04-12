class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxi = -1e9;
        for(auto it:nums)
        {
            curr = max(curr+it, it);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};