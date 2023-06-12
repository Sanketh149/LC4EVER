class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = size(s);
        vector<int>res(256,-1);
        int begin = -1,maxi=0;
        for(int i=0;i<n;i++)
        {
            if(res[s[i]]>begin)
                begin = res[s[i]];
            res[s[i]] = i;
            maxi = max(maxi,i-begin);
        }
        return maxi;
    }
};