class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), cnt = 0, cnt2 = 0;
        for(int i = 0;i<n-1;i++)
            if((nums[i] - nums[i+1]) > 0) cnt++;
        if(cnt == 0) return true;
        else if(cnt  == 1 and nums[0] >= nums[n-1]) return true;
        return false;
    }
};