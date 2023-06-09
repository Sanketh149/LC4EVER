class Solution {
public:
    int dp[101][101];
    int rec(int r, int c, int m, int n)
    {
        if(r>m or c>n) return 0;
        if(r == m and c == n) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int down = rec(r+1,c,m,n);
        int right = rec(r,c+1,m,n);
        return dp[r][c] = down+right;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return rec(0,0,m-1,n-1);
    }
};