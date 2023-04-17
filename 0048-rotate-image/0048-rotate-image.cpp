class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        for(int i = 0;i<n-1;i++) //Transpose code
        {
            for(int j = i+1;j<n;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto &it:matrix) //use & for changing in-place in the original matrix
            reverse(it.begin(), it.end());
    }
};