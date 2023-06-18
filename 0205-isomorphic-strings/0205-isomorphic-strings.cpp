class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>v1(256, -1), v2(256, -1);
        for(int i = 0;i<s.size();i++)
        {
            if(v1[s[i]] == -1 and v2[t[i]] == -1)
            {
                v1[s[i]] = i+1;
                v2[t[i]] = i+1;
            }
            else if(v1[s[i]] != v2[t[i]]) return false;
        }
        return true;
    }
};