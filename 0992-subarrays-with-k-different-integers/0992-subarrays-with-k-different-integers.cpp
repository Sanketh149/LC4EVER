class Solution {
public:
    int atMost(vector<int> &nums, int k)
    {
        unordered_map<int,int>mp;
        int res = 0, n = nums.size(), l = 0, r = 0;
        while(r<n)
        {
            mp[nums[r]]++;
            while(mp.size() > k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            res += (r - l + 1);
            r++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};