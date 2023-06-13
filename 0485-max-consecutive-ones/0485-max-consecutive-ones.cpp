class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int curr = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                curr = 0;
            else curr++;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};