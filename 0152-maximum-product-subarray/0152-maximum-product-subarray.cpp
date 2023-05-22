class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x1 = 1, n = nums.size(), maxi = -1e5;
        for(int i=0;i<n;i++)
        {
            x1 *= nums[i];
            maxi = max(maxi, x1);
            if(x1 == 0) x1 = 1;
        }
        x1 = 1;
        for(int i=n-1;i>=0;i--)
        {
            x1 *= nums[i];
            maxi = max(maxi, x1);
            if(x1 == 0) x1 = 1;
        }
        return maxi;
    }
};