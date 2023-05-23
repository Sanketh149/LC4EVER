class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1, suff = 1, n = nums.size(), maxi = -1e9;
        for(int i = 0;i<n;i++)
        {
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            pre *= nums[i];
            suff *= nums[n - i - 1];
            maxi = max({maxi, pre, suff});
        }
        return maxi;
    }
};