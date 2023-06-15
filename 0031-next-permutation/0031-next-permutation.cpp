class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakPt = -1, n = nums.size();
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                breakPt = i;
                break;
            }
        }
        if(breakPt == -1) 
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n-1;i>=0;i--)
        {
            if(nums[breakPt] < nums[i])
            {
                swap(nums[breakPt], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+breakPt+1, nums.end());
    }
};