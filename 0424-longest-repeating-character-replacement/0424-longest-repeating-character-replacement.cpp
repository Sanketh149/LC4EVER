class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0,maxi = 0, rem = k;
        vector<int>res(26, 0);
        while(right<n)
        {
            res[s[right] - 'A']++;
            int maxFrequent = *max_element(res.begin(), res.end());
            // cout<<maxFrequent<<endl;
            while((right - left + 1) - maxFrequent > k)
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