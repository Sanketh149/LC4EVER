class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>nonOverlaps;
        nonOverlaps.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++)
        {
            auto &recent = nonOverlaps.back();
            if(recent[1] >= intervals[i][0])
                recent[1] = max(recent[1], intervals[i][1]);
            else 
                nonOverlaps.push_back(intervals[i]);
        }
        return nonOverlaps;
    }
};