class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size(), sum = 0, mini = 1e9;
        while(r<n)
        {
            sum += nums[r];
            while(sum >= target)
            {
                mini = min(mini, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return mini == 1e9?0:mini;
    }
};