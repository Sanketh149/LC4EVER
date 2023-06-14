class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int subStrings = 0;
        map<char,int>mp;
        int l = 0, r = 0;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp.size() >= 3)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
                subStrings += (n - r);
            }
            r++;
        }
        return subStrings;
    }
};