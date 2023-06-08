class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int numClasses = classes.size();
        double avgPassRatio = 0;
        priority_queue<pair<double,int>>pq;
        for(int i = 0;i<numClasses;i++)
        {
            int val1 = classes[i][0], val2 = classes[i][1];
            double diff = (double)(val1+1)/(val2+1) - (double)(val1)/(val2);
            pq.push({diff, i});
        }
        while(extraStudents--)
        {
            auto [diff, i] = pq.top();
            pq.pop();
            classes[i][0] += 1;
            classes[i][1] += 1;
            int val1 = classes[i][0];
            int val2 = classes[i][1];
            double newdiff = (double)(val1+1)/(val2+1) - (double)(val1)/(val2);
            pq.push({newdiff,i});
        }
        while(pq.size())
        {
            auto i = pq.top().second;
            avgPassRatio += (double)(classes[i][0])/(classes[i][1]);
            pq.pop();
        }
        avgPassRatio/=numClasses;
        return avgPassRatio;
    }
};