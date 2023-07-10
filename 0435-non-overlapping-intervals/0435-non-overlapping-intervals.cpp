class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        int ans = 0, currEnd = intervals[0][1], n = intervals.size();
        for(int i = 1;i<n;i++)
        {
            if(currEnd > intervals[i][0]) ans++;
            else currEnd = intervals[i][1];
        }
        return ans;
    }
};