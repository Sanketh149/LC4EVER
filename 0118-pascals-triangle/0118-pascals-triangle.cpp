class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int row = 1;row<=numRows;row++)
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
            res.push_back(tempList);
        }
        return res;
    }
};