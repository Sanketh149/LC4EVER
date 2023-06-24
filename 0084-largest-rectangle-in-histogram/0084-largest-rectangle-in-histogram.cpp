class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftMin(n, 0), rightMin(n, 0);
        stack<int>s;
        for(int i = 0;i<n;i++)
        {
            while(s.size() and heights[s.top()] >= heights[i])
                s.pop();
            if(s.size() == 0) leftMin[i] = 0;
            else leftMin[i] = s.top()+1;
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = n-1;i>=0;i--)
        {
            while(s.size() and heights[s.top()] >=  heights[i])
                s.pop();
            if(s.size() == 0) rightMin[i] = n-1;
            else rightMin[i] = s.top()-1;
            s.push(i);
        }
        int res = 0;
        for(int i = 0;i<n;i++)
        {
            res = max(res, (rightMin[i] - leftMin[i]+1)*heights[i]);
        }
        return res;
    }
};