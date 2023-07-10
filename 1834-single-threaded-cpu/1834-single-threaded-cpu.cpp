class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>sequence; //Non - Premptive
        int n = tasks.size();
        vector<array<int,3>>schedules;
        for(int i=0;i<n;i++)
            schedules.push_back({tasks[i][0], tasks[i][1], i});
        sort(schedules.begin(), schedules.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        long long i = 0, currTime = 0;
        while(pq.size() or i<schedules.size())
        {
            if(pq.empty() and schedules[i][0] > currTime)
             // When the heap is empty, try updating currTime to next task's arrival time.
                currTime = schedules[i][0];
            // Push all the tasks whose enqueueTime <= currtTime into the heap.
            while(i < schedules.size() and currTime>=schedules[i][0])
            {
                pq.push({schedules[i][1], schedules[i][2]});
                i++;
            }
            // Complete this task and increment currTime.
            auto [currJobBT, index] = pq.top();
            pq.pop();
            sequence.push_back(index);
            currTime += currJobBT;
        }
        return sequence;
    }
};