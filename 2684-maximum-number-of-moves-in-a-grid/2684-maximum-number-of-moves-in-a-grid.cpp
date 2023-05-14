class Solution {
public:
    bool isValid(int r, int c, int m, int n)
    {
        if(r<0 or c<0 or r>=m or c>=n) return false;
        return true;
    }
    void dfs(int curr, int col, int row, vector<int> &res, int m, int n, vector<vector<int>> &grid, int &cnt, vector<vector<int>> &dp)
    {
        if(!isValid(row, col, m, n)) return;
        if(dp[row][col] != 0) 
            return;
        if(isValid(row-1, col+1, m, n) and grid[row-1][col+1] > grid[row][col])
        {
            cnt++;
            dfs(curr, col+1, row-1, res, m, n, grid, cnt, dp);
            cnt--;
        }
        if(isValid(row, col+1, m,n) and grid[row][col+1] > grid[row][col])
        {
            cnt++;
            dfs(curr, col+1, row, res, m, n, grid, cnt, dp);
            cnt--;
        }
        if(isValid(row+1, col+1, m, n) and grid[row+1][col+1] > grid[row][col])
        {
            cnt++;
            dfs(curr, col+1, row+1, res, m, n, grid, cnt, dp);
            cnt--;
        }
        res[curr] = max(res[curr], cnt);
        dp[row][col]  = max(res[curr], dp[row][col]);
    }
    int maxMoves(vector<vector<int>>& grid) {
        int i = 0, j = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int>res(m, 0);
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(j = 0;j<m;j++)
        {
            int cnt = 0;
            dfs(0, 0, j, res, m, n, grid,cnt, dp);
        }
        int maxi = 0;
        for(int i = 0;i<m;i++)
            maxi = max(maxi, dp[i][0]);
        return maxi;
    }
};