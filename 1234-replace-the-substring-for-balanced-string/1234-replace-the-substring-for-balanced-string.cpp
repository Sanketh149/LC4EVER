class Solution {
public:
    int balancedString(string s) {
        map<char,int>mp;
        int l = 0, r = 0, mini = 1e9,n = s.size();
        for(auto it:s)
            mp[it]++;
        int k = n/4;
        while(r<n)
        {
            mp[s[r]]--;
            while(l<n and mp['Q']<=k and mp['W']<=k and mp['E']<=k and mp['R']<=k)
            {
                mini = min(mini, r - l + 1);
                mp[s[l]]++;
                l++;
            }
            r++;
        }
        return mini;
    }
};