class Solution {
public:
    int dp[101][101];
    int rec(vector<vector<int>>& matrix, int r, int c, int n)
    {
        if(c<0 or c>=n) return 1e8;
        if(r == n-1) return matrix[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        int left = rec(matrix, r+1, c-1, n);
        int right = rec(matrix, r+1, c+1,  n);
        int down = rec(matrix, r+1, c, n);
        return dp[r][c] = min({left, right, down}) + matrix[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int mini = 1e9, n = matrix.size();
        for(int i = 0;i<n;i++)
            mini = min(mini, rec(matrix, 0, i, n));
        return mini;
    }
};