class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long int l = 0, r = 0, ans = -1e9, n = nums.size(), sum = 0;
        while(r<n)
        {
            sum += nums[r];
            while((r-l+1)*nums[r] - sum> k) //size*nums[i] - sum> k (invalid window)
            {
                sum -= nums[l];
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};