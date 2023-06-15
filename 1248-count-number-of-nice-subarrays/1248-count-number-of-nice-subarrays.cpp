class Solution {
public:
    int atMost(vector<int>& nums, int k)
    {
        if(k < 0) return 0;
        int sum = 0, res = 0, l = 0, r = 0, n = nums.size();
        while(r<n)
        {
            sum += (nums[r]&1);
            while(sum > k)
            {
                sum -= (nums[l]&1);
                l++;
            }
            res += (r - l + 1);
            r++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};