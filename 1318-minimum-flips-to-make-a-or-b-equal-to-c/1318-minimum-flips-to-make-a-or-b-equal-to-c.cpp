class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a!=0 or b!=0 or c!=0)
        {
            if(c&1)
            {
                if((a&1) == 0 and (b&1) == 0) res += 1;
            }
            else {
                res += (a&1)+(b&1);
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return res;
    }
};