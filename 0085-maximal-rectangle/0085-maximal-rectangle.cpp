class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftMin(n, 0), rightMin(n, n-1);
        stack<int>s;
        for(int i = 0;i<n;i++)
        {
            while(s.size() and heights[s.top()] >= heights[i]) s.pop();
            if(s.size()) leftMin[i] = s.top()+1;
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = n-1;i>=0;i--)
        {
            while(s.size() and heights[s.top()] >= heights[i]) s.pop();
            if(s.size()) rightMin[i] = s.top() - 1;
            s.push(i);
        }
        int maxi = 0;
        for(int i = 0;i<n;i++)
            maxi = max(maxi, (rightMin[i] - leftMin[i]+1)*heights[i]);
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>currHist(n, 0);
        int maxi = 0;
        for(int i = 0;i<m;i++)
        {
            auto currRow = matrix[i];
            for(int j = 0;j<n;j++)
            {
                if(currRow[j] == '1')
                    currHist[j] += 1;
                else currHist[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(currHist));
        }
        return maxi;
    }
};