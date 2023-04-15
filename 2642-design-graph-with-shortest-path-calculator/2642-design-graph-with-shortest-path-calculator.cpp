class Graph {
public:
    int v;
    vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        v = n;
        adj.resize(v);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
    }
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, node1});
        vector<int>dist(v, 1e9);
        dist[node1] = 0;
        while(pq.size())
        {
            int node = pq.top().second, wt = pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjNode = it.first, edgewt = it.second;
                if(dist[adjNode] > wt+edgewt) {
                    dist[adjNode] = wt+edgewt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[node2] == 1e9?-1:dist[node2];
        // return 0;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */