class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = 0, maxi = 0;
        for(int i = 0;i<mat.size();i++)
        {
            int cnt = 0;
            for(int j = 0;j<mat[0].size();j++)
            {
                if(mat[i][j] == 1)
                    cnt++;
            }
            if(cnt > maxi)
            {
                maxi = cnt;
                row = i;
            }
        }
        return {row, maxi};
    }
};