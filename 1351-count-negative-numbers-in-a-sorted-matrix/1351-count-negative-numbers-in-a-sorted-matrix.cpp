class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        if(grid[m-1][n-1]>0) return 0;
        int row = m-1, col = 0;
        while(row>=0 and col<n)
        {
            if(grid[row][col]>=0)
            {
                col++;
                continue;
            }
            else {
                cnt += (n - col);
                row--;
            }
        }
        return cnt;
    }
};