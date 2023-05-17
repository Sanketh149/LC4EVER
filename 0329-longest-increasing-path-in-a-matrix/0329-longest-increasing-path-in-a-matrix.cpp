class Solution {
public:
    int help[5] = {0,1,0,-1,0};
    bool isValid(int i, int j, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n;
    }
    int rec(int i, int j, vector<vector<int>>& matrix, int m, int n, vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(isValid(i,j,m,n)) {
            int curr = 1;
            for(int k = 0;k<4;k++)
            {
                int nr = i+help[k], nc = j+help[k+1];
                if(isValid(nr,nc,m,n) and matrix[i][j] < matrix[nr][nc])
                    curr = max(curr, 1+rec(nr, nc, matrix, m, n, dp));
            }
            return dp[i][j] = curr;
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxi = 1;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                maxi = max(maxi, rec(i, j, matrix, m, n, dp));
            }
        }
        return maxi;
    }
};