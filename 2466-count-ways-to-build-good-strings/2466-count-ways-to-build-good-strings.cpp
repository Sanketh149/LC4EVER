class Solution {
public:
    int modulo = 1e9+7;
    int rec(int len, int low, int high, int zero, int one, vector<int> &dp)
    {
        if(len > high) return 0;
        int count = 0;
        if(dp[len] != -1) return dp[len];
        if(len >= low and len <= high) count++;
        count = count+rec(len+zero, low, high, zero, one, dp);
        count = count+rec(len+one, low, high, zero, one, dp);
        return dp[len] = (count)%modulo;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, -1);
        return rec(0, low, high, zero, one, dp);
    }
};