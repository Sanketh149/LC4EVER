class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>v; //row,col
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    v.push_back({i,j});
                }
            }
        }
        for(auto it:v)
        {
            int r = it.first, c = it.second;
            for(int i = 0;i<n;i++)
                matrix[r][i] = 0;
            for(int i = 0;i<m;i++)
                matrix[i][c] = 0;
        }
    }
};