class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, int low[], int tin[], vector<vector<int>> &bridges, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it == parent) continue;
            if(!vis[it])
            {
                dfs(it, node, low, tin, bridges, adj, vis);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int low[n];
        int tin[n];
        vector<vector<int>>bridges;
        vector<int>adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n, 0);
        dfs(0, -1, low, tin, bridges, adj, vis);
        return bridges;
    }
};