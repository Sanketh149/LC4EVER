class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0, mini = 1e9;
        while(right<n)
        {
            sum += nums[right];
            while(sum >= target)
            {
                mini = min(mini, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return mini == 1e9?0:mini;
    }
};