class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<array<int,3>>pq;
        for(int i = 0;i<points.size();i++)
        {
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1], points[i][0], points[i][1]});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>>res;
        while(pq.size())
        {
            res.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return res;
    }
};