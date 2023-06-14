class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0, left = 0, right = 0;
        vector<int>res(256, -1);
        while(right<n)
        {
            if(res[s[right]] != -1) left = max(res[s[right]]+1, left);
            res[s[right]] = right;
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};