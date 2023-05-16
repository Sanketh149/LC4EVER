class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(auto it:nums){
            if(it > nums[res]) res++;
        }
        return res;
    }
};