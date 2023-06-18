class Solution {
public:
    int dp[501][501];
    int rec(int i, vector<int> &cost, vector<int> &time, int remWalls)
    {
        if(remWalls <= 0) return 0;
        if(i >= cost.size()) return 1e9;
        if(dp[i][remWalls] != -1) return dp[i][remWalls];
        int notpick = rec(i+1, cost, time, remWalls);
        int pick = cost[i]+rec(i+1, cost, time, remWalls - time[i] - 1);
        return dp[i][remWalls] = min(pick, notpick);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return rec(0, cost, time, time.size());
    }
};