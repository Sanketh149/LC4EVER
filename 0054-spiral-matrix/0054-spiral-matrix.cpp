class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rs = 0, re = m-1, cs = 0, ce = n-1;
        vector<int>res;
        while(rs <= re and cs <= ce)
        {
            for(int i = cs;i<=ce;i++) res.push_back(matrix[rs][i]);
            rs++;
            for(int i = rs;i<=re;i++) res.push_back(matrix[i][ce]);
            ce--;
            for(int i = ce;i>=cs and rs<=re;i--) res.push_back(matrix[re][i]);
            re--;
            for(int i = re;i>=rs and cs<=ce;i--) res.push_back(matrix[i][cs]);
            cs++;
        }
        return res;
    }
};