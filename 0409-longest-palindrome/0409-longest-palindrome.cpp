class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>v(128, 0);
        for(auto it:s) v[it]++;
        int odd = 0;
        for(auto it:v) odd += it&1;
        if(odd>1) return s.size()-odd+1;
        return s.size();
    }
};