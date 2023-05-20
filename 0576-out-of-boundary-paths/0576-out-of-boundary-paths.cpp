class Solution {
public:
    int dp[50][50][51];
    int help[5] = {0,1,0,-1,0};
    int mod = 1e9+7;
    int rec(int m, int n, int maxMoves, int r, int c)
    {
        if(r<0 or r>=m or c<0 or c>=n) return 1;
        if(maxMoves == 0) return 0;
        if(dp[r][c][maxMoves] != -1) return dp[r][c][maxMoves];
        int currOptions = 0;
        for(int k = 0;k<4;k++)
        {
            currOptions += rec(m,n, maxMoves-1, r+help[k], c+help[k+1]);
            currOptions = currOptions % (mod);
        }
        return dp[r][c][maxMoves] = currOptions;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return rec(m,n, maxMove, startRow, startColumn);
    }
};