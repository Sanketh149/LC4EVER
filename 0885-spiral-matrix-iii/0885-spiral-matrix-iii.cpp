class Solution {
public:
    bool isValid(int m, int n, int i, int j)
    {
        if(i>=0 and i<m and j>=0 and j<n) return true;
        return false;
    }
    vector<vector<int>> spiralMatrixIII(int m, int n, int rStart, int cStart) {
        vector<vector<int>>mat;
        int cnt = 1;
        int movement = 1;
        int i = rStart, j = cStart;
        bool rd = true;
        while(cnt <= m*n)
        {
            int curr = 0;
            if(rd)
            {
                while(curr < movement)
                {
                    if(isValid(m, n, i, j))
                    {
                        mat.push_back({i, j});
                        cnt++;
                    }
                    j++;
                    curr++;
                }
                curr = 0;
                while(curr < movement)
                {
                    if(isValid(m, n, i, j))
                    {
                        mat.push_back({i, j});
                        cnt++;
                    }
                    i++;
                    curr++;
                }
                rd = false;
                movement++;
            }
            else
            {
                while(curr < movement)
                {
                    if(isValid(m, n, i, j))
                    {
                        mat.push_back({i, j});
                        cnt++;
                    }
                    j--;
                    curr++;
                }
                curr = 0;
                while(curr < movement)
                {
                    if(isValid(m, n, i, j))
                    {
                        mat.push_back({i, j});
                        cnt++;
                    }
                    i--;
                    curr++;
                }
                rd = true;
                movement++;
            }
        }
        return mat;
    }
};