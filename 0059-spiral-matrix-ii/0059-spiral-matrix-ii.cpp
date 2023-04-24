class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n, vector<int>(n, 0));
        int rs = 0, re = n-1, cs = 0, ce = n-1;
        int cnt = 1;
        while(rs <= re and cs <= ce)
        {
            for(int i = cs;i<=ce;i++) mat[rs][i] = cnt++;
            rs++;
            for(int i = rs;i<=re;i++) mat[i][ce] = cnt++;
            ce--;
            for(int i = ce;i>=cs and rs<=re;i--) mat[re][i] = cnt++;
            re--;
            for(int i = re;i>=rs and cs<=ce;i--) mat[i][cs] = cnt++;
            cs++;
        }
        return mat;
    }
};