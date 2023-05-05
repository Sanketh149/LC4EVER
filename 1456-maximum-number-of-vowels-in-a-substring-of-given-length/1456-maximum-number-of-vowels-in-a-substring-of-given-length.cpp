class Solution {
public:
    bool isVowel(char s)
    {
        return s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int maxi = -1e9;
        int curr = 0;
        for(int i = 0;i<k;i++)
            if(isVowel(s[i])) curr++;
        maxi = max(maxi, curr);
        for(int i = k;i<n;i++)
        {
            if(isVowel(s[i - k]))
            {
                if(!isVowel(s[i])) {
                    curr--;
                    maxi = max(maxi, curr);
                }
            }
            else{
                if(isVowel(s[i]))
                {
                    curr++;
                    maxi = max(maxi, curr);
                }
            }
        }
        return maxi;
    }
};