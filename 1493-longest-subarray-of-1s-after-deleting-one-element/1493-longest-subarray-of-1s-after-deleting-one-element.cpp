class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        long long int l = 0, r = 0, maxi = -1e9, sum = 0, n = nums.size(), zeros = 0;
        while(r<n)
        {
            sum += nums[r];
            if(nums[r] == 0) zeros++;
            while(zeros > 1)
            {
                if(nums[l] == 0) zeros--;
                sum -= nums[l];
                l++;
            }
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi-1;
    }
};