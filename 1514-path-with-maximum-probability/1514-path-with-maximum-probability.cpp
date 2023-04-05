class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        vector<double>dist(n, 0);
        queue<int>q;
        q.push(start);
        dist[start] = 1;
        while(q.size())
        {
            auto node = q.front();
            q.pop();
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                double adjProb = it.second;
                if(adjProb*dist[node] > dist[adjNode])
                {
                    dist[adjNode] = adjProb * dist[node];
                    q.push(adjNode);
                }
            }
        }
        return dist[end];
    }
};