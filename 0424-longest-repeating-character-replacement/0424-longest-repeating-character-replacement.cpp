class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0,maxi = 0, maxFrequent = 0;
        vector<int>res(26, 0);
        while(right<n)
        {
            res[s[right] - 'A']++;
            maxFrequent = max(maxFrequent, res[s[right] - 'A']);
            //replacing a in babb is better than replacing b {O(1) only}
            if((right - left + 1) - maxFrequent > k)
            {
                res[s[left] - 'A']--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};