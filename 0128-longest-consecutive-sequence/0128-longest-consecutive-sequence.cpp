class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int n = nums.size();
        int len = 0,maxi = 0;
        for(int i = 0;i<n;i++)
        {
            if(s.find(nums[i]-1) == s.end())
            {
                len = 1;
                int curr = nums[i];
                while(s.count(++curr)) len++;
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};