class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = -1e9;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            int cnt = 0;
            while(i<n and nums[i] == 1)
            {
                i++;
                cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};