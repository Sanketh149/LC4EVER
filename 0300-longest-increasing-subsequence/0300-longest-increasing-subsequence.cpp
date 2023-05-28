class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if(it>=lis.size()) lis.push_back(nums[i]);
            else lis[it] = nums[i];
        }
        return lis.size();
    }
};