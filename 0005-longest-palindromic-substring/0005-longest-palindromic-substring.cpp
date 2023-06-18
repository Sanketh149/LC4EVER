class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n = s.size(), beg = -1, maxlen = -1e9;
        string temp = s;
        reverse(temp.begin(), temp.end());
        if(temp == s) return s;
        for(int i = 0;i<n;i++)
        {
            int l = i,r = i;
            while(l>=0 and r<n and s[l] == s[r])
            {
                if(maxlen < (r-l+1))
                {
                    maxlen = r-l+1;
                    beg = l;
                }
                l--;
                r++;
            }
            
            l = i, r = i+1;
            while(l>=0 and r<n and s[l] == s[r])
            {
                if(maxlen < (r-l+1))
                {
                    maxlen = r-l+1;
                    beg = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(beg, maxlen);
    }
};