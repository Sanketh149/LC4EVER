class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        for(auto it:s)
        {
            if(s.find(it-1) == s.end())
            {
                int x = it;
                int cnt = 0;
                while(s.find(x) != s.end())
                {
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};