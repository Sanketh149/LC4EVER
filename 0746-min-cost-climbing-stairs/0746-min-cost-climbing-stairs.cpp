class Solution {
public:
    int dp[1001];
    int rec(vector<int> &cost, int idx)
    {
        if(idx>=cost.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int takeOne = rec(cost, idx+1);
        int takeTwo = rec(cost, idx+2);
        return dp[idx] = (min(takeOne, takeTwo)+cost[idx]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(rec(cost, 0), rec(cost, 1));
    }
};