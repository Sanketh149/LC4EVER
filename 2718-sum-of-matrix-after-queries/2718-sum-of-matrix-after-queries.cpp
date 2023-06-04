class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long res = 0;
        vector<bool>row(n, 0),col(n, 0);
        int remrow = n, remcol = n;
        for(int i = queries.size()-1;i>=0;i--)
        {
            if(queries[i][0] == 0 and !row[queries[i][1]])
            {
                res += remcol*queries[i][2];
                row[queries[i][1]] = true;
                remrow--;
            }
            if(queries[i][0] == 1 and !col[queries[i][1]])
            {
                res += remrow*queries[i][2];
                remcol--;
                col[queries[i][1]] = true;
            }
        }
        return res;
    }
};