class Solution {
public:
    int queens[10];
    bool check(int row, int col)
    {
        for(int i = 0;i<row;i++)
        {
            if(queens[i] == col or abs(queens[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }
    int rec(int level, int n)
    {
        if(level == n)
            return 1;
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(check(level, i))
            {
                queens[level] = i;
                ans += rec(level+1, n);
                queens[level] = -1;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        memset(queens, -1, sizeof(queens));
        return rec(0, n);
    }
};