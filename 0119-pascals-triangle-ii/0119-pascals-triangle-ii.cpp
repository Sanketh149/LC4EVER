class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>currRow;
        long long ans = 1;
        currRow.push_back(1);
        for(int col = 1;col<=rowIndex;col++)
        {
            ans = ans * (rowIndex+1-col);
            ans = ans/col;
            currRow.push_back(ans);
        }
        return currRow;
    }
};