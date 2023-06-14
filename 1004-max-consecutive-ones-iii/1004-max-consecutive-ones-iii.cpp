class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zeros = 0, maxi = 0, n = nums.size();
        while(right < n)
        {
            if(nums[right] == 0 and zeros == k)
            {
                zeros++;
                while(left<=right and zeros>k)
                {
                    if(nums[left] == 0) zeros--;
                    left++;
                }
            }
            else if(nums[right] == 0 and zeros<k) zeros++;
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};