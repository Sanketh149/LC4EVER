class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int i = 0, res = 0;
        int maxlimit = INT_MAX;
        while(i<n and s[i] == ' ') i++; //white spaces skip
        bool isNeg = false;
        if(i<n)
        {
            if(s[i] == '-') 
            {
                isNeg = true;
                i++;
            }
            else if(s[i] == '+') 
            {
                isNeg = false;
                i++;
            }
        }
        while(i<n and isdigit(s[i]))
        {
            int digit = s[i] - '0';
            if(res > ((maxlimit - digit)/10))
                return isNeg?INT_MIN:maxlimit;
            res = res*10+digit;
            i++;
        }
        return isNeg?-res:res;
    }
};