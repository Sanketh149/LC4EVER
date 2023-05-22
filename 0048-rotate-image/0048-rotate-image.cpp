class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        for(int i = 0;i<n;i++) //Transpose code
        {
            for(int j = 0;j<i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto &it:matrix) //use & for changing in-place in the original matrix
            reverse(it.begin(), it.end());
    }
};