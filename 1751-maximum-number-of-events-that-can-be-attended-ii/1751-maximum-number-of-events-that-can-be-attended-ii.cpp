class Solution {
public:
    int rec(vector<vector<int>>& events,int n, int i, int k, vector<vector<int>> &dp)
    {
        if(i >= n or k == 0) return 0;
        int notTake = rec(events, n, i+1, k, dp);
        if(dp[i][k] != -1)
            return dp[i][k];
        int next = upper_bound(events.begin()+i+1, events.end(), events[i][1], [](const int t, const vector<int> &arr){
            return arr[0] > t;
        }) - events.begin();
        int take = events[i][2]+rec(events, n, next, k-1, dp);
        return dp[i][k] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return rec(events,n,0,k, dp);
    }
};