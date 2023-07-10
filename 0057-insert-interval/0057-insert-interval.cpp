class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        int n = intervals.size();
        for(int i = 0;i<n;i++)
        {
            if(res.size() and res.back()[1] >= intervals[i][0])
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        return mergeIntervals(intervals);
    }
};