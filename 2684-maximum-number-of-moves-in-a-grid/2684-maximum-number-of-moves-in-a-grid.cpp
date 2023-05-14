class Solution {
public:
    bool isValid(int r, int c, int m, int n)
    {
        if(r<0 or c<0 or r>=m or c>=n) return false;
        return true;
    }
    int dfs(int curr, int col, int row, vector<int> &res, int m, int n, vector<vector<int>> &grid, int &cnt, vector<vector<int>> &dp)
    {
        if(!isValid(row, col, m, n)) return 0;
        if(dp[row][col] != -1) 
            return dp[row][col];
        int a = 0,b = 0,c = 0;
        if(isValid(row-1, col+1, m, n) and grid[row-1][col+1] > grid[row][col])
        {
            a = dfs(curr, col+1, row-1, res, m, n, grid, cnt, dp);
        }
        if(isValid(row, col+1, m,n) and grid[row][col+1] > grid[row][col])
        {
            b = dfs(curr, col+1, row, res, m, n, grid, cnt, dp);
        }
        if(isValid(row+1, col+1, m, n) and grid[row+1][col+1] > grid[row][col])
        {
            c = dfs(curr, col+1, row+1, res, m, n, grid, cnt, dp);
        }
        return dp[row][col] = 1+max({a,b,c});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int i = 0, j = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int>res(m, 0);
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int maxi = 0;
        for(j = 0;j<m;j++)
        {
            int cnt = 0;
            maxi = max(maxi, dfs(0, 0, j, res, m, n, grid,cnt, dp));
        }
        return maxi-1;
    }
};