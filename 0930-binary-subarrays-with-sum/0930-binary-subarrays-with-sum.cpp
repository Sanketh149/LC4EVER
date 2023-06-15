class Solution {
public:
    int atMost(vector<int> &nums, int goal)
    {
        int n = nums.size(), res = 0, left = 0, right = 0;
        if(goal<0) return 0;
        long long sum = 0;
        while(right < n)
        {
            sum += nums[right];
            while(sum > goal)
            {
                sum -= nums[left];
                left++;
            }
            res += right - left + 1;
            right++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //atmost goal - atmost goal-1
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
    
};