class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int rcnt = 0, bcnt = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(word[i] >= word[i+1]) rcnt++;
            else bcnt++;
        }
        return (rcnt+1)*2 - bcnt;
    }
};