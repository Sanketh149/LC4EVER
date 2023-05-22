class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>nonOverLap;
        nonOverLap.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++)
        {
            vector<int> &recent = nonOverLap.back();
            if(intervals[i][0] <= recent[1]) //need to merge
                recent[1] = max(recent[1], intervals[i][1]);
            else
                nonOverLap.emplace_back(intervals[i]);
        }
        return nonOverLap;
    }
};