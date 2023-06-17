class Solution {
public:
    char findTheDifference(string s, string t) {
        char xorr = ' ';
        for(auto it:s)
            xorr ^= it;
        for(auto it:t)
            xorr ^= it;
        return xorr^' ';
    }
};