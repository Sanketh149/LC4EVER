class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return nums;
        vector<int>avg(n, -1);
        if(2*k+1 > n) return avg;
        int divi = 2*k+1;
        long long curr = 0;
        for(int i = 0;i<2*k+1;i++)
            curr += nums[i];
        avg[k] = curr/divi;
        for(int i = 2*k+1;i<n;i++)
        {
            curr = curr - nums[i - (2*k+1)] + nums[i];
            avg[i - k] = (curr/divi);
        }
        return avg;
    }
};