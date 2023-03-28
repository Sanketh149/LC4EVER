class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        vector<long long>dist(n, LLONG_MAX);
        vector<long long>steps(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        steps[0] = 1;
        int mod = 1e9+7;
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto i:roads)
        {
            adj[i[1]].push_back({i[0], i[2]});
            adj[i[0]].push_back({i[1], i[2]});
        }
        while(pq.size())
        {
            auto [wt, node] = pq.top();
            pq.pop();
            for(auto adjNode:adj[node])
            {
                if(dist[adjNode.first] > wt + adjNode.second)
                {
                    dist[adjNode.first] = wt + adjNode.second;
                    steps[adjNode.first] = steps[node];
                    pq.push({dist[adjNode.first], adjNode.first});
                }
                else if(dist[adjNode.first] == wt + adjNode.second)
                {
                    steps[adjNode.first] = (steps[adjNode.first]+steps[node])%mod;
                }
            }
        }
        return steps[n-1]%mod;
    }
};