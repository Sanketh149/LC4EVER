class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int cnt = 0, last = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(i+nums[i] > maxi)
            {
                maxi = i+nums[i];
            }
            if(last == i)
            {
                last = maxi;
                cnt++;
            }
        }
        return cnt;
    }
};