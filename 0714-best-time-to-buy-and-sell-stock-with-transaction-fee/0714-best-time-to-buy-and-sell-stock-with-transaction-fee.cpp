class Solution {
public:
    int rec(vector<int> &prices, int fee, int i, int n, bool toSell, int dp[][2])
    {
        if(i>=n) return 0;
        if(dp[i][toSell] != -1) return dp[i][toSell];
        if(toSell)
        {
            int sell = prices[i]+rec(prices, fee, i+1, n, false, dp);
            int notsell = rec(prices, fee, i+1,n, true, dp);
            return dp[i][toSell] = max(sell, notsell);
        }
        else
        {
            int buy = -prices[i]-fee+rec(prices, fee, i+1,n, true, dp);
            int notbuy = rec(prices, fee, i+1,  n, false, dp);
            return dp[i][toSell] = max(buy, notbuy);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n+1][2];
        memset(dp, -1, sizeof(dp));
        return rec(prices, fee, 0 , n, false, dp);
    }
};