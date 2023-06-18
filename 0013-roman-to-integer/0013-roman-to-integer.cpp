class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp = {{'I', 1},{'V', 5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n = s.size();
        int ans = 0;
        for(int i = n-1;i>=0;i--)
        {
            ans += mp[s[i]];
            if(i>0 and mp[s[i]] > mp[s[i-1]])
            {
                ans -= mp[s[i-1]];
                i--;
            }
        }
        return ans;
    }
};