class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        unsigned int a = labs(dividend), b = labs(divisor);
        unsigned int ans = 0;
        while(a >= b)
        {
            int q = 0;
            while(a > (b<<(q+1))) q++;
            ans += (1<<q);
            a -= (b<<q);
        }
        bool negSign = ((dividend ^ divisor) < 0); //to see if either of them are negative
        if(ans == (1<<31) and !negSign)   // if ans cannot be stored in signed int
            return INT_MAX;
        return negSign?-ans:ans;
    }
};