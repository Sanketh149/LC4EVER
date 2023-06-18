class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>counts(26,0);
        if(size(s)!=size(t)) return false;
        for(int i=0;i<size(s);i++)
        {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }
        for(auto i:counts)
            if(i!=0) return false;
        return true;
    }
};