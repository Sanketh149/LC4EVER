class Solution {
public:
    int help[5] = {0,1,0,-1,0};
    void dfs(int r, int c, vector<vector<int>> &grid, int n)
    {
        if(r<0 or c<0 or r>=n or c>=n or grid[r][c] == 0 or grid[r][c] == 2) return;
        grid[r][c] = 2;
        q.push({r,c});
        for(int k = 0;k<4;k++)
        {
            int nr = r+help[k], nc = c+help[k+1];
            dfs(nr, nc, grid, n);
        }
    }
    queue<pair<int,int>>q;
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = false;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(!flag and grid[i][j] == 1)
                {
                    dfs(i, j, grid, n);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        int cntr = 0;
        while(q.size())
        {
            int siz = q.size();
            while(siz--)
            {
                auto [r,c] = q.front();
                q.pop();
                for(int k = 0;k<4;k++)
                {
                    int nr = r+help[k], nc = c+help[k+1];
                    if(nr<0 or nc<0 or nr>=n or nc>=n) continue;
                    if(grid[nr][nc] == 1) return cntr;
                    else if(grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            cntr++;
        }
        return cntr;
    }
};