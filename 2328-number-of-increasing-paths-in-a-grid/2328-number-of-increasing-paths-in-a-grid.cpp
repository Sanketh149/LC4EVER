class Solution {
public:
    int dp[1001][1001];
    int help[5] = {0,1,0,-1,0};
    int mod = 1e9+7;
    int rec(int i, int j, int m, int n, vector<vector<int>> &grid, int prev)
    {
        if(i<0 or j<0 or i >= m or j >= n or grid[i][j] <= prev) return 0;
        int count = 1;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = 0;k<4;k++)
        {
            int nr = i+help[k], nc = j+help[k+1];
            count += rec(nr, nc, m, n, grid, grid[i][j]);
        }
        return dp[i][j] = (count)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        long long int ans = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(dp[i][j] == -1)
                {
                    ans += rec(i, j, m, n, grid, -1)%mod;
                }
                else ans += dp[i][j]%mod;
            }
        }
        return ans%mod;
    }
};