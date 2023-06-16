class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mp(128, 0);
        for(char it:t) mp[it]++;
        int l = 0, r = 0, m = s.size(), n = t.size(), mini = 1e9, beg = 0;
        while(r<m)
        {
            if(mp[s[r]]-- > 0) n--;
            while(n == 0)
            {
                if(mini > (r-l+1))
                {
                    mini = r-l+1;
                    beg = l;
                }
                if(mp[s[l]]++ == 0) n++;
                l++;
            }
            r++;
        }
        return mini == 1e9?"":s.substr(beg, mini);
    }
};