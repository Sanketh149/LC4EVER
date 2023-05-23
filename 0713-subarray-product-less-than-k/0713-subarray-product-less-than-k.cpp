class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1, n = nums.size();
        int j = 0;
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            prod *=  nums[i];
            while(prod >= k and j<i)
            {
                prod /= nums[j];
                j++;
            }
            if(prod<k) count += (i - j + 1);
        }
        return count;
    }
};