class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin(), ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
        if(lb == n or nums[lb] != target)
            return {-1,-1};
        return {lb,ub};
    }
};