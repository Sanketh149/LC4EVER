class Solution {
public:
    int queens[10];
    bool check(int row, int col)
    {
        for(int i = 0;i<row;i++)
        {
            if(queens[i] == col or abs(i - row) == abs(col - queens[i]))
                return false;
        }
        return true;
    }
    void rec(vector<vector<string>>&ans, int n, int level, vector<string> &curr)
    {
        if(level == n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i = 0;i<n;i++)
        {
            if(check(level, i))
            {
                queens[level] = i;
                curr[level][i] = 'Q';
                rec(ans, n, level+1, curr);
                queens[level] = -1;
                curr[level][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(queens, -1, sizeof(queens));
        vector<vector<string>>ans;
        string res = "";
        for(int i=0;i<n;i++)
            res += '.';
        vector<string>chessBoard(n,res);
        rec(ans, n, 0, chessBoard);
        return ans;
    }
};