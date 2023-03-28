class Solution {
public:
    int indexCheck(vector<int> &days, int idx, int duration)
    {
        int t = days[idx]+duration - 1;
        for(int i = idx+1;i<days.size();i++)
        {
            if(days[i] > t) return i;
        }
        return days.size();
    }
    int rec(vector<int> &days, vector<int> &costs, vector<int> &tickets, int idx, vector<int> &dp)
    {
        if(idx >= days.size()) return 0;
        int mini = 1e9;
        if(dp[idx] != -1) return dp[idx];
        for(int i = 0;i<3;i++)
        {
            int cost = costs[i], duration = tickets[i];
            int nextIdx = indexCheck(days, idx, duration);
            mini = min(mini, rec(days, costs, tickets, nextIdx, dp)+cost);
        }
        return dp[idx] = mini;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>tickets = {1,7,30};
        vector<int>dp(days.size(), -1);
        return rec(days, costs, tickets, 0, dp);
    }
};