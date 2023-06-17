class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorr = 0;
        for(auto it:s)
            xorr ^= it;
        for(auto it:t)
            xorr ^= it;
        return xorr;
    }
};