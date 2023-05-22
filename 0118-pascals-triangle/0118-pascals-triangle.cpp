class Solution {
public:
    vector<int>generateRow(int row)
    {
        vector<int>tempList;
        int ans = 1;
        tempList.push_back(1);
        for(int col = 1;col<row;col++)
        {
            ans = ans*(row - col);
            ans = ans/col;
            tempList.push_back(ans);
        }
        return tempList;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int row = 1;row<=numRows;row++)
            res.push_back(generateRow(row));
        return res;
    }
};