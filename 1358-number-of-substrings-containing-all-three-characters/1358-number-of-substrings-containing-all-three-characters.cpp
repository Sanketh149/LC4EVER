class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int aIndex = -1, bIndex = -1, cIndex = -1;
        int subStrings = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i] == 'a')
                aIndex = i;
            else if(s[i] == 'b')
                bIndex = i;
            else if(s[i] == 'c')
                cIndex = i;
            if(i >= 2) //because atleast a b c to be present i >= 2
                subStrings += min({aIndex, bIndex, cIndex})+1;
        }
        return subStrings;
    }
};